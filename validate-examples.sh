#!/usr/bin/env sh
# Validate the standard-tagged CP/M Z80 C test suite.
#
# Files are named by the language standard they target:
#   c89NN.c  strict C89 (also valid as C99 and C11)
#   c99NN.c  C99 features (also valid as C11)
#   c11NN.c  C11 features (anonymous struct/union, ...)
#
# clang mode compiles and runs each file under every standard it supports.
# dcc mode builds each file with dccmake and runs the .COM under ntvcm.
#
# Filenames are 8.3-clean and contain NO underscore: the CP/M M80/L80 tools
# reject an underscore in the object/output name and hang at the linker prompt.
set -u

mode=${1:-all}
clang_bin=${CLANG:-clang}
ntvcm_bin=${NTVCM:-${NTVCM_DIR:-/Users/dave/GitHub/ntvcm}/ntvcm}
failures=0

# Run a command with a hard kill-timeout (seconds) so a stuck CP/M tool
# can never hang the whole run. Kills the process group on timeout.
run_to() {
    _t=$1
    shift
    perl -e '
        my $t = shift @ARGV;
        my $pid = fork();
        if ($pid == 0) { setpgrp(0,0); exec(@ARGV); exit 127; }
        $SIG{ALRM} = sub { kill("KILL", -$pid); };
        alarm($t);
        waitpid($pid, 0);
        exit($? >> 8 ? ($? >> 8) : ($? & 127 ? 124 : 0));
    ' "$_t" "$@"
}

# Standards a given source is expected to compile and run under.
standards_for() {
    case "$1" in
        c89*) echo "c89 c99 c11" ;;
        c99*) echo "c99 c11" ;;
        c11*) echo "c11" ;;
        *)    echo "c89 c99 c11" ;;
    esac
}

run_clang_one() {
    src=$1
    base=$(basename "$src" .c)

    for standard in $(standards_for "$base"); do
        out="/tmp/testc-$standard-$base"
        if "$clang_bin" "-std=$standard" -Wall -Wextra -pedantic -fsigned-char \
                "$src" -o "$out" && "$out" >/dev/null; then
            printf 'clang %s ok %s\n' "$standard" "$base"
        else
            printf 'clang %s FAIL %s\n' "$standard" "$base"
            failures=$((failures + 1))
        fi
    done
}

run_dcc_one() {
    src=$1
    base=$(basename "$src" .c)
    upper=$(printf '%s' "$base" | tr 'abcdefghijklmnopqrstuvwxyz' 'ABCDEFGHIJKLMNOPQRSTUVWXYZ')
    build_dir="b$base"

    rm -rf "$build_dir"
    if run_to 90 dccmake "dcc-input=$src" "dcc-output=$upper" \
            "dcc-build-dir=$build_dir" </dev/null >"/tmp/testc-dcc-$base.log" 2>&1 \
            && run_to 30 "$ntvcm_bin" "$build_dir/$upper.COM" </dev/null >/dev/null 2>&1; then
        printf 'dcc ok %s\n' "$base"
        rm -rf "$build_dir"
    else
        printf 'dcc FAIL %s (see /tmp/testc-dcc-%s.log)\n' "$base" "$base"
        failures=$((failures + 1))
    fi
}

run_clang() {
    for src in examples/c*.c; do
        run_clang_one "$src"
    done
}

run_dcc() {
    for src in examples/c*.c; do
        run_dcc_one "$src"
    done
}

case "$mode" in
    clang)
        run_clang
        ;;
    dcc)
        run_dcc
        ;;
    all)
        run_clang
        run_dcc
        ;;
    *)
        printf 'usage: %s [clang|dcc|all]\n' "$0" >&2
        exit 2
        ;;
esac

if [ "$failures" -ne 0 ]; then
    printf 'validation failures=%d\n' "$failures" >&2
    exit 1
fi

printf 'validation ok\n'
