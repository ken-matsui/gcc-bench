## Mon Sep 11 09:56:01 AM PDT 2023

https://github.com/ken-matsui/gsoc23/blob/e66f1086a6f0341d1cbfe2c14b01e86c558b3e72/is_member_function_pointer_v.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230911 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
286655d04678cb61dee9cac43b139571247c4ad1
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
7274c0c91c0adb325d9d6fe082e45353a785b4a1
ef3fcee4cb55b47841a5cb8470bcca5944f9e655
```

### Time

```console
$ perf stat xg++ -c is_member_function_pointer_v.cc
x /tmp/tmp.WGWMKAE75o/time_A.txt
+ /tmp/tmp.WGWMKAE75o/time_B.txt
+----------------------------------------------------------------------+
| +   +                                                   x            |
|++   +                                                   xx        x  |
|+++  ++                                                  xx     x  xxx|
||_A__|                                                   |____A_M__|  |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     6.8678442     7.3836188     7.1732782     7.0936515    0.21700271
+  10     4.4990724     4.7384817      4.587474     4.6028898   0.093147976
Difference at 95.0% confidence
	-2.49076 +/- 0.156897
	-35.1125% +/- 2.21179%
	(Student's t, pooled s = 0.166983)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_member_function_pointer_v.cc
x /tmp/tmp.WGWMKAE75o/peak_mem_A.txt
+ /tmp/tmp.WGWMKAE75o/peak_mem_B.txt
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
x  10       1534788       1535084       1534980     1534951.2     86.959506
+  10       1139076       1139316       1139192     1139194.4     71.807149
Difference at 95.0% confidence
	-395757 +/- 74.9272
	-25.783% +/- 0.0048814%
	(Student's t, pooled s = 79.744)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_member_function_pointer_v.cc
x /tmp/tmp.WGWMKAE75o/total_mem_A.txt
+ /tmp/tmp.WGWMKAE75o/total_mem_B.txt
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
x  10          1775          1775          1775          1775             0
+  10          1279          1279          1279          1279             0
Difference at 95.0% confidence
	-496 +/- 0
	-27.9437% +/- 0%
	(Student's t, pooled s = 0)
```

---
## Sat Oct 21 09:42:59 PM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_member_function_pointer_v.cc
x /tmp/tmp.FrMUoC5Xoz/time_no_builtin.txt
+ /tmp/tmp.FrMUoC5Xoz/time_builtin.txt
+----------------------------------------------------------------------+
|+                                                                  x  |
|++                                                                 x  |
|++  +                                                            x x  |
|+++ +                                                         xx x xxx|
||A_|                                                            |_AM| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10      13.30942     14.247305     14.004239     13.856251     0.2975967
+  10     4.6035219     5.1754034     4.7729196     4.7968868    0.19587569
Difference at 95.0% confidence
	-9.05936 +/- 0.236706
	-65.3811% +/- 1.7083%
	(Student's t, pooled s = 0.251924)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_member_function_pointer_v.cc
x /tmp/tmp.FrMUoC5Xoz/peak_mem_no_builtin.txt
+ /tmp/tmp.FrMUoC5Xoz/peak_mem_builtin.txt
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
x  10       2683092       2683576       2683344     2683327.6     159.10248
+  10       1141860       1142148       1142076     1142032.8     88.479501
Difference at 95.0% confidence
	-1.54129e+06 +/- 120.953
	-57.4397% +/- 0.00450758%
	(Student's t, pooled s = 128.729)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_member_function_pointer_v.cc
x /tmp/tmp.FrMUoC5Xoz/total_mem_no_builtin.txt
+ /tmp/tmp.FrMUoC5Xoz/total_mem_builtin.txt
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
x  10          3204          3204          3204          3204             0
+  10          1292          1292          1292          1292             0
Difference at 95.0% confidence
	-1912 +/- 0
	-59.6754% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_member_function_pointer_v/time_no_builtin.txt
+ ./reports/built-ins/is_member_function_pointer_v/time_builtin.txt
+----------------------------------------------------------------------+
|  +                                                                   |
|  ++ ++                                                               |
|+ ++ ++                                                 x  xxx xx xxxx|
| |_A_|                                                     |___AM___| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     13.906954     15.891452     15.162468     15.030183    0.64083178
+  10     5.1534387     6.1004115     5.6788731     5.6806244    0.32557328
Difference at 95.0% confidence
	-9.34956 +/- 0.477562
	-62.2052% +/- 3.17735%
	(Student's t, pooled s = 0.508263)
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_member_function_pointer_v/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_member_function_pointer_v/peak_mem_builtin.txt
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
x  10       2682308       2682680       2682464     2682471.6     108.14723
+  10       1140908       1141400       1141284       1141210     176.43633
Difference at 95.0% confidence
	-1.54126e+06 +/- 137.492
	-57.4568% +/- 0.00512558%
	(Student's t, pooled s = 146.331)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_member_function_pointer_v/total_mem_no_builtin.txt
+ ./reports/built-ins/is_member_function_pointer_v/total_mem_builtin.txt
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
x  10          3204          3204          3204          3204             0
+  10          1292          1292          1292          1292             0
Difference at 95.0% confidence
	-1912 +/- 0
	-59.6754% +/- 0%
	(Student's t, pooled s = 0)
```

---

