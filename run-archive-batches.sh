#!/usr/bin/env sh
# Build and run archived C tests through dcc and ntvcm.
set -u

script_dir=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
cd "$script_dir"

ntvcm_bin=${NTVCM:-${NTVCM_DIR:-/Users/dave/GitHub/ntvcm}/ntvcm}
logs_dir=${ARCHIVE_LOGS_DIR:-/tmp/dcc-archive-logs}
build_root=${ARCHIVE_BUILD_DIR:-.archive-build}
failures=0
total=0

usage() {
    printf 'usage: %s [all|batch-number|archive/batch-directory]\n' "$0" >&2
    exit 2
}

# Kill the whole process group if a CP/M build or program gets stuck.
run_to() {
    _timeout=$1
    shift
    perl -e '
        my $timeout = shift @ARGV;
        my $pid = fork();
        if ($pid == 0) { setpgrp(0, 0); exec(@ARGV); exit 127; }
        $SIG{ALRM} = sub { kill("KILL", -$pid); };
        alarm($timeout);
        waitpid($pid, 0);
        exit($? >> 8 ? ($? >> 8) : ($? & 127 ? 124 : 0));
    ' "$_timeout" "$@"
}

run_one() {
    batch_dir=$1
    src=$2
    batch=$(basename "$batch_dir")
    base=$(basename "$src" .c)
    upper=$(printf '%s' "$base" | tr 'abcdefghijklmnopqrstuvwxyz' 'ABCDEFGHIJKLMNOPQRSTUVWXYZ')
    build_dir="$build_root/$batch/$base"
    log="$logs_dir/$batch/$base.log"

    total=$((total + 1))
    rm -rf "$build_dir"
    mkdir -p "$build_dir" "$(dirname "$log")"

    if run_to 90 dccmake "dcc-input=$src" "dcc-output=$upper" \
            "dcc-build-dir=$build_dir" </dev/null >"$log" 2>&1 \
            && run_to 30 "$ntvcm_bin" "$build_dir/$upper.COM" \
                </dev/null >>"$log" 2>&1; then
        printf 'PASS %s/%s\n' "$batch" "$base"
        rm -rf "$build_dir"
    else
        printf 'FAIL %s/%s (see %s)\n' "$batch" "$base" "$log"
        failures=$((failures + 1))
    fi
}

run_batch() {
    batch_dir=$1
    found=0

    if [ ! -d "$batch_dir" ]; then
        printf 'batch directory not found: %s\n' "$batch_dir" >&2
        failures=$((failures + 1))
        return
    fi

    for src in "$batch_dir"/c*.c; do
        [ -f "$src" ] || continue
        found=1
        run_one "$batch_dir" "$src"
    done

    if [ "$found" -eq 0 ]; then
        printf 'no C programs found in %s\n' "$batch_dir" >&2
        failures=$((failures + 1))
    fi
}

selection=${1:-all}
case "$selection" in
    all)
        found_batch=0
        for batch_dir in archive/batch*; do
            [ -d "$batch_dir" ] || continue
            found_batch=1
            run_batch "$batch_dir"
        done
        if [ "$found_batch" -eq 0 ]; then
            printf 'no archive batch directories found\n' >&2
            exit 1
        fi
        ;;
    *[!0-9]*)
        [ "$#" -eq 1 ] || usage
        run_batch "${selection%/}"
        ;;
    *)
        [ "$#" -eq 1 ] || usage
        run_batch "archive/batch$selection"
        ;;
esac

passed=$((total - failures))
printf '\narchive dcc results: %d passed, %d failed, %d total\n' \
    "$passed" "$failures" "$total"

if [ "$failures" -ne 0 ]; then
    exit 1
fi

rm -rf "$build_root"