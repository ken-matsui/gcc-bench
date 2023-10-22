#!/bin/zsh
set -eu

# Exit on Ctrl+C
trap "exit" INT

SAMPLE_SIZE=10
WARMUP_SIZE=3

# Make sure we have commands to use
check_cmd() {
    if ! command -v $1 &> /dev/null; then
        echo "command `$1` not found"
        exit 1
    fi
}
check_cmd perf
check_cmd /usr/bin/time
check_cmd ministat
check_cmd mktemp
check_cmd awk
check_cmd grep
check_cmd sed
check_cmd seq
check_cmd basename
check_cmd touch
check_cmd tee
check_cmd pushd
check_cmd popd
check_cmd dirname
check_cmd where
check_cmd date
check_cmd git
check_cmd cat
check_cmd xg++

# Make sure we have the right number of arguments
if [ $# -ne 1 ]; then
    echo 'Usage: ./bench.sh <benchmark-file>'
    echo 'Example: ./bench.sh is_object.cc'
    exit 1
fi

# Make sure the benchmark file exists
if [ ! -f "$1" ]; then
    echo "Benchmark file $1 does not exist"
    exit 1
fi
# Make sure the benchmark file is a C++ file (.cc)
if [ "${1: -3}" != ".cc" ]; then
    echo "Benchmark file $1 is not a C++ file"
    exit 1
fi
FILE=$1
FILENAME=$(basename "$FILE" .cc)

XGPP_DIR=$(dirname $(where xg++)) # i.e. .../gcc/objdir/gcc; assuming xg++ is under the GCC directory
GCC_BUILD_DIR="$XGPP_DIR/.."  # i.e. .../gcc/objdir
GCC_DIR="$GCC_BUILD_DIR/.."  # i.e. .../gcc

# Set include & link directories
INCLUDE_PATH1="$GCC_BUILD_DIR/x86_64-pc-linux-gnu/libstdc++-v3/include"
INCLUDE_PATH2="$GCC_BUILD_DIR/x86_64-pc-linux-gnu/libstdc++-v3/include/x86_64-pc-linux-gnu"
INCLUDE_PATH3="$GCC_DIR/gcc/ginclude"  # for stddef.h

# Set C++ version (C++23 by default)
CXX_VERSION="c++2b"

echo 'NOTE: Make sure to run `sudo sysctl -w kernel.perf_event_paranoid=1` before'
echo 'running this script. It should be okay to run once per computer boot.\n'

# Test runs before writing to file
echo "Test Run: perf stat xg++ -D_GLIBCXX_DO_NOT_USE_BUILTIN_TRAITS -c $FILE"
perf stat -r 1 xg++ -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -D_GLIBCXX_DO_NOT_USE_BUILTIN_TRAITS -c $FILE >!error.log 2>&1
echo "Test Run: perf stat xg++ -c $FILE"
perf stat -r 1 xg++ -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -c $FILE >!error.log 2>&1

echo "Test Run: /usr/bin/time -v xg++ -D_GLIBCXX_DO_NOT_USE_BUILTIN_TRAITS -c $FILE"
/usr/bin/time -v xg++ -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -D_GLIBCXX_DO_NOT_USE_BUILTIN_TRAITS -c $FILE >!error.log 2>&1
echo "Test Run: /usr/bin/time -v xg++ -c $FILE"
/usr/bin/time -v xg++ -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -c $FILE >!error.log 2>&1

echo "Test Run: xg++ -ftime-report -D_GLIBCXX_DO_NOT_USE_BUILTIN_TRAITS -c $FILE"
xg++ -ftime-report -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -D_GLIBCXX_DO_NOT_USE_BUILTIN_TRAITS -c $FILE >!error.log 2>&1
echo "Test Run: xg++ -ftime-report -c $FILE"
xg++ -ftime-report -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -c $FILE >!error.log 2>&1

echo '\n=== Running benchmark ==='


# Create a benchmark report file if it doesn't exist
REPORT_FILE="$FILENAME.md"
touch "$REPORT_FILE"
echo "## $(date)" >> "$REPORT_FILE"

echo '\n```console' >> "$REPORT_FILE"
echo '$ xg++ --version' >> "$REPORT_FILE"
xg++ --version >> "$REPORT_FILE"
echo '```\n' >> "$REPORT_FILE"


# Create a temporary directory for the benchmark
TMP_DIR=$(mktemp -d)

# Run time benchmark
echo '### Time' | tee -a "$REPORT_FILE"

## Run warmup with non-built-in
echo "W/o built-in: Running warmup ($WARMUP_SIZE)"
for i in $(seq $WARMUP_SIZE); do
    perf stat -r 1 xg++ -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -D_GLIBCXX_DO_NOT_USE_BUILTIN_TRAITS -c $FILE 2>&1 | grep 'seconds time elapsed' | awk '{print $1}'
done > /dev/null
## Run samples with non-built-in
echo "W/o built-in: Running samples ($SAMPLE_SIZE)"
for i in $(seq $SAMPLE_SIZE); do
    perf stat -r 1 xg++ -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -D_GLIBCXX_DO_NOT_USE_BUILTIN_TRAITS -c $FILE 2>&1 | grep 'seconds time elapsed' | awk '{print $1}'
done > "$TMP_DIR/time_no_builtin.txt"

## Run warmup with built-in
echo "With built-in: Running warmup ($WARMUP_SIZE)"
for i in $(seq $WARMUP_SIZE); do
    perf stat -r 1 xg++ -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -c $FILE 2>&1 | grep 'seconds time elapsed' | awk '{print $1}'
done > /dev/null
## Run samples with built-in
echo "With built-in: Running samples ($SAMPLE_SIZE)"
for i in $(seq $SAMPLE_SIZE); do
    perf stat -r 1 xg++ -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -c $FILE 2>&1 | grep 'seconds time elapsed' | awk '{print $1}'
done > "$TMP_DIR/time_builtin.txt"

# Show statistics for time
echo '\n```console' >> "$REPORT_FILE"
echo "$ perf stat xg++ -std=$CXX_VERSION -c $FILE" >> "$REPORT_FILE"
ministat -w 70 "$TMP_DIR/time_no_builtin.txt" "$TMP_DIR/time_builtin.txt" | tee -a "$REPORT_FILE"
echo '```' >> "$REPORT_FILE"


echo '' | tee -a "$REPORT_FILE"


# Run peak memory usage benchmark
echo '### Peak Memory Usage' | tee -a "$REPORT_FILE"

## Run warmup with non-built-in
echo "W/o built-in: Running warmup ($WARMUP_SIZE)"
for i in $(seq $WARMUP_SIZE); do
    /usr/bin/time -v xg++ -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -D_GLIBCXX_DO_NOT_USE_BUILTIN_TRAITS -c $FILE 2>&1 | grep 'Maximum resident set size' | awk '{print $6}'
done > /dev/null
## Run samples with non-built-in
echo "W/o built-in: Running samples ($SAMPLE_SIZE)"
for i in $(seq $SAMPLE_SIZE); do
    /usr/bin/time -v xg++ -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -D_GLIBCXX_DO_NOT_USE_BUILTIN_TRAITS -c $FILE 2>&1 | grep 'Maximum resident set size' | awk '{print $6}'
done > "$TMP_DIR/peak_mem_no_builtin.txt"

## Run warmup with built-in
echo "With built-in: Running warmup ($WARMUP_SIZE)"
for i in $(seq $WARMUP_SIZE); do
    /usr/bin/time -v xg++ -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -c $FILE 2>&1 | grep 'Maximum resident set size' | awk '{print $6}'
done > /dev/null
## Run samples with built-in
echo "With built-in: Running samples ($SAMPLE_SIZE)"
for i in $(seq $SAMPLE_SIZE); do
    /usr/bin/time -v xg++ -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -c $FILE 2>&1 | grep 'Maximum resident set size' | awk '{print $6}'
done > "$TMP_DIR/peak_mem_builtin.txt"

# Show statistics for peak memory usage
echo '\n```console' >> "$REPORT_FILE"
echo "$ /usr/bin/time -v xg++ -std=$CXX_VERSION -c $FILE" >> "$REPORT_FILE"
ministat -w 70 "$TMP_DIR/peak_mem_no_builtin.txt" "$TMP_DIR/peak_mem_builtin.txt" | tee -a "$REPORT_FILE"
echo '```' >> "$REPORT_FILE"


echo '' | tee -a "$REPORT_FILE"


# Run total memory usage benchmark
echo '### Total Memory Usage' | tee -a "$REPORT_FILE"

## Run warmup with non-built-in
echo "W/o built-in: Running warmup ($WARMUP_SIZE)"
for i in $(seq $WARMUP_SIZE); do
    xg++ -ftime-report -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -D_GLIBCXX_DO_NOT_USE_BUILTIN_TRAITS -c $FILE 2>&1 | grep TOTAL | awk '{print $6}' | sed 's/M$//'
done > /dev/null
## Run samples with non-built-in
echo "W/o built-in: Running samples ($SAMPLE_SIZE)"
for i in $(seq $SAMPLE_SIZE); do
    xg++ -ftime-report -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -D_GLIBCXX_DO_NOT_USE_BUILTIN_TRAITS -c $FILE 2>&1 | grep TOTAL | awk '{print $6}' | sed 's/M$//'
done > "$TMP_DIR/total_mem_no_builtin.txt"

## Run warmup with built-in
echo "With built-in: Running warmup ($WARMUP_SIZE)"
for i in $(seq $WARMUP_SIZE); do
    xg++ -ftime-report -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -c $FILE 2>&1 | grep TOTAL | awk '{print $6}' | sed 's/M$//'
done > /dev/null
## Run samples with built-in
echo "With built-in: Running samples ($SAMPLE_SIZE)"
for i in $(seq $SAMPLE_SIZE); do
    xg++ -ftime-report -std=$CXX_VERSION -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -c $FILE 2>&1 | grep TOTAL | awk '{print $6}' | sed 's/M$//'
done > "$TMP_DIR/total_mem_builtin.txt"

# Show statistics for total memory usage
echo '\n```console' >> "$REPORT_FILE"
echo "$ xg++ -ftime-report -std=$CXX_VERSION -c $FILE" >> "$REPORT_FILE"
ministat -w 70 "$TMP_DIR/total_mem_no_builtin.txt" "$TMP_DIR/total_mem_builtin.txt" | tee -a "$REPORT_FILE"
echo '```' >> "$REPORT_FILE"


echo '\n---\n' >> "$REPORT_FILE"
