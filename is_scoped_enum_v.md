## Mon Sep 11 05:04:11 PM PDT 2023

https://github.com/ken-matsui/gsoc23/blob/5c284d735b0e74b464cc1a629fad1c0152ca8d31/is_scoped_enum_v.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230911 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
25c30049f5896ef6312cf45a1c058ee3e3079e6a
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
048927ed8561ca994ad853fe85ccf8c2ca07a8fe
316d57da5bb9205b946afc56d78582fee874e4b5
```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_scoped_enum_v.cc
x /tmp/tmp.VckpWmBEWZ/time_A.txt
+ /tmp/tmp.VckpWmBEWZ/time_B.txt
+----------------------------------------------------------------------+
|  +                                                               x   |
| ++                                                               xx  |
| ++                                                               xx  |
| ++     + ++                                                x     xxxx|
||_M_A___|                                                       |_AM_||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.2673449     4.4862935     4.4478224     4.4227799    0.05949854
+  10     2.9064265     3.1420003     2.9324074     2.9757774   0.094155188
Difference at 95.0% confidence
	-1.447 +/- 0.0739996
	-32.717% +/- 1.67315%
	(Student's t, pooled s = 0.0787568)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_scoped_enum_v.cc
x /tmp/tmp.VckpWmBEWZ/peak_mem_A.txt
+ /tmp/tmp.VckpWmBEWZ/peak_mem_B.txt
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
x  10       1095548       1095896       1095768     1095718.8     102.72812
+  10        905056        905416        905296      905277.6     114.28152
Difference at 95.0% confidence
	-190441 +/- 102.095
	-17.3805% +/- 0.00931763%
	(Student's t, pooled s = 108.658)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_scoped_enum_v.cc
x /tmp/tmp.VckpWmBEWZ/total_mem_A.txt
+ /tmp/tmp.VckpWmBEWZ/total_mem_B.txt
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
x  10          1294          1294          1294          1294             0
+  10          1047          1047          1047          1047             0
Difference at 95.0% confidence
	-247 +/- 0
	-19.0881% +/- 0%
	(Student's t, pooled s = 0)
```

---
## Sun Oct 22 12:50:23 AM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_scoped_enum_v.cc
x /tmp/tmp.1h5DYteHvL/time_no_builtin.txt
+ /tmp/tmp.1h5DYteHvL/time_builtin.txt
+----------------------------------------------------------------------+
| +                                                    x               |
| +   +                                                x               |
|+++++++                                               xx   x  xx     x|
| |_A_|                                              |__M__A____|      |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10      4.599905     5.0667456     4.6517754     4.7207256    0.16156969
+  10     2.9504342     3.1484237     3.0367281     3.0337029   0.067848214
Difference at 95.0% confidence
	-1.68702 +/- 0.116427
	-35.7365% +/- 2.46629%
	(Student's t, pooled s = 0.123912)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_scoped_enum_v.cc
x /tmp/tmp.1h5DYteHvL/peak_mem_no_builtin.txt
+ /tmp/tmp.1h5DYteHvL/peak_mem_builtin.txt
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
x  10       1107760       1108112       1107904     1107911.2     98.608992
+  10        906384        906736        906556      906544.8     104.32087
Difference at 95.0% confidence
	-201366 +/- 95.3738
	-18.1753% +/- 0.00860843%
	(Student's t, pooled s = 101.505)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_scoped_enum_v.cc
x /tmp/tmp.1h5DYteHvL/total_mem_no_builtin.txt
+ /tmp/tmp.1h5DYteHvL/total_mem_builtin.txt
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
x  10          1324          1324          1324          1324             0
+  10          1046          1046          1046          1046             0
Difference at 95.0% confidence
	-278 +/- 0
	-20.997% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_scoped_enum_v/time_no_builtin.txt
+ ./reports/built-ins/is_scoped_enum_v/time_builtin.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+    +                                                    x    x    x |
|+ +  +++   +  +                               x      x    x    xx   xx|
||____A____|                                           |______A_M____| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     5.2048712     6.0551091      5.838973     5.7598789    0.27491655
+  10     3.4819245     3.9856531     3.6676574     3.6665642    0.17547562
Difference at 95.0% confidence
	-2.09331 +/- 0.216689
	-36.343% +/- 3.76204%
	(Student's t, pooled s = 0.23062)
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_scoped_enum_v/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_scoped_enum_v/peak_mem_builtin.txt
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
x  10       1106984       1107192       1107108     1107099.2     69.864631
+  10        905876        906196        905996      906017.2     125.54663
Difference at 95.0% confidence
	-201082 +/- 95.4581
	-18.163% +/- 0.00862236%
	(Student's t, pooled s = 101.595)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_scoped_enum_v/total_mem_no_builtin.txt
+ ./reports/built-ins/is_scoped_enum_v/total_mem_builtin.txt
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
x  10          1324          1324          1324          1324             0
+  10          1046          1046          1046          1046             0
Difference at 95.0% confidence
	-278 +/- 0
	-20.997% +/- 0%
	(Student's t, pooled s = 0)
```

---

