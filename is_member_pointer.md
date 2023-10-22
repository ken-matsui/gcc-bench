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

