## Sat Oct 21 11:55:16 PM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_object.cc
x /tmp/tmp.nIhfMxy4a5/time_no_builtin.txt
+ /tmp/tmp.nIhfMxy4a5/time_builtin.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                   x |
|+ +                                                                 x |
|+++                                                           x     xx|
|+++                                                           xx  x xx|
||A|                                                            |__A_M||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     8.7665668      9.394702     9.2841521     9.1495283    0.25544911
+  10     3.3161825     3.5054768     3.4261053     3.3978673   0.082049445
Difference at 95.0% confidence
	-5.75166 +/- 0.178259
	-62.8629% +/- 1.94828%
	(Student's t, pooled s = 0.189719)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_object.cc
x /tmp/tmp.nIhfMxy4a5/peak_mem_no_builtin.txt
+ /tmp/tmp.nIhfMxy4a5/peak_mem_builtin.txt
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
x  10       1918340       1918596       1918468     1918458.4     88.808407
+  10        970396        970764        970512        970546     112.70019
Difference at 95.0% confidence
	-947912 +/- 95.3314
	-49.4101% +/- 0.00496917%
	(Student's t, pooled s = 101.46)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_object.cc
x /tmp/tmp.nIhfMxy4a5/total_mem_no_builtin.txt
+ /tmp/tmp.nIhfMxy4a5/total_mem_builtin.txt
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
x  10          2417          2417          2417          2417             0
+  10          1141          1141          1141          1141             0
Difference at 95.0% confidence
	-1276 +/- 0
	-52.7927% +/- 0%
	(Student's t, pooled s = 0)
```

---

