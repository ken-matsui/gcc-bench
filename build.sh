#!/bin/zsh
set -eu

# Exit on Ctrl+C
trap "exit" INT

# Make sure we have commands to use
check_cmd() {
    if ! command -v $1 &> /dev/null; then
        echo "command `$1` not found"
        exit 1
    fi
}
check_cmd xg++
check_cmd dirname
check_cmd where

usage() {
    echo 'Usage: ./build.sh A|B <build-file> [-- <xg++-args>]'
    echo 'Example: ./build.sh A is_object.cc'
    echo 'Example: ./build.sh B is_object.cc -- -O3'
    exit 1
}

# Make sure we have the right number of arguments
# If -- is supplied, pass all arguments after it to xg++
if [ $# -lt 2 ]; then
    usage
fi

# Make sure the first argument is either A or B
if [ "$1" != "A" ] && [ "$1" != "B" ]; then
    usage
fi
# Set BUILD_EITHER to GSOC23_BENCH_A if A, GSOC23_BENCH_B if B.
# Use upper case for the macro name.
BUILD_EITHER="GSOC23_BENCH_$1"

# Make sure the benchmark file exists
if [ ! -f "$2" ]; then
    echo "Build file $2 does not exist"
    exit 1
fi
# Make sure the benchmark file is a C++ file (.cc)
if [ "${2: -3}" != ".cc" ]; then
    echo "Build file $2 is not a C++ file"
    exit 1
fi
FILE=$2

# Retrieve -- args
if [ $# -gt 2 ]; then
    shift
    shift
    if [ "$1" = "--" ]; then
        shift
        XGPP_ARGS=$@
    else
        usage
    fi
else
    XGPP_ARGS=""
fi

XGPP_DIR=$(dirname $(where xg++)) # i.e. .../gcc/objdir/gcc; assuming xg++ is under the GCC directory
GCC_BUILD_DIR="$XGPP_DIR/.."  # i.e. .../gcc/objdir
GCC_DIR="$GCC_BUILD_DIR/.."  # i.e. .../gcc

# Set include & link directories
INCLUDE_PATH1="$GCC_BUILD_DIR/x86_64-pc-linux-gnu/libstdc++-v3/include"
INCLUDE_PATH2="$GCC_BUILD_DIR/x86_64-pc-linux-gnu/libstdc++-v3/include/x86_64-pc-linux-gnu"
INCLUDE_PATH3="$GCC_DIR/gcc/ginclude"  # for stddef.h

xg++ -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" -D"$BUILD_EITHER" $XGPP_ARGS -c $FILE
