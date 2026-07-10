#include <stdbool.h>
#include <stddef.h>
#include <stdarg.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern unsigned _brk;
extern unsigned _hlimit;

struct ReactorCore {
    float flux;
    float bias;
    float reserve;
};

struct Chamber {
    char name[16];
    union {
        struct {
            unsigned char glyph;
            unsigned char intensity;
        };
        unsigned packed;
    };
    struct ReactorCore core;
    long ledger;
};

struct Observatory {
    const char *title;
    struct Chamber chambers[4];
};

enum TransformMode {
    MODE_ECHO,
    MODE_TWIST,
    MODE_PULSE,
    MODE_COUNT
};

enum ManifestKind {
    MANIFEST_TEXT,
    MANIFEST_LONG,
    MANIFEST_FLOAT,
    MANIFEST_BOOL
};

struct ManifestItem {
    enum ManifestKind kind;
    const char *label;
    union {
        const char *as_text;
        long as_long;
        float as_float;
        _Bool as_flag;
    };
};

enum ExprKind {
    EXPR_LITERAL,
    EXPR_CHAMBER,
    EXPR_NEGATE,
    EXPR_ADD,
    EXPR_SUB,
    EXPR_MUL,
    EXPR_DIV,
    EXPR_IF,
    EXPR_KIND_COUNT
};

struct Expr {
    enum ExprKind kind;
    union {
        long literal;
        struct {
            const struct Chamber *chamber;
            int delta;
        } chamber_ref;
        const struct Expr *single;
        struct {
            const struct Expr *left;
            const struct Expr *right;
        } pair;
        struct {
            _Bool gate;
            const struct Expr *when_true;
            const struct Expr *when_false;
        } branch;
    };
};

typedef float (*core_rule_fn)(struct ReactorCore *core);
typedef char (*transform_fn)(const struct Chamber *chamber, int row, int col, int tick);
typedef long (*expr_eval_fn)(const struct Expr *expr, int depth);
typedef const struct Chamber *(*chamber_pick_fn)(const struct Observatory *observatory, int seed);
typedef const char *(*oracle_line_fn)(char *buffer, size_t size, const struct Chamber *chamber, int seed);

struct OracleDescriptor {
    char code[4];
    oracle_line_fn line;
};

struct GlyphPacket {
    unsigned glyph_low : 4;
    unsigned glyph_high : 4;
    signed drift : 5;
    unsigned vivid : 1;
    unsigned phase : 2;
};

typedef int (*packet_predicate_fn)(const struct Chamber *chamber, const struct GlyphPacket *packet);
typedef packet_predicate_fn (*packet_factory_fn)(unsigned salt);

#define CARDINAL_TABLE(ENTRY) \
    ENTRY(NORTH, 'N', 3) \
    ENTRY(EAST,  'E', 5) \
    ENTRY(SOUTH, 'S', 7) \
    ENTRY(WEST,  'W', 9)

enum Cardinal {
#define ENTRY(name, glyph, weight) CARD_##name,
    CARDINAL_TABLE(ENTRY)
#undef ENTRY
    CARD_COUNT
};

static const char cardinal_glyph[CARD_COUNT] = {
#define ENTRY(name, glyph, weight) [CARD_##name] = glyph,
    CARDINAL_TABLE(ENTRY)
#undef ENTRY
};

static const char *const cardinal_name[CARD_COUNT] = {
#define ENTRY(name, glyph, weight) [CARD_##name] = #name,
    CARDINAL_TABLE(ENTRY)
#undef ENTRY
};

static const unsigned char cardinal_weight[CARD_COUNT] = {
#define ENTRY(name, glyph, weight) [CARD_##name] = weight,
    CARDINAL_TABLE(ENTRY)
#undef ENTRY
};

struct Almanac {
    size_t count;
    long entries[CARD_COUNT];
};

static const char *const phase_names[MODE_COUNT + 2] = {
    [MODE_ECHO] = "echo",
    [MODE_TWIST] = "twist",
    [MODE_PULSE] = "pulse",
    [MODE_COUNT + 1] = "sentinel"
};

static jmp_buf expr_escape;
static const char *expr_fault;

static int wrap_cycle(int value, int limit);
static long chamber_signature(const struct Chamber *chamber);

static unsigned heap_free(void)
{
    if (_hlimit <= _brk)
        return 0;
    return _hlimit - _brk;
}

static inline int clamp_band(int value)
{
    return value < 0 ? 0 : (value > 15 ? 15 : value);
}

static void chronicle_event(const char *channel, const char *fmt, ...)
{
    va_list args;

    printf("  [%s] ", channel);
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
    printf("\n");
}

static long eval_expr(const struct Expr *expr, int depth);

static void bounded_copy(char *dst, size_t size, const char *src)
{
    size_t index = 0;

    if (size == 0)
        return;

    while (index + 1 < size && src[index] != '\0') {
        dst[index] = src[index];
        ++index;
    }
    dst[index] = '\0';
}

static void append_unsigned(char *dst, size_t size, unsigned value)
{
    char tmp[6];
    int pos = 0;
    size_t used = strlen(dst);

    if (used + 1 >= size)
        return;

    do {
        tmp[pos++] = (char) ('0' + (value % 10u));
        value = (unsigned) (value / 10u);
    } while (value != 0u && pos < (int) sizeof tmp);

    while (pos > 0 && used + 1 < size)
        dst[used++] = tmp[--pos];
    dst[used] = '\0';
}

static struct GlyphPacket make_packet(const struct Chamber *chamber, int drift, unsigned phase)
{
    struct GlyphPacket packet;

    packet.glyph_low = (unsigned) chamber->glyph & 0x0fu;
    packet.glyph_high = ((unsigned) chamber->glyph >> 4) & 0x0fu;
    packet.drift = drift;
    packet.vivid = chamber->intensity > 9 ? 1u : 0u;
    packet.phase = phase & 3u;
    return packet;
}

static unsigned packet_glyph(const struct GlyphPacket *packet)
{
    return (packet->glyph_high << 4) | packet->glyph_low;
}

static int packet_matches_vivid(const struct Chamber *chamber, const struct GlyphPacket *packet)
{
    return packet->vivid && chamber->intensity > 9;
}

static int packet_matches_phase(const struct Chamber *chamber, const struct GlyphPacket *packet)
{
    return (((unsigned) chamber_signature(chamber) + packet->phase) & 3u) == packet->phase;
}

static int packet_matches_drift(const struct Chamber *chamber, const struct GlyphPacket *packet)
{
    long drifted = chamber_signature(chamber) + (long) packet->drift;

    return (drifted % 5L) == (long) packet->phase;
}

static packet_predicate_fn packet_factory(unsigned salt)
{
    static packet_predicate_fn predicates[3] = {
        packet_matches_vivid,
        packet_matches_phase,
        packet_matches_drift
    };

    return predicates[salt % 3u];
}

static long expr_fail(const char *message)
{
    expr_fault = message;
    longjmp(expr_escape, 1);
    return 0;
}

static long eval_literal_expr(const struct Expr *expr, int depth)
{
    (void) depth;
    return expr->literal;
}

static long eval_chamber_expr(const struct Expr *expr, int depth)
{
    (void) depth;
    return chamber_signature(expr->chamber_ref.chamber) + (long) expr->chamber_ref.delta;
}

static long eval_negate_expr(const struct Expr *expr, int depth)
{
    return -eval_expr(expr->single, depth + 1);
}

static long eval_add_expr(const struct Expr *expr, int depth)
{
    return eval_expr(expr->pair.left, depth + 1) + eval_expr(expr->pair.right, depth + 1);
}

static long eval_sub_expr(const struct Expr *expr, int depth)
{
    return eval_expr(expr->pair.left, depth + 1) - eval_expr(expr->pair.right, depth + 1);
}

static long eval_mul_expr(const struct Expr *expr, int depth)
{
    return eval_expr(expr->pair.left, depth + 1) * eval_expr(expr->pair.right, depth + 1);
}

static long eval_div_expr(const struct Expr *expr, int depth)
{
    long numerator = eval_expr(expr->pair.left, depth + 1);
    long denominator = eval_expr(expr->pair.right, depth + 1);

    if (denominator == 0)
        return expr_fail("division-by-zero");
    return numerator / denominator;
}

static long eval_if_expr(const struct Expr *expr, int depth)
{
    return expr->branch.gate
        ? eval_expr(expr->branch.when_true, depth + 1)
        : eval_expr(expr->branch.when_false, depth + 1);
}

static long eval_expr(const struct Expr *expr, int depth)
{
    static const expr_eval_fn dispatch[EXPR_KIND_COUNT] = {
        eval_literal_expr,
        eval_chamber_expr,
        eval_negate_expr,
        eval_add_expr,
        eval_sub_expr,
        eval_mul_expr,
        eval_div_expr,
        eval_if_expr
    };

    if (expr == NULL)
        return expr_fail("null-expression");
    if (depth > 14)
        return expr_fail("depth-overflow");
    if (expr->kind < 0 || expr->kind >= EXPR_KIND_COUNT)
        return expr_fail("bad-tag");
    return dispatch[expr->kind](expr, depth);
}

static const struct Chamber *pick_forward(const struct Observatory *observatory, int seed)
{
    int index = wrap_cycle(seed, 4);
    return &observatory->chambers[index];
}

static const struct Chamber *pick_reverse(const struct Observatory *observatory, int seed)
{
    int index = 3 - wrap_cycle(seed, 4);
    return &observatory->chambers[index];
}

static const struct Chamber *pick_signature(const struct Observatory *observatory, int seed)
{
    int index;
    const struct Chamber *best = &observatory->chambers[0];
    long best_score = chamber_signature(best) - (long) seed;

    if (best_score < 0)
        best_score = -best_score;

    for (index = 1; index < 4; ++index) {
        long score = chamber_signature(&observatory->chambers[index]) - (long) seed;
        if (score < 0)
            score = -score;
        if (score < best_score) {
            best = &observatory->chambers[index];
            best_score = score;
        }
    }

    return best;
}

static unsigned char (*glyph_matrix(void))[4]
{
    static unsigned char matrix[3][4] = {
        { 'N', 'E', 'S', 'W' },
        { 'R', 'I', 'N', 'G' },
        { 'Z', '8', '0', '!' }
    };

    return matrix;
}

static const char *oracle_name(char *buffer, size_t size, const struct Chamber *chamber, int seed)
{
    (void) seed;
    bounded_copy(buffer, size, chamber->name);
    return buffer;
}

static const char *oracle_sig(char *buffer, size_t size, const struct Chamber *chamber, int seed)
{
    bounded_copy(buffer, size, "sig+");
    append_unsigned(buffer, size, (unsigned) (chamber_signature(chamber) + (long) seed));
    return buffer;
}

static const char *oracle_flux(char *buffer, size_t size, const struct Chamber *chamber, int seed)
{
    unsigned scaled = (unsigned) (chamber->core.flux * 10.0f) + (unsigned) seed;

    bounded_copy(buffer, size, "fluxx10=");
    append_unsigned(buffer, size, scaled);
    return buffer;
}

static int compare_oracle_code(const void *lhs, const void *rhs)
{
    const char *key = (const char *) lhs;
    const struct OracleDescriptor *entry = (const struct OracleDescriptor *) rhs;

    return strcmp(key, entry->code);
}

static void run_oracle_mirror(const struct Observatory *observatory)
{
    static const struct OracleDescriptor oracle_table[] = {
        { .code = "FLX", .line = oracle_flux },
        { .code = "NAM", .line = oracle_name },
        { .code = "SIG", .line = oracle_sig }
    };
    chamber_pick_fn pickers[3] = { pick_forward, pick_reverse, pick_signature };
    char buffer[24];
    unsigned char (*matrix)[4] = glyph_matrix();
    int index;

    printf("\nOracle mirror\n");

    for (index = 0; index < 3; ++index) {
        const struct Chamber *chamber = pickers[index](observatory, 2353 + index * 97);
        const char *code = index == 0 ? "NAM" : (index == 1 ? "SIG" : "FLX");
        const struct OracleDescriptor *entry =
            (const struct OracleDescriptor *) bsearch(code,
                                                      oracle_table,
                                                      sizeof oracle_table / sizeof oracle_table[0],
                                                      sizeof oracle_table[0],
                                                      compare_oracle_code);

        if (entry != NULL)
            chronicle_event("oracle", "%s %c%c%c%c -> %s",
                            entry->code,
                            matrix[index][0],
                            matrix[index][1],
                            matrix[index][2],
                            matrix[index][3],
                            entry->line(buffer, sizeof buffer, chamber, index + 5));
    }
}

static void run_packet_maze(const struct Observatory *observatory)
{
    struct GlyphPacket packets[4];
    struct GlyphPacket (*packet_rows)[4] = &packets;
    packet_factory_fn factory_ring[3] = { packet_factory, packet_factory, packet_factory };
    const struct GlyphPacket *cursor;
    const struct GlyphPacket *end;
    int index;

    printf("\nPacket maze\n");

    for (index = 0; index < 4; ++index) {
        int drift = index == 0 ? -3 : (index == 1 ? 2 : (index == 2 ? -1 : 4));
        (*packet_rows)[index] = make_packet(&observatory->chambers[index], drift, (unsigned) index);
    }

    cursor = &(*packet_rows)[0];
    end = cursor + 4;
    for (index = 0; cursor != end; ++cursor, ++index) {
        const struct Chamber *chamber = &observatory->chambers[index];
        packet_predicate_fn predicate = factory_ring[index % 3]((unsigned) index + packet_glyph(cursor));
        int accepted = predicate(chamber, cursor);

        chronicle_event("packet",
                        "%s glyph=%c phase=%u drift=%d vivid=%u accept=%s bytes=%u",
                        chamber->name,
                        (char) packet_glyph(cursor),
                        (unsigned) cursor->phase,
                        (int) cursor->drift,
                        (unsigned) cursor->vivid,
                        accepted ? "yes" : "no",
                        (unsigned) sizeof *cursor);
    }
}

#define almanac(...) chronicle_event("almanac", __VA_ARGS__)

struct Protothread {
    int resume;
    int cursor;
};

#define PT_BEGIN(pt)  switch ((pt)->resume) { case 0:
#define PT_YIELD(pt)  do { (pt)->resume = __LINE__; return 1; case __LINE__:; } while (0)
#define PT_FINISH(pt) } (pt)->resume = -1; return 0

static void duff_copy(char *dst, const char *src, unsigned count)
{
    unsigned chunks = (count + 3u) / 4u;

    switch (count % 4u) {
    case 0:
        do {
            *dst++ = *src++;
    case 3:
            *dst++ = *src++;
    case 2:
            *dst++ = *src++;
    case 1:
            *dst++ = *src++;
        } while (--chunks > 0u);
    }
    *dst = '\0';
}

static int walk_cardinals(struct Protothread *pt, int *emit)
{
    PT_BEGIN(pt);
    for (pt->cursor = 0; pt->cursor < CARD_COUNT; ++pt->cursor) {
        *emit = pt->cursor;
        PT_YIELD(pt);
    }
    PT_FINISH(pt);
}

static void run_chrono_almanac(const struct Observatory *observatory, _Bool stable)
{
    const char *title = observatory->title;
    struct Protothread pt = { 0, 0 };
    struct Almanac *ledger;
    char echoed[24];
    char trail[CARD_COUNT + 1];
    int emitted = 0;
    int step = 0;
    long total = 0;
    size_t index;

    printf("\nChrono almanac\n");
    almanac("mode=%s cardinals=%d", stable ? "stable" : "drift", (int) CARD_COUNT);

    while (walk_cardinals(&pt, &emitted)) {
        trail[step++] = cardinal_glyph[emitted];
        almanac("step %d %-5s glyph=%c weight=%u",
                step,
                cardinal_name[emitted],
                cardinal_glyph[emitted],
                (unsigned) cardinal_weight[emitted]);
    }
    trail[step] = '\0';
    almanac("trail=%s resume=%d", trail, pt.resume);

    duff_copy(echoed, title, (unsigned) strlen(title));
    almanac("echoed=%s len=%u", echoed, (unsigned) strlen(echoed));

    ledger = malloc(sizeof *ledger);
    if (ledger != NULL) {
        ledger->count = CARD_COUNT;
        for (index = 0; index < ledger->count; ++index) {
            ledger->entries[index] = (long) cardinal_glyph[index] * 100L
                                   + (long) cardinal_weight[index];
            total += ledger->entries[index];
        }
        almanac("entries=%u first=%ld last=%ld total=%ld",
                (unsigned) ledger->count,
                ledger->entries[0],
                ledger->entries[ledger->count - 1],
                total);
        free(ledger);
    }
}

static int wrap_cycle(int value, int limit)
{
    while (value < 0)
        value += limit;
    while (value >= limit)
        value -= limit;
    return value;
}

static float rebalance_core(struct ReactorCore *core)
{
    core->reserve += core->flux * 0.125f;
    core->flux = core->flux + core->reserve - core->bias;
    return core->flux;
}

static float fold_core(struct ReactorCore *core)
{
    core->bias = (core->flux - core->bias) * 0.5f;
    return core->bias;
}

static float saturate_core(struct ReactorCore *core)
{
    if (core->flux < core->bias)
        core->flux = core->bias;
    return core->flux;
}

static long chamber_signature(const struct Chamber *chamber)
{
    return chamber->ledger + (long) chamber->glyph * (long) (chamber->intensity + 1);
}

static int compare_chambers(const void *lhs, const void *rhs)
{
    const struct Chamber *left = (const struct Chamber *) lhs;
    const struct Chamber *right = (const struct Chamber *) rhs;
    long left_score = chamber_signature(left);
    long right_score = chamber_signature(right);

    if (left_score < right_score)
        return 1;
    if (left_score > right_score)
        return -1;
    return 0;
}

static char mode_echo(const struct Chamber *chamber, int row, int col, int tick)
{
    int marker = wrap_cycle((int) (chamber->ledger % 29L) + tick + row * 3, 29);
    int halo = wrap_cycle(marker + chamber->intensity, 29);

    if (col == marker)
        return (char) chamber->glyph;
    if (col == halo)
        return (char) ('0' + (clamp_band(chamber->intensity) % 10));
    return (col + tick + row) % 11 == 0 ? '.' : ' ';
}

static char mode_twist(const struct Chamber *chamber, int row, int col, int tick)
{
    int diagonal = wrap_cycle(tick * 2 + row * 5 + chamber->glyph, 29);
    int pulse = wrap_cycle(diagonal + (int) chamber->core.reserve + col, 7);

    if (col == diagonal)
        return (char) ('A' + (row % 26));
    return pulse == 0 ? (char) ('a' + (chamber->intensity % 26)) : '-';
}

static char mode_pulse(const struct Chamber *chamber, int row, int col, int tick)
{
    int wave = wrap_cycle(col + tick + row + (int) chamber->core.bias, 29);

    if (wave < chamber->intensity)
        return (char) ('!' + wrap_cycle(chamber->glyph + wave, 15));
    return (col % 3) == 0 ? '+' : ' ';
}

static int compare_signature_key(const void *lhs, const void *rhs)
{
    const long *key = (const long *) lhs;
    const struct Chamber *chamber = (const struct Chamber *) rhs;
    long score = chamber_signature(chamber);

    if (*key < score)
        return 1;
    if (*key > score)
        return -1;
    return 0;
}

static void render_constellation(const struct Observatory *observatory,
                                 enum TransformMode mode,
                                 int tick)
{
    int rows = (int) (sizeof observatory->chambers / sizeof observatory->chambers[0]);
    char canvas[rows][30];
    transform_fn transforms[MODE_COUNT] = { mode_echo, mode_twist, mode_pulse };
    int row;

    printf("\n[%s] mode=%s tick=%d\n", observatory->title, phase_names[mode], tick);

    for (row = 0; row < rows; ++row) {
        int col;
        for (col = 0; col < 29; ++col)
            canvas[row][col] = transforms[mode](&observatory->chambers[row], row, col, tick);
        canvas[row][29] = '\0';
        printf("%-10s |%s|\n", observatory->chambers[row].name, canvas[row]);
    }
}

static void print_machine_facts(void)
{
    unsigned probe = 0x1234u;
    unsigned char *bytes = (unsigned char *) &probe;

    printf("Machine facts\n");
    printf("  sizeof(int)=%u sizeof(long)=%u sizeof(void*)=%u sizeof(float)=%u\n",
           (unsigned) sizeof(int),
           (unsigned) sizeof(long),
           (unsigned) sizeof(void *),
           (unsigned) sizeof(float));
    printf("  chamber bytes=%u reserve offset=%u\n",
           (unsigned) sizeof(struct Chamber),
           (unsigned) offsetof(struct Chamber, core.reserve));
    printf("  endian probe bytes=%x %x\n", (unsigned) bytes[0], (unsigned) bytes[1]);
    printf("  heap head=%x heap ceiling=%x free=%u\n", _brk, _hlimit, heap_free());
}

static void run_core_rules(struct Observatory *observatory)
{
    core_rule_fn rules[3] = { rebalance_core, fold_core, saturate_core };
    int chamber_index;

    printf("\nCore rule cascade\n");

    for (chamber_index = 0; chamber_index < 4; ++chamber_index) {
        int rule_index;
        struct Chamber *chamber = &observatory->chambers[chamber_index];

        for (rule_index = 0; rule_index < 3; ++rule_index)
            rules[rule_index](&chamber->core);

        chamber->ledger += (long) (chamber->core.flux * 100.0f) - (long) (chamber->core.bias * 10.0f);

        printf("  %-10s flux=%6.2f bias=%6.2f reserve=%6.2f ledger=%ld vivid=%s\n",
               chamber->name,
               chamber->core.flux,
               chamber->core.bias,
               chamber->core.reserve,
               chamber->ledger,
               chamber->intensity > 9 ? "yes" : "no");
    }
}

static void print_rankings(struct Observatory *observatory)
{
    int index;

    qsort(observatory->chambers,
          sizeof observatory->chambers / sizeof observatory->chambers[0],
          sizeof observatory->chambers[0],
          compare_chambers);

    printf("\nRanked chambers\n");
    for (index = 0; index < 4; ++index) {
        struct Chamber *chamber = &observatory->chambers[index];
        printf("  %d. %-10s sig=%ld packed=%x glyph=%c intensity=%u\n",
               index + 1,
               chamber->name,
               chamber_signature(chamber),
               chamber->packed,
               chamber->glyph,
               (unsigned) chamber->intensity);
    }
}

static void print_manifest(const struct Observatory *observatory, _Bool stable)
{
    struct ManifestItem manifest[] = {
        { .kind = MANIFEST_TEXT, .label = "title", .as_text = observatory->title },
        { .kind = MANIFEST_LONG, .label = "lead-signature", .as_long = chamber_signature(&observatory->chambers[0]) },
        { .kind = MANIFEST_FLOAT, .label = "lead-flux", .as_float = observatory->chambers[0].core.flux },
        { .kind = MANIFEST_BOOL, .label = "stable", .as_flag = stable }
    };
    size_t index;
    size_t count = sizeof manifest / sizeof manifest[0];

    printf("\nManifest stream\n");
    for (index = 0; index < count; ++index) {
        switch (manifest[index].kind) {
        case MANIFEST_TEXT:
            chronicle_event("variant", "%s=%s", manifest[index].label, manifest[index].as_text);
            break;
        case MANIFEST_LONG:
            chronicle_event("variant", "%s=%ld", manifest[index].label, manifest[index].as_long);
            break;
        case MANIFEST_FLOAT:
            printf("  [variant] %s=%0.2f\n", manifest[index].label, manifest[index].as_float);
            break;
        default:
            chronicle_event("variant", "%s=%s", manifest[index].label, manifest[index].as_flag ? "true" : "false");
            break;
        }
    }
}

static void print_flux_lattice(const struct Observatory *observatory, int columns)
{
    enum { LATTICE_MAX = 12 };
    int row_count = (int) (sizeof observatory->chambers / sizeof observatory->chambers[0]);
    unsigned short lattice[row_count][LATTICE_MAX];
    unsigned short (*rows)[LATTICE_MAX] = lattice;
    int row;

    printf("\nFlux lattice\n");

    for (row = 0; row < row_count; ++row) {
        int col;
        unsigned short checksum = 0;

        for (col = 0; col < columns; ++col) {
            unsigned short value = (unsigned short) ((unsigned short) observatory->chambers[row].glyph
                                    + (unsigned short) (row * 7)
                                    + (unsigned short) (col * 3)
                                    + (unsigned short) observatory->chambers[row].intensity);
            rows[row][col] = value;
            checksum = (unsigned short) (checksum + value);
        }

        chronicle_event("lattice",
                        "%-10s width=%d head=%u tail=%u checksum=%u",
                        observatory->chambers[row].name,
                        columns,
                        (unsigned) rows[row][0],
                        (unsigned) rows[row][columns - 1],
                        (unsigned) checksum);
    }
}

static void print_signature_lookup(const struct Observatory *observatory)
{
    long target = chamber_signature(&observatory->chambers[1]);
    struct Chamber *found = (struct Chamber *) bsearch(&target,
                                                       observatory->chambers,
                                                       sizeof observatory->chambers / sizeof observatory->chambers[0],
                                                       sizeof observatory->chambers[0],
                                                       compare_signature_key);

    printf("\nSignature lookup\n");
    if (found != NULL)
        chronicle_event("search", "target=%ld hit=%s glyph=%c", target, found->name, found->glyph);
    else
        chronicle_event("search", "target=%ld miss", target);
}

static void print_pointer_geometry(const struct Observatory *observatory)
{
    const struct Chamber *first = &observatory->chambers[0];
    const struct Chamber *last = &observatory->chambers[3];
    ptrdiff_t chamber_gap = last - first;
    size_t title_len = strlen(observatory->title);
    signed char drifts[4] = { -3, 1, 4, -2 };
    unsigned char mask = (unsigned char) (observatory->chambers[0].glyph ^ observatory->chambers[3].glyph);

    printf("\nPointer geometry\n");
    chronicle_event("layout", "title bytes=%u chamber-gap=%ld mask=%u",
                    (unsigned) title_len,
                    (long) chamber_gap,
                    (unsigned) mask);
    chronicle_event("layout", "drifts=%d,%d,%d,%d",
                    (int) drifts[0],
                    (int) drifts[1],
                    (int) drifts[2],
                    (int) drifts[3]);
}

static void run_expression_ritual(const struct Observatory *observatory, _Bool stable)
{
    const struct Expr *ritual = &(struct Expr) {
        .kind = EXPR_IF,
        .branch = {
            .gate = stable,
            .when_true = &(struct Expr) {
                .kind = EXPR_SUB,
                .pair = {
                    .left = &(struct Expr) {
                        .kind = EXPR_ADD,
                        .pair = {
                            .left = &(struct Expr) {
                                .kind = EXPR_CHAMBER,
                                .chamber_ref = {
                                    .chamber = &observatory->chambers[0],
                                    .delta = 17
                                }
                            },
                            .right = &(struct Expr) {
                                .kind = EXPR_NEGATE,
                                .single = &(struct Expr) {
                                    .kind = EXPR_LITERAL,
                                    .literal = -33L
                                }
                            }
                        }
                    },
                    .right = &(struct Expr) {
                        .kind = EXPR_DIV,
                        .pair = {
                            .left = &(struct Expr) {
                                .kind = EXPR_MUL,
                                .pair = {
                                    .left = &(struct Expr) {
                                        .kind = EXPR_CHAMBER,
                                        .chamber_ref = {
                                            .chamber = &observatory->chambers[2],
                                            .delta = -5
                                        }
                                    },
                                    .right = &(struct Expr) {
                                        .kind = EXPR_LITERAL,
                                        .literal = 2L
                                    }
                                }
                            },
                            .right = &(struct Expr) {
                                .kind = EXPR_LITERAL,
                                .literal = 3L
                            }
                        }
                    }
                }
            },
            .when_false = &(struct Expr) {
                .kind = EXPR_LITERAL,
                .literal = 0L
            }
        }
    };
    const struct Expr *faulty = &(struct Expr) {
        .kind = EXPR_DIV,
        .pair = {
            .left = &(struct Expr) {
                .kind = EXPR_LITERAL,
                .literal = 7L
            },
            .right = &(struct Expr) {
                .kind = EXPR_SUB,
                .pair = {
                    .left = &(struct Expr) {
                        .kind = EXPR_LITERAL,
                        .literal = 4L
                    },
                    .right = &(struct Expr) {
                        .kind = EXPR_LITERAL,
                        .literal = 4L
                    }
                }
            }
        }
    };

    printf("\nExpression ritual\n");

    if (setjmp(expr_escape) == 0) {
        long value = eval_expr(ritual, 0);
        chronicle_event("expr", "stable-tree=%ld", value);
    } else {
        chronicle_event("expr", "stable-tree fault=%s", expr_fault);
    }

    if (setjmp(expr_escape) == 0) {
        long value = eval_expr(faulty, 0);
        chronicle_event("expr", "fault-tree=%ld", value);
    } else {
        chronicle_event("expr", "fault-tree fault=%s", expr_fault);
    }
}

int main(void)
{
    struct Observatory observatory = {
        .title = "CLOCKWORK ORRERY",
        .chambers = {
            [0] = {
                .name = "AURORA",
                .glyph = 'A',
                .intensity = 12,
                .core = { .flux = 3.50f, .bias = 1.00f, .reserve = 0.25f },
                .ledger = 1200L
            },
            [1] = {
                .name = "BRASS",
                .glyph = 'B',
                .intensity = 7,
                .core = { .flux = 5.25f, .bias = 1.50f, .reserve = 0.50f },
                .ledger = 980L
            },
            [2] = {
                .name = "CINDER",
                .glyph = 'C',
                .intensity = 14,
                .core = { .flux = 4.75f, .bias = 0.75f, .reserve = 0.40f },
                .ledger = 1410L
            },
            [3] = {
                .name = "DELTA",
                .glyph = 'D',
                .intensity = 9,
                .core = { .flux = 6.00f, .bias = 2.25f, .reserve = 0.80f },
                .ledger = 1115L
            }
        }
    };
    float calibration = rebalance_core(&(struct ReactorCore) {
        .flux = 9.00f,
        .bias = 2.50f,
        .reserve = 0.75f
    });
    bool stable = calibration > 7.0f;
    int lattice_width = (int) (strlen(observatory.title) % 7u) + 6;
    int mode;

    printf("Clockwork Observatory\n");
    printf("  calibration spark=%6.2f stable=%s\n", calibration, stable ? "yes" : "no");
    print_machine_facts();
    run_core_rules(&observatory);
    print_rankings(&observatory);
    print_manifest(&observatory, stable);
    print_signature_lookup(&observatory);
    print_flux_lattice(&observatory, lattice_width);
    print_pointer_geometry(&observatory);
    run_expression_ritual(&observatory, stable);
    run_oracle_mirror(&observatory);
    run_packet_maze(&observatory);
    run_chrono_almanac(&observatory, stable);

    for (mode = 0; mode < MODE_COUNT; ++mode)
        render_constellation(&observatory, (enum TransformMode) mode, mode + 2);

    printf("\nRuntime check\n");
    printf("  first chamber addr=%x title addr=%x\n",
           (unsigned) &observatory.chambers[0],
           (unsigned) observatory.title);
    printf("  octal 010=%d hex 0x10=%d\n", 010, 0x10);
    printf("  copied title length=%u\n", (unsigned) strlen(observatory.title));

    return 0;
}