# GCC Build Benchmark

This benchmark measures performance regression after [me/16-bit-enum-rid](https://github.com/ken-matsui/gcc-gsoc23/tree/me/16-bit-enum-rid).

## [8d8bc560b6ab7f3153db23ffb37157528e5b2c9a](https://gcc.gnu.org/git/?p=gcc.git;a=commit;h=8d8bc560b6ab7f3153db23ffb37157528e5b2c9a)

The master branch commit from which [me/16-bit-enum-rid](https://github.com/ken-matsui/gcc-gsoc23/tree/me/16-bit-enum-rid) is derived.

## [238947215e593f8a44f5fd68a49e1fcef235c6f6](https://github.com/ken-matsui/gcc-gsoc23/commit/238947215e593f8a44f5fd68a49e1fcef235c6f6)

HEAD of [me/16-bit-enum-rid](https://github.com/ken-matsui/gcc-gsoc23/tree/me/16-bit-enum-rid).

## Environment

Same as [README.md](../../README.md).

## Configuration

```bash
../configure --enable-languages=c++ --disable-error --enable-checking=release --disable-bootstrap
```

## Benchmarks

Used [scripts/bench-gcc-build.sh](https://github.com/ken-matsui/gsoc23/blob/c9437f468d0ad5bc7387b43c623d89ad4fd5e04b/scripts/bench-gcc-build.sh) on both commits. This script builds GCC and measures the performance. The results are stored this directory.

## Statistics

```console
$ ./scripts/stat-gcc-build.sh ./reports/gcc-build/8d8bc560b6ab7f3153db23ffb37157528e5b2c9a ./reports/gcc-build/238947215e593f8a44f5fd68a49e1fcef235c6f6
Time benchmark
==============

x ./reports/gcc-build/8d8bc560b6ab7f3153db23ffb37157528e5b2c9a/time.txt
+ ./reports/gcc-build/238947215e593f8a44f5fd68a49e1fcef235c6f6/time.txt
+----------------------------------------------------------------------+
|      x             x                 +                               |
|x     x x     x     x      +x + + +   +++*   +                       x|
||___________________MA_________|____A_M___|                           |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     819.50079     856.25885     830.28758     830.84325     11.084477
+  10     833.64196     843.21166     839.71668     838.74453     2.9339448
Difference at 95.0% confidence
        7.90128 +/- 7.61808
        0.950995% +/- 0.916909%
        (Student's t, pooled s = 8.10783)

Peak memory benchmark
=====================

x ./reports/gcc-build/8d8bc560b6ab7f3153db23ffb37157528e5b2c9a/peak_memory.txt
+ ./reports/gcc-build/238947215e593f8a44f5fd68a49e1fcef235c6f6/peak_memory.txt
+----------------------------------------------------------------------+
|+          xx++    +    +   +    x  + x x       xx   +      x  +     +|
|         |____________|_____M___A_____A_M____________|_|              |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1839608       1840068       1839880     1839858.4      149.4785
+  10       1839500       1840156       1839764     1839803.2     219.12797
No difference proven at 95.0% confidence
```
