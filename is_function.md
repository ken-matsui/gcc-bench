## Sat Oct 21 09:12:25 PM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_function.cc
x /tmp/tmp.PKZGYrLLfi/time_no_builtin.txt
+ /tmp/tmp.PKZGYrLLfi/time_builtin.txt
+----------------------------------------------------------------------+
|+         +           +                   x              x            |
|+ +       +    ++ +   +                   x   x    x    xx x      x  x|
|   |_______A___M____|                        |________A__M______|     |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     5.7556625     6.3289907     6.0696598      6.023702     0.1983235
+  10     4.8767241     5.3436679     5.1825268     5.1165366    0.17771893
Difference at 95.0% confidence
	-0.907165 +/- 0.176929
	-15.0599% +/- 2.93721%
	(Student's t, pooled s = 0.188303)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_function.cc
x /tmp/tmp.PKZGYrLLfi/peak_mem_no_builtin.txt
+ /tmp/tmp.PKZGYrLLfi/peak_mem_builtin.txt
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
x  10       1445900       1446544       1446336     1446327.6     169.65796
+  10       1180432       1180780       1180664     1180605.6     119.70631
Difference at 95.0% confidence
	-265722 +/- 137.953
	-18.3722% +/- 0.00953818%
	(Student's t, pooled s = 146.822)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_function.cc
x /tmp/tmp.PKZGYrLLfi/total_mem_no_builtin.txt
+ /tmp/tmp.PKZGYrLLfi/total_mem_builtin.txt
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
x  10          1721          1721          1721          1721             0
+  10          1426          1426          1426          1426             0
Difference at 95.0% confidence
	-295 +/- 0
	-17.1412% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_function/time_no_builtin.txt
+ ./reports/built-ins/is_function/time_builtin.txt
+----------------------------------------------------------------------+
|  +                   +                                               |
|+ +  ++   + x      x +++        x       x   x  x   x       x    x    x|
|  |_______MA_________|   |__________________A__M______________|       |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     6.2080386     7.3979806     6.9500102     6.8733216    0.38697059
+  10      5.964885     6.4523702     6.1748106     6.1986185    0.19897179
Difference at 95.0% confidence
	-0.674703 +/- 0.289096
	-9.81626% +/- 4.20607%
	(Student's t, pooled s = 0.307682)
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_function/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_function/peak_mem_builtin.txt
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
x  10       1445408       1445760       1445448     1445510.4     133.58909
+  10       1179556       1179928       1179748     1179726.4     103.93502
Difference at 95.0% confidence
	-265784 +/- 112.455
	-18.3869% +/- 0.00777958%
	(Student's t, pooled s = 119.684)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_function/total_mem_no_builtin.txt
+ ./reports/built-ins/is_function/total_mem_builtin.txt
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
x  10          1721          1721          1721          1721             0
+  10          1426          1426          1426          1426             0
Difference at 95.0% confidence
	-295 +/- 0
	-17.1412% +/- 0%
	(Student's t, pooled s = 0)
```

---

