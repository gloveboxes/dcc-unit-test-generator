# dcc pitfalls catalog — constructs to avoid or work around

Valid, Clang-accepted C constructs that current/recent `dcc` builds have
mishandled while generating this test suite. For each: the trigger, the failure,
and the **dcc-safe idiom** to use instead so a test stays green. Many are
context/TU-sensitive (a minimal repro may behave differently from the full
file). When one bites, reduce it, work around it, and file
`examples/DCC_ISSUE_<NAME>.md`.

Fast front-end check (no link, no L80 hang):
`dcc -I "$DCC_DIR" repro.c -o /tmp/x.mac`

## Permanent target/runtime exceptions (NOT bugs — never use)

- `double` / `long double`, `long long` / 64-bit integers.
- `_Generic`, `_Static_assert` (dcc will not add these).
- `snprintf`, `strtod`, `<time.h>`/`<signal.h>`/`<locale.h>`.
- GNU range designators `[0 ... 3]`.
- `%f` without the `-ffloatio` build flag; `%ld`/`%lu` without `-flongio`.

## Filenames

- **Underscore in a source/output name hangs M80/L80** at the `*` prompt with
  `?Command error`. Name files `c8901.c` etc. — no `_`.

## Known dcc defects seen while authoring (check status; may be fixed)

Each has a matching `examples/DCC_ISSUE_C*.md` with full detail.

| Trigger | Diagnostic / symptom | dcc-safe idiom |
| ------- | -------------------- | -------------- |
| `long`-typed ternary in an assignment: `long r = c ? x : y;` | `E1002 unsupported expression statement` | use `if`/`else` (int ternary is fine) |
| cast of a logical `\|\|`/`&&` to a narrow type stored to an array element in a loop: `a[i]=(unsigned char)(x\|\|y);` | `E1002 unsupported for statement` | `int t = x\|\|y; a[i]=(unsigned char)t;` |
| `return f(x);` where `f` returns a `struct` by value | `E1002 unsupported return expression` | `T t = f(x); return t;` |
| indirect call through a **`long`-signature** function pointer: `long(*fn)(long,long); fn(a,b)` | `E1002` (varies by context) | `int`-width fnptr signature, or selector enum + direct call |
| a `union` (esp. with bit-fields) passed **by value** to a function | runtime miscompile: wrong values + stack-overflow loop (large TU); `E1002` in a reduced TU | pass the union **by pointer** |
| pointer-typed `va_arg` as a declaration initializer: `const char *s = va_arg(ap,const char*);` | `E1002 unsupported initializer expression` | split: `const char *s; s = va_arg(...);` |
| member access on a struct-return rvalue: `f(...).m` | `E1002` | `T t = f(...); ...t.m` |

## Historically fixed (safe now, but verify)

These were rejected by older builds and later fixed; keep them clang-clean so
they double as regression coverage:

- `for` whose body is an `if` whose body is a `for` (compact nested statements).
- 1D VLA function parameters `void f(int n, int a[n])` (2D with a *variable
  inner* dimension `a[n][m]` is still unsupported — use a constant inner dim or
  a 1D VLA indexed manually).
- Designated initializer for a struct with bit-fields.
- Compound-literal value semantics (by-value arg, initializer, assignment).
- Bit-field read-modify-write (`bf += x`).

## Portability gotchas (correct code, wrong-looking output)

- `int32_t`/`uint32_t` are `long`/`unsigned long` on dcc but `int`/`unsigned`
  on the host → **cast in every `printf`** (`%ld`+`(long)`, etc.).
- `unsigned long` masked with `0xFFFFFFFF` is 64-bit on the host, 32-bit on dcc
  — fine, but don't rely on host wrap width; keep results within 32 bits.
- Byte/bit-field overlay unions are little-endian on both platforms; a value
  that depends on endianness will still match, but note the assumption.
- Transcendental `mathf` results differ ~5–6 digits; compare floats as scaled
  integers, never raw `%f` equality.

## Sizing

- Heap and stack share the TPA with no guard. Keep big buffers `static`/global;
  size deep recursion / large VLAs with `dcc-stack-bytes` (see `dccmake.txt`).
- Many-call-site `static inline` can bloat the `.COM`; prefer a real function
  if a no-peephole build runs out of memory.
