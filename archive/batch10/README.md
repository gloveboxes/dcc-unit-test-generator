# CP/M Z80 C conformance scenarios

This directory contains 100 standalone behavioral tests for dcc targeting CP/M 2.2 on the Z80:

- 34 strict C89 programs: `c8901.c` through `c8934.c`
- 33 C99 programs: `c9901.c` through `c9933.c`
- 33 C11 programs: `c1101.c` through `c1133.c`

Every program has bounded deterministic input, prints exactly one line beginning with its own basename, and returns zero only when all expected results hold. The 8.3-compatible filenames contain no underscores because underscored output names can hang the CP/M M80/L80 pipeline.

## Themes

The C89 programs model billing, weighted scheduling, telemetry reconstruction, escaped-field parsing, KMP matching, stable record partitioning, bounded deques and heaps, trie routing, polynomial differentiation, sparse transforms, calendar and duration arithmetic, raster geometry, polygon operations, Bloom filters, Hamming correction, protocol framing, display diagnostics, inventory and tax calculations, signal filtering, control hysteresis, dispatch systems, rate limiting, log compaction, and safe resource allocation.

The C99 programs deliberately exercise designated initializers, address-taken compound literals, `stdbool.h`, mixed declarations, `for`-initializers, fixed-width integers, bounded VLAs, `restrict` kernels, `static inline` helpers, base-type-safe variadic functions, `sprintf`, bit-fields, and data-driven tables. Scenarios include tariffs, command metadata, keypads, affine transforms, phasors, geofences, integral images, FIR filtering, dependency checks, packet validation, covariance, morphology, access control, schedules, route metrics, and fingerprints.

The C11 programs focus on anonymous structures and unions plus supported C99 features. They cover actuator calibration, viewports, ledgers, retry policies, route segments, envelopes, file metadata, routing records, diagnostics, timestamps, compact motor/tile/counter words, journals, options, leases, parser nodes, database columns, transactions, snapshots, acknowledgments, controllers, grid cells, metrics, backups, components, layout constraints, and protocol exchanges.

## Target constraints

- Strict C89 declaration and comment rules in every `c89*.c` source
- 16-bit-aware `int`, pointer, and storage assumptions
- Explicit `long`, `uint32_t`, or `int32_t` for values beyond 16-bit range
- Portable casts for fixed-width values passed to `printf`
- Small fixed arrays and VLAs suitable for the shared CP/M stack/heap space
- No `double`, `long long`, `_Generic`, `_Static_assert`, threads, atomics, or unsupported hosted APIs
- Little-endian assumptions documented beside word/byte overlay unions

## Validation

Run the host oracle and CP/M/Z80 target validation from the repository root:

```sh
./validate-examples.sh clang
./validate-examples.sh dcc
./validate-examples.sh all
```

The validator builds C89 files as C89, C99, and C11; C99 files as C99 and C11; and C11 files as C11, all with `-Wall -Wextra -pedantic -fsigned-char`, then executes each result. A successful run ends with `validation ok`.

This batch passed `./validate-examples.sh all`: every applicable Clang mode
passed, and all 100 programs built with dcc and returned success under ntvcm.
