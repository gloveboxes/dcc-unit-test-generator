# CP/M Z80 C unit tests — batch 11

100 standalone behavioural tests for dcc targeting CP/M 2.2 on the Z80:

- **34 strict C89:** `c8901.c`–`c8934.c`
- **33 C99:** `c9901.c`–`c9933.c`
- **33 C11:** `c1101.c`–`c1133.c`

Every program prints exactly one basename-prefixed line, returns 0 only
when all assertions pass, uses bounded deterministic input, and is
8.3-filename-clean with no underscores.

## Themes

**C89** — Roman numeral conversion, big-integer addition, edit distance,
memoised Fibonacci, BST in-order traversal, Kadane max-subarray, rat-in-maze
backtracking, interval merging, FNV-1a hash, stable counting sort, Gray
code encode/decode, CRC-8, 16-bit bit reversal, modular exponentiation,
Luhn check, sliding-window maximum, RLE decoder, Zeckendorf representation,
circular queue, prefix sum of squares, Celsius/Fahrenheit conversion, graph
degree sum, bit-array sieve, Dutch-flag partition, disjoint interval check,
queue via two stacks, Tower of Hanoi counter, prime factorisation, Euclidean
distance table, palindrome number, run-length statistics, next permutation,
buy-low sell-high profit, staircase ways.

**C99** — designated-initializer direction table, `stdbool.h` power-of-two
counter, address-taken compound-literal Vec2 arithmetic, Sudoku row validator,
ones-complement checksum, flood-fill island count, `restrict` dot product,
RGB565 bit-field packing, all-unique VLA predicate, designated month-days table,
N-queens solver, Murmur-mix hash step, SAXPY kernel, VLA histogram, `stdbool.h`
parenthesis depth, designated `Register16` table, VLA predicate with function
pointer, `restrict` array reverse, topological-sort DAG check, RGBA pack/unpack,
strictly-sorted VLA check, 1-D convolution, packet XOR checksum, 2x2 matrix
determinant, connected-component count, hex-dump formatter, jump-game reachability,
generic insertion sort, trapping rain water, geographic bounding-box area,
nested-depth counter, Fletcher-16 checksum, regex `.*` matcher.

**C11** — anonymous-union 16-bit word byte overlay, tagged `Val` AND operation,
little-endian `Pixel` RGBA overlay, anonymous-union expression-tree evaluator,
anonymous-struct `SensorReading` temperature/humidity, AABB intersection via
named/positional alias, `DWord` byte-swap, `Event` tagged union (key/mouse/timer),
VM `Opcode` word/byte overlay, subnet-mask `NetAddr` overlay, Q8 fixed-point
addition, `Task` state-machine with progress, CAN frame word/byte overlay,
multi-kind `Config` tagged union, `TimerWord` bit-field overlay, `Atom` symbol/num
equality, `MotorCmd` bit-field word, `LogEntry` tagged level/code, `Point3D`
array/named alias, LRU cache, `Span` start/length overlap, flat-token evaluator,
IEEE 754 sign/exponent overlay, 2x2 matrix multiply, EEPROM slot version,
playing-card bit-field, PID controller with anonymous state, USB descriptor
raw/named overlay, ring buffer, unit quaternion magnitude, `Variant` tagged union,
`GPIO` port byte/word overlay, `Message` req/ack tagged frame.

## Target constraints

- Strict C89 declaration rules in every `c89*.c` — no `//`, no mixed decls
- 16-bit `int`/pointer; `long` or `int32_t`/`uint32_t` for wider values
- Portable `(long)`/`(unsigned long)` casts in `printf` for fixed-width types
- Bounded fixed arrays and outer-dimension-only VLAs (inner dims constant)
- No `double`, `long long`, `_Generic`, `_Static_assert`, threads, atomics
- Little-endian byte-overlay assumptions noted beside each affected union

## Validation

```sh
./validate-examples.sh clang   # strict Clang oracle: -Wall -Wextra -pedantic -fsigned-char
./validate-examples.sh dcc     # dcc + M80/L80 + ntvcm
./validate-examples.sh all
```

## Known dcc issue

`c8916.c` (sliding-window maximum) fails with the default `dcc-peep=true`
build due to a `dccpeep` code-generation defect — it produces `6,3,-1,3`
instead of `6,3,5,7`.  The program compiles and links cleanly; the error
is in the peephole optimiser.  Building with `dcc-peep=false` produces the
correct result.  The original valid source is preserved unchanged as a
regression test.  See `DCC_ISSUE_C8916_PEEP_SLIDING_MAX.md` for the full
write-up and isolation matrix.
