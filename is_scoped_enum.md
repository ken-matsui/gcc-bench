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

