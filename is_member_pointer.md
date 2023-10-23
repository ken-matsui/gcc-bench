## Sat Oct 21 11:02:39 PM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_member_pointer.cc
x /tmp/tmp.XSVqMq0WXE/time_no_builtin.txt
+ /tmp/tmp.XSVqMq0WXE/time_builtin.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                     |
|+                                                                     |
|+                                                               x     |
|+ +                                                             x  x  |
|+ +++                                                          xxxxxxx|
|MA_|                                                            |_A_| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     21.914079     22.980079     22.492233     22.339249    0.39897838
+  10     9.8454666     10.494251     9.8834543      10.05134    0.24810386
Difference at 95.0% confidence
	-12.2879 +/- 0.312152
	-55.0059% +/- 1.39732%
	(Student's t, pooled s = 0.332219)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_member_pointer.cc
x /tmp/tmp.XSVqMq0WXE/peak_mem_no_builtin.txt
+ /tmp/tmp.XSVqMq0WXE/peak_mem_builtin.txt
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
x  10       4118276       4118644       4118404     4118422.8     114.29474
+  10       2150352       2150592       2150472     2150458.4      82.54184
Difference at 95.0% confidence
	-1.96796e+06 +/- 93.6689
	-47.7844% +/- 0.00227439%
	(Student's t, pooled s = 99.6906)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_member_pointer.cc
x /tmp/tmp.XSVqMq0WXE/total_mem_no_builtin.txt
+ /tmp/tmp.XSVqMq0WXE/total_mem_builtin.txt
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
x  10          5113          5113          5113          5113             0
+  10          2507          2507          2507          2507             0
Difference at 95.0% confidence
	-2606 +/- 0
	-50.9681% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_member_pointer/time_no_builtin.txt
+ ./reports/built-ins/is_member_pointer/time_builtin.txt
+----------------------------------------------------------------------+
|    +                                                                 |
|   +++                                                    x           |
|+ ++++ +                                             x   xxxxx  x  x x|
|  |_A_|                                                 |___MA___|    |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     22.577469     25.926299     24.056296      24.17177     1.0097955
+  10     11.541709     13.040381      12.41863     12.332072    0.40574331
Difference at 95.0% confidence
	-11.8397 +/- 0.723035
	-48.9815% +/- 2.99124%
	(Student's t, pooled s = 0.769518)
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_member_pointer/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_member_pointer/peak_mem_builtin.txt
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
x  10       4117504       4117892       4117628     4117646.4     107.87977
+  10       2149396       2149860       2149608     2149599.2     164.60917
Difference at 95.0% confidence
	-1.96805e+06 +/- 130.76
	-47.7954% +/- 0.00317559%
	(Student's t, pooled s = 139.166)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_member_pointer/total_mem_no_builtin.txt
+ ./reports/built-ins/is_member_pointer/total_mem_builtin.txt
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
x  10          5113          5113          5113          5113             0
+  10          2507          2507          2507          2507             0
Difference at 95.0% confidence
	-2606 +/- 0
	-50.9681% +/- 0%
	(Student's t, pooled s = 0)
```

---

