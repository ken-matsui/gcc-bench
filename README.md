# gcc-benches

GCC Benchmarks for GSoC 2023

## Environment

### Arch

```console
$ uname -m
x86_64
```

### CPU

```console
$ lscpu | grep 'Model name'
Model name: 11th Gen Intel(R) Core(TM) i7-1185G7 @ 3.00GHz

$ nproc --all
8
```

### Caches

```console
$ lscpu | grep "cache"
L1d cache: 192 KiB (4 instances)
L1i cache: 128 KiB (4 instances)
L2 cache: 5 MiB (4 instances)
L3 cache: 12 MiB (1 instance)
```

### Memory

```console
$ free -m
               total        used        free      shared  buff/cache   available
Mem:           15681        6642        4538         735        5559        9038
Swap:           1955           0        1955
```

## Tools

* Linux perf
* /usr/bin/time
* -ftime-report
* ministat

## Benchmark Script

```console
$ ./bench.sh is_object_benchmark.cc
```
