---
name: cpm-c-test-suite
description: 'Generate a suite of 50 standalone C unit tests (17 C89, 17 C99, 16 C11) for the dcc compiler targeting CP/M 2.2 / Z80, validated against Clang and run under ntvcm. Use when asked to create/refresh a batch of example programs or unit tests spanning C89/C99/C11 for dcc/CP/M/Z80, write "typical pro-level, best-practice, moderately complex" C tests, or add standard-tagged tests to the examples/ folder. Encodes the naming rule (NO underscore in filenames — M80/L80 hang), the stdint/portability conventions, per-standard feature targeting, the clang-oracle + dcc/ntvcm validation loop, and how to file DCC_ISSUE reports for dcc defects.'
argument-hint: 'e.g. "generate a fresh set of 50 c89/c99/c11 dcc tests" or "add 10 more C11 tests"'
---

# CP/M Z80 C test-suite generator

Produce a maintainable suite of standalone C programs that exercise C89, C99 and
C11 features, compile clean under both Clang (the behavioural oracle) and `dcc`
(CP/M 2.2 / Z80), and run correctly under `ntvcm`. This skill builds on the
[dcc-cpm-z80](../dcc-cpm-z80/SKILL.md) compiler-contract skill — read that for
the language/library deviations; this skill is the *authoring + validation
workflow* for a whole test batch.

## When to use

- "Generate / write / refresh a set of 50 unit tests for C89 C99 C11" (dcc/CP/M).
- "Add N more tests" to the `examples/` suite.
- Any request for "typical pro-level, best-practice, moderately complex" C tests
  that must build for dcc on the Z80.

## The deliverable

- **Location: all test sources go in the `examples/` folder** (repo root
  `examples/`), alongside `examples/README.md` and any `examples/DCC_ISSUE_*.md`
  reports. Never scatter tests elsewhere.
- **50 files** by default: **17 `c89NN.c`, 17 `c99NN.c`, 16 `c11NN.c`** in
  `examples/` (adjust counts on request; keep the three-way split).
- Each file is a complete program with `int main(void)` that prints **one
  deterministic result line** beginning with its own base name, e.g.
  `printf("c8901 sorted=%d ...\n", ...)`. Deterministic output is what makes it a
  test (compare dcc output to the Clang oracle).
- Moderately complex, idiomatic, maintainable code a professional would write —
  a *different* algorithm/scenario per file, never a shared generator/boilerplate.

## Hard rules (learned the hard way)

1. **Filenames contain NO underscore.** Use `c8901.c`, `c9901.c`, `c1101.c` —
   never `c89_01.c`. The CP/M `M80`/`L80` toolchain rejects an underscore in the
   object/output name and **hangs at the linker `*` prompt** printing
   `?Command error`. Base name ≤ 8 chars, extension ≤ 3, no extra dots.
2. **`int` is 16-bit.** Any value that can exceed ±32767 must use `long` /
   `int32_t`. Keep loop counters and small values in `int`.
3. **C89 files stay strict C89**: declarations at the top of each block,
   `/* */` comments only, no `//`, no `_Bool`, no VLAs, no designated
   initializers, no mixed declarations. Use `int`/`long` (no `<stdint.h>`).
4. **C99 files target C99 features**: `//` comments, `for`-init scope, mixed
   declarations, designated initializers, compound literals, `<stdbool.h>`,
   VLAs, `restrict`, and `<stdint.h>` fixed-width types.
5. **C11 files target C11**: anonymous `struct`/`union` members (the headline
   C11 feature dcc supports) plus the full C99 set. **Do not** use `_Generic`
   or `_Static_assert` (dcc does not support them — permanent, not bugs).
6. **stdint printf casting (C99/C11).** `int32_t`/`uint32_t` are `long`/
   `unsigned long` on dcc but `int`/`unsigned` on the host, so **always cast in
   `printf`**: `%ld`+`(long)`, `%lu`/`%lX`+`(unsigned long)`, `%d`+`(int)`,
   `%u`+`(unsigned)`. This keeps Clang `-Wformat` clean *and* dcc correct.
7. **No `double`, no `long long`.** `float` is the only floating type; prefer
   scaled integers / fixed point and print fractions as scaled `long`s.
8. **Library subset.** Use `sprintf` (there is **no `snprintf`**). No
   `<time.h>`/`<signal.h>`/`<locale.h>`. No GNU range designators (`[0 ... 3]`).
9. **`va_arg` uses base types.** In variadic functions read `long` (not
   `int32_t`) and pass `long` literals — fixed-width types are unsafe with
   `va_arg` because argument promotions are defined on the base types.
10. **Byte/bit-field overlay unions assume little-endian** (true for both Z80
    and the host); add a comment noting it.

Before using any construct dcc has historically mishandled, check
[references/dcc-pitfalls.md](./references/dcc-pitfalls.md) and prefer the listed
dcc-safe idiom.

## Procedure

1. **Plan distinct scenarios.** List ~50 different algorithms/domains split
   across the standards (see the idea bank below). Avoid repeating scenarios
   from any existing suite in the repo.
2. **Write in small batches** (5–6 files), then validate that batch with Clang
   before continuing:
   ```sh
   clang -std=c89 -Wall -Wextra -pedantic -fsigned-char examples/c8901.c -o /tmp/t && /tmp/t
   ```
   Use `-std=c99`/`-std=c11` for those prefixes. Fix warnings and confirm the
   output line is correct/deterministic.
3. **Regenerate `examples/README.md`** describing the split, contents, design
   constraints, and validation commands.
4. **Validate the whole suite** by executing the repo's runner
   [`validate-examples.sh`](../../../validate-examples.sh) from the repo root
   (this is the canonical way to build/run the tests — don't hand-roll a loop):
   ```sh
   ./validate-examples.sh clang   # each file under every std it supports
   ./validate-examples.sh dcc     # dccmake build + ntvcm run, with kill-timeout
   ./validate-examples.sh all
   ```
   It discovers `examples/c*.c`, maps prefix → standards (`c89*`→c89/c99/c11,
   `c99*`→c99/c11, `c11*`→c11), runs the full `dcc → dccpeep → dccrtlstrip →
   M80 → L80` pipeline under `ntvcm`, and wraps every build/run in a hard
   kill-timeout (`run_to`) so a stuck CP/M tool can never hang the run. It relies
   on `dccmake.txt` in the repo root for the include dir, runtime, and
   `-ffloatio`/`-flongio`. Success prints `validation ok`; a dcc failure names
   the log at `/tmp/testc-dcc-<name>.log`.
5. **Fast front-end checks** (no link, no hang risk):
   ```sh
   dcc -I "$DCC_DIR" examples/c9902.c -o /tmp/x.mac
   ```
   A front-end error aborts cleanly; a *successful* compile with a bad name is
   what hangs L80. There is no `timeout` on macOS — use a perl watchdog that
   kills the process group (see the validate script's `run_to`).

## Handling a dcc failure

Every test is valid, Clang-accepted C, so a dcc failure is a **dcc defect**.

1. **Reduce to a minimal repro** with `dcc -I "$DCC_DIR"`; bisect variants to
   find the exact trigger (many dcc bugs are context/TU-sensitive — a minimal
   repro may pass while the full file fails, or vice-versa).
2. **Keep the suite green**: rewrite the affected test to a dcc-safe idiom that
   is still idiomatic/maintainable (e.g. materialize a struct-return into a
   local; use `if`/`else` instead of a `long` ternary — see the pitfalls file).
3. **File a report** `examples/DCC_ISSUE_<NAME>.md` (one per distinct defect,
   even if it affects several examples) containing: a one-line summary + status,
   a **minimal reproduction** with the exact `DCC-E...` diagnostic, an
   **isolation matrix** (which variants pass/fail), the **workaround** used, the
   **Clang oracle** command + expected output, and the **expected dcc result**.
   List it in the README bug table. When dcc is later fixed, retest the
   idiomatic form, restore it, and flip the report title/status to a "fixed"
   regression record (keep the original failure documented for tracking).

## Scenario idea bank (pick distinct ones per batch)

- **C89 (strict):** sorts (merge/heap/shell/quick), search (rotated/binary),
  checksums (CRC-16, Adler-32, Fletcher-16, Luhn), parsing (RPN, shunting-yard,
  recursive descent, brackets), number theory (sieve, Goldbach, GCD/Stein,
  mod-pow, factorization), DP (LCS, edit distance, Kadane), data structures
  (ring buffer, BST, hash table, heap, arena), classics (Josephus, Hanoi,
  Game of Life, Bresenham, base conversion, Roman numerals, big-int factorial,
  rational arithmetic, matrix det/transpose/rotate, Fisher-Yates).
- **C99:** designated tables (status codes, calendar, units, dispatch),
  compound-literal value types (complex, fractions, vectors, 2x2 matrices),
  VLAs (sliding window, histogram, flood fill, point cloud), `restrict`
  kernels (dot/saxpy/matvec), `static inline` helpers, variadic reduce/join,
  `<stdbool.h>` predicates/sieve/Sudoku/N-queens, `sprintf` formatting
  (CSV, HH:MM:SS, hex dump), bit-field packing (RGB565, dates, chess moves).
- **C11:** tagged unions (value/variant/Result/event/token/message/JSON-ish),
  anonymous-struct grouping (points/rects/vectors), overlay unions
  (register hi/lo, RGBA/color, FourCC, IPv4/MAC, version, fixed-point,
  BCD, minifloat/bit-fields), object pools / free lists, small VMs.

## Definition of done

- 50 files, correct three-way split, no underscores, each printing a
  deterministic name-prefixed line.
- `./validate-examples.sh clang` and `./validate-examples.sh dcc` both print
  `validation ok` (or every remaining dcc failure has a `DCC_ISSUE_*.md` and a
  green workaround in the source).
- `examples/README.md` updated; any dcc defects reported.
