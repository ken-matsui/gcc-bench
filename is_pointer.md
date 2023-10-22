## Sun Oct 22 12:15:00 AM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_pointer.cc
x /tmp/tmp.YTZd0zgsGl/time_no_builtin.txt
+ /tmp/tmp.YTZd0zgsGl/time_builtin.txt
+----------------------------------------------------------------------+
|                                   +                                  |
|   x                               +                                  |
|   xx                       x      +                                  |
|  xxx                       xx  x ++  +           +  +       +       +|
||___M_________A____________|   |______M_____A____________|            |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.7004852     5.0691313     4.7316591     4.8418325    0.16362216
+  10     5.0902249     5.5102333      5.134115     5.2143697    0.15656603
Difference at 95.0% confidence
	0.372537 +/- 0.15046
	7.69414% +/- 3.10751%
	(Student's t, pooled s = 0.160133)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_pointer.cc
x /tmp/tmp.YTZd0zgsGl/peak_mem_no_builtin.txt
+ /tmp/tmp.YTZd0zgsGl/peak_mem_builtin.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                   xx|
|A                                                                    A|
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1284084       1284588       1284460     1284382.4     160.22429
+  10       1226200       1226532       1226368       1226364     111.41115
Difference at 95.0% confidence
	-58018.4 +/- 129.658
	-4.51722% +/- 0.010095%
	(Student's t, pooled s = 137.993)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_pointer.cc
x /tmp/tmp.YTZd0zgsGl/total_mem_no_builtin.txt
+ /tmp/tmp.YTZd0zgsGl/total_mem_builtin.txt
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
x  10          1498          1498          1498          1498             0
+  10          1473          1473          1473          1473             0
Difference at 95.0% confidence
	-25 +/- 0
	-1.66889% +/- 0%
	(Student's t, pooled s = 0)
```

---

