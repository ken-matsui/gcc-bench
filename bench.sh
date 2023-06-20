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
check_cmd git
check_cmd xg++

# Make sure we have the right number of arguments
if [ $# -ne 2 ]; then
    echo 'Usage: ./bench.sh <benchmark-file> <#-of-commits>'
    echo 'Example: ./bench.sh is_object.cc 6'
    exit 1
fi
NUM_COMMITS=$2

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

# Create a benchmark report file if it doesn't exist
REPORT_FILE="$FILENAME.md"
touch "$REPORT_FILE"
echo "## $(date)" >> "$REPORT_FILE"

echo '\n```console' >> "$REPORT_FILE"
echo '$ xg++ --version' >> "$REPORT_FILE"
xg++ --version >> "$REPORT_FILE"
echo '```\n' >> "$REPORT_FILE"

pushd $(dirname $(where xg++)) # assuming xg++ is under the GCC directory (e.g. .../gcc/objdir/gcc/xg++)
BASE_COMMIT=$(git rev-parse HEAD~"$NUM_COMMITS")
COMMITS_MADE=$(git log -n "$NUM_COMMITS" --pretty=format:%H)
popd

echo '```console' >> "$REPORT_FILE"
echo "$ git rev-parse HEAD~"$NUM_COMMITS"  # base commit" >> "$REPORT_FILE"
echo "$BASE_COMMIT" >> "$REPORT_FILE"
echo '```\n' >> "$REPORT_FILE"

echo '```console' >> "$REPORT_FILE"
echo "$ git log -n "$NUM_COMMITS" --pretty=format:%H  # changes from the base" >> "$REPORT_FILE"
echo "$COMMITS_MADE" >> "$REPORT_FILE"
echo '```\n' >> "$REPORT_FILE"


# Create a temporary directory for the benchmark
TMP_DIR=$(mktemp -d)

# Set include directories
CPLUS_INCLUDE_PATH=/usr/include/c++/13:/usr/include/x86_64-linux-gnu/c++/13:/usr/include/linux


# Run time benchmark
echo '### Time' | tee -a "$REPORT_FILE"

## Run warmup without built-ins
echo "Running warmup ($WARMUP_SIZE) without built-ins"
for i in $(seq $WARMUP_SIZE); do
    perf stat -r 1 xg++ -c $FILE 2>&1 | grep 'seconds time elapsed' | awk '{print $1}'
done > /dev/null
## Run sample without built-ins
echo "Running samples ($SAMPLE_SIZE) without built-ins"
for i in $(seq $SAMPLE_SIZE); do
    perf stat -r 1 xg++ -c $FILE 2>&1 | grep 'seconds time elapsed' | awk '{print $1}'
done > "$TMP_DIR/time_before.txt"

## Run warmup with built-ins
echo "Running warmup ($WARMUP_SIZE) with built-ins"
for i in $(seq $WARMUP_SIZE); do
    perf stat -r 1 xg++ -DUSE_BUILTIN -c $FILE 2>&1 | grep 'seconds time elapsed' | awk '{print $1}'
done > /dev/null
## Run sample with built-ins
echo "Running samples ($SAMPLE_SIZE) with built-ins"
for i in $(seq $SAMPLE_SIZE); do
    perf stat -r 1 xg++ -DUSE_BUILTIN -c $FILE 2>&1 | grep 'seconds time elapsed' | awk '{print $1}'
done > "$TMP_DIR/time_after.txt"

# Show statistics for time
echo '\n```console' >> "$REPORT_FILE"
echo "$ perf stat xg++ -c $FILE" >> "$REPORT_FILE"
ministat -w 70 "$TMP_DIR/time_before.txt" "$TMP_DIR/time_after.txt" | tee -a "$REPORT_FILE"
echo '```' >> "$REPORT_FILE"


echo '' | tee -a "$REPORT_FILE"


# Run peak memory usage benchmark
echo '### Peak Memory Usage' | tee -a "$REPORT_FILE"

## Run warmup without built-ins
echo "Running warmup ($WARMUP_SIZE) without built-ins"
for i in $(seq $WARMUP_SIZE); do
    /usr/bin/time -v xg++ -c $FILE 2>&1 | grep 'Maximum resident set size' | awk '{print $6}'
done > /dev/null
## Run sample without built-ins
echo "Running samples ($SAMPLE_SIZE) without built-ins"
for i in $(seq $SAMPLE_SIZE); do
    /usr/bin/time -v xg++ -c $FILE 2>&1 | grep 'Maximum resident set size' | awk '{print $6}'
done > "$TMP_DIR/peak_mem_before.txt"

## Run warmup with built-ins
echo "Running warmup ($WARMUP_SIZE) with built-ins"
for i in $(seq $WARMUP_SIZE); do
    /usr/bin/time -v xg++ -DUSE_BUILTIN -c $FILE 2>&1 | grep 'Maximum resident set size' | awk '{print $6}'
done > /dev/null
## Run sample with built-ins
echo "Running samples ($SAMPLE_SIZE) with built-ins"
for i in $(seq $SAMPLE_SIZE); do
    /usr/bin/time -v xg++ -DUSE_BUILTIN -c $FILE 2>&1 | grep 'Maximum resident set size' | awk '{print $6}'
done > "$TMP_DIR/peak_mem_after.txt"

# Show statistics for peak memory usage
echo '\n```console' >> "$REPORT_FILE"
echo "$ /usr/bin/time -v xg++ -c $FILE" >> "$REPORT_FILE"
ministat -w 70 "$TMP_DIR/peak_mem_before.txt" "$TMP_DIR/peak_mem_after.txt" | tee -a "$REPORT_FILE"
echo '```' >> "$REPORT_FILE"


echo '' | tee -a "$REPORT_FILE"


# Run total memory usage benchmark
echo '### Total Memory Usage' | tee -a "$REPORT_FILE"

## Run warmup without built-ins
echo "Running warmup ($WARMUP_SIZE) without built-ins"
for i in $(seq $WARMUP_SIZE); do
    xg++ -ftime-report -c $FILE 2>&1 | grep TOTAL | awk '{print $6}' | sed 's/M$//'
done > /dev/null
## Run sample without built-ins
echo "Running samples ($SAMPLE_SIZE) without built-ins"
for i in $(seq $SAMPLE_SIZE); do
    xg++ -ftime-report -c $FILE 2>&1 | grep TOTAL | awk '{print $6}' | sed 's/M$//'
done > "$TMP_DIR/total_mem_before.txt"

## Run warmup with built-ins
echo "Running warmup ($WARMUP_SIZE) with built-ins"
for i in $(seq $WARMUP_SIZE); do
    xg++ -ftime-report -DUSE_BUILTIN -c $FILE 2>&1 | grep TOTAL | awk '{print $6}' | sed 's/M$//'
done > /dev/null
## Run sample with built-ins
echo "Running samples ($SAMPLE_SIZE) with built-ins"
for i in $(seq $SAMPLE_SIZE); do
    xg++ -ftime-report -DUSE_BUILTIN -c $FILE 2>&1 | grep TOTAL | awk '{print $6}' | sed 's/M$//'
done > "$TMP_DIR/total_mem_after.txt"

# Show statistics for total memory usage
echo '\n```console' >> "$REPORT_FILE"
echo "$ xg++ -ftime-report -c $FILE" >> "$REPORT_FILE"
ministat -w 70 "$TMP_DIR/total_mem_before.txt" "$TMP_DIR/total_mem_after.txt" | tee -a "$REPORT_FILE"
echo '```' >> "$REPORT_FILE"


echo '\n---\n' >> "$REPORT_FILE"
