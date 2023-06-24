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

# Make sure we have the right number of arguments
# If -- is supplied, pass all arguments after it to xg++
if [ $# -lt 1 ]; then
    echo 'Usage: ./build.sh <build-file> [-- <xg++-args>]'
    echo 'Example: ./build.sh is_object.cc'
    echo 'Example: ./build.sh is_object.cc -- -O3'
    exit 1
fi

# Make sure the benchmark file exists
if [ ! -f "$1" ]; then
    echo "Build file $1 does not exist"
    exit 1
fi
# Make sure the benchmark file is a C++ file (.cc)
if [ "${1: -3}" != ".cc" ]; then
    echo "Build file $1 is not a C++ file"
    exit 1
fi
FILE=$1

# Retrieve -- args
if [ $# -gt 1 ]; then
    shift
    if [ "$1" = "--" ]; then
        shift
        XGPP_ARGS=$@
    else
        echo "Usage: ./build.sh <build-file> [-- <xg++-args>]"
        echo "Example: ./build.sh is_object.cc -- -O3"
        exit 1
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

xg++ -I"$INCLUDE_PATH1" -I"$INCLUDE_PATH2" -I"$INCLUDE_PATH3" $XGPP_ARGS -c $FILE
