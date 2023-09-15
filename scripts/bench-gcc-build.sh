#!/bin/zsh
set -eu

# Exit on Ctrl+C
trap 'exit 1' INT

SAMPLE_SIZE=10
WARMUP_SIZE=3

# Create a temporary directory for the benchmark
TMP_DIR=$(mktemp -d)
echo "Benchmark results will be stored in $TMP_DIR"

# Run time benchmark
echo "Running warmup ($WARMUP_SIZE) for time"
for i in $(seq $WARMUP_SIZE); do
    make clean >/dev/null 2>&1
    perf stat -r 1 sh -c 'make -j8 >/dev/null 2>&1' 2>&1 | grep 'seconds time elapsed' | awk '{print $1}'
done >/dev/null
echo "Running samples ($SAMPLE_SIZE) for time"
for i in $(seq $SAMPLE_SIZE); do
    make clean >/dev/null 2>&1
    perf stat -r 1 sh -c 'make -j8 >/dev/null 2>&1' 2>&1 | grep 'seconds time elapsed' | awk '{print $1}'
done >"$TMP_DIR/time.txt"

# Run peak memory benchmark
echo "Running warmup ($WARMUP_SIZE) for peak memory"
for i in $(seq $WARMUP_SIZE); do
    make clean >/dev/null 2>&1
    /usr/bin/time -v sh -c 'make -j8 >/dev/null 2>&1' 2>&1 | grep 'Maximum resident set size' | awk '{print $6}'
done >/dev/null
echo "Running samples ($SAMPLE_SIZE) for peak memory"
for i in $(seq $SAMPLE_SIZE); do
    make clean >/dev/null 2>&1
    /usr/bin/time -v sh -c 'make -j8 >/dev/null 2>&1' 2>&1 | grep 'Maximum resident set size' | awk '{print $6}'
done >"$TMP_DIR/peak_memory.txt"
