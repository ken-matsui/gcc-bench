## Sun Oct 22 12:44:15 AM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_scoped_enum.cc
x /tmp/tmp.cVB7ThxQAH/time_no_builtin.txt
+ /tmp/tmp.cVB7ThxQAH/time_builtin.txt
+----------------------------------------------------------------------+
|                 +                                                    |
|                 +               x                                    |
|                 +              xx                                    |
|+ + +        +   +  +        + xxx x            x          x         x|
|    |________A___M_____|   |_____M______A_____________|               |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     3.9054656      4.249295     3.9252424     3.9908792    0.12330827
+  10     3.6238378     3.8870111     3.7768624     3.7460308   0.082771021
Difference at 95.0% confidence
	-0.244848 +/- 0.0986709
	-6.1352% +/- 2.47241%
	(Student's t, pooled s = 0.105014)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_scoped_enum.cc
x /tmp/tmp.cVB7ThxQAH/peak_mem_no_builtin.txt
+ /tmp/tmp.cVB7ThxQAH/peak_mem_builtin.txt
+----------------------------------------------------------------------+
| +                                                                  x |
| +                                                                  x |
| ++                                                                 x |
| ++                                                                xxx|
|++++                                                              xxxx|
||A|                                                                |A||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1028740       1029048       1028920     1028910.4     86.803994
+  10       1021448       1021772       1021548     1021587.6     99.231716
Difference at 95.0% confidence
	-7322.8 +/- 87.594
	-0.711704% +/- 0.00851328%
	(Student's t, pooled s = 93.2252)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_scoped_enum.cc
x /tmp/tmp.cVB7ThxQAH/total_mem_no_builtin.txt
+ /tmp/tmp.cVB7ThxQAH/total_mem_builtin.txt
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
x  10          1239          1239          1239          1239             0
+  10          1209          1209          1209          1209             0
Difference at 95.0% confidence
	-30 +/- 0
	-2.42131% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_scoped_enum/time_no_builtin.txt
+ ./reports/built-ins/is_scoped_enum/time_builtin.txt
+----------------------------------------------------------------------+
|                        +                                             |
|                        +             x                               |
|+              + +    + +++  x  *     xx         x           xx x    x|
|            |________A__M_____|  |______________AM_____________|      |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.5087199     5.1254173     4.8224691     4.8035112    0.22781009
+  10      4.060389     4.5535449     4.4309131     4.3850414    0.13415958
Difference at 95.0% confidence
	-0.41847 +/- 0.175652
	-8.71175% +/- 3.65674%
	(Student's t, pooled s = 0.186944)
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_scoped_enum/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_scoped_enum/peak_mem_builtin.txt
+----------------------------------------------------------------------+
|   +                                                                  |
|   +                                                                  |
|   +                                                                x |
|   +                                                                x |
|   +                                                                x |
|   +                                                               xxx|
|++++                                                             x xxx|
| |AM|                                                             |_A||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1027880       1028396       1028304     1028236.8     155.19221
+  10       1020344       1020720       1020696     1020630.4      124.0387
Difference at 95.0% confidence
	-7606.4 +/- 131.996
	-0.739752% +/- 0.0128371%
	(Student's t, pooled s = 140.482)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_scoped_enum/total_mem_no_builtin.txt
+ ./reports/built-ins/is_scoped_enum/total_mem_builtin.txt
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
x  10          1239          1239          1239          1239             0
+  10          1209          1209          1209          1209             0
Difference at 95.0% confidence
	-30 +/- 0
	-2.42131% +/- 0%
	(Student's t, pooled s = 0)
```

---

