#!/bin/zsh
set -eu

# Exit on Ctrl+C
trap 'exit 1' INT

# Check if 2 arguments were passed
if [ $# -ne 2 ]; then
    echo "Usage: $0 <dir_before> <dir_after>"
    exit 1
fi
DIR_BEFORE=$1
DIR_AFTER=$2

# Check if the directories exist
if [ ! -d "$DIR_BEFORE" ]; then
    echo "Directory $DIR_BEFORE does not exist"
    exit 1
fi
if [ ! -d "$DIR_AFTER" ]; then
    echo "Directory $DIR_AFTER does not exist"
    exit 1
fi

# Show statistics for time benchmark
echo "Time benchmark"
echo "=============="
echo ''
ministat -w 70 "$DIR_BEFORE/time.txt" "$DIR_AFTER/time.txt"

echo ''

# Show statistics for peak memory benchmark
echo "Peak memory benchmark"
echo "====================="
echo ''
ministat -w 70 "$DIR_BEFORE/peak_memory.txt" "$DIR_AFTER/peak_memory.txt"
