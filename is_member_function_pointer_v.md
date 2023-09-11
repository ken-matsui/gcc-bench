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
