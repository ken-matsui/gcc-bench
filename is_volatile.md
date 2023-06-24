## Sat Jun 24 07:40:36 AM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/4c4310e08be128f5781a76e27815696fc5fe775f/is_volatile.cc

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230624 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
31b7659995caccca626709ecb634339f75980ff2
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
9aa3c857842984a307c959278ccb7491cb4efe21
7c332d241cfe6be2fa6b22456a564e0c03b8cbf3
```

### Time

```console
$ perf stat xg++ -c is_volatile.cc
x /tmp/tmp.IAvyC5OMf7/time_before.txt
+ /tmp/tmp.IAvyC5OMf7/time_after.txt
+----------------------------------------------------------------------+
|+  +++   +     +          xx x   +*      ++                     x x  x|
|  |____________M___A___|__________M_|_______A___________________|     |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     2.8518002     2.9742907     2.8745644     2.9021609   0.057199974
+  10     2.7789344     2.8969829     2.8215754     2.8318313   0.047785726
Difference at 95.0% confidence
	-0.0703296 +/- 0.04952
	-2.42335% +/- 1.70631%
	(Student's t, pooled s = 0.0527035)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_volatile.cc
x /tmp/tmp.IAvyC5OMf7/peak_mem_before.txt
+ /tmp/tmp.IAvyC5OMf7/peak_mem_after.txt
+----------------------------------------------------------------------+
|  +                                                                   |
|  +                                                                 x |
|  +                                                                 x |
|  +                                                                 x |
|+ +                                                                xxx|
|++++                                                              xxxx|
| AM                                                                |A||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10        910980        911364        911244      911204.8     124.59071
+  10        901188        901576        901424      901395.6     122.03388
Difference at 95.0% confidence
	-9809.2 +/- 115.87
	-1.07651% +/- 0.0127161%
	(Student's t, pooled s = 123.319)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_volatile.cc
x /tmp/tmp.IAvyC5OMf7/total_mem_before.txt
+ /tmp/tmp.IAvyC5OMf7/total_mem_after.txt
+----------------------------------------------------------------------+
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|A                                                                    A|
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10          1047          1047          1047          1047             0
+  10          1030          1030          1030          1030             0
Difference at 95.0% confidence
	-17 +/- 0
	-1.62369% +/- 0%
	(Student's t, pooled s = 0)
```

---

