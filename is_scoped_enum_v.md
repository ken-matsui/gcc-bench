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
