## Mon Sep 11 09:29:27 PM PDT 2023

https://github.com/ken-matsui/gsoc23/blob/f875d1a16130b5e301b882c3a9e0a8236f60b5f1/is_member_pointer_v.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230912 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
721021a18e2ac004140ddd93113c11075ea890c6
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
b35c72c21795f3d8cec969395dba2c27d9607dc9
4c368cd72abe4aa90aefb659fdd3c2ac95d2b9fe
```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_member_pointer_v.cc
x /tmp/tmp.9441YLswCw/time_A.txt
+ /tmp/tmp.9441YLswCw/time_B.txt
+----------------------------------------------------------------------+
|    +                                                        x        |
|    +                                                        x        |
|+   +                                                        x        |
|+   +                                                        x      x |
|+   +                                                        x      x |
|+   +                                                        x      xx|
||__AM|                                                      |M__A__|  |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     13.391522     14.280132     13.479845     13.739878    0.37807586
+  10     6.9775123     7.4474665     7.4068671     7.2541428     0.2257727
Difference at 95.0% confidence
	-6.48574 +/- 0.292571
	-47.2037% +/- 2.12936%
	(Student's t, pooled s = 0.31138)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_member_pointer_v.cc
x /tmp/tmp.9441YLswCw/peak_mem_A.txt
+ /tmp/tmp.9441YLswCw/peak_mem_B.txt
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
x  10       2529332       2529476       2529436       2529426     46.197643
+  10       1532272       1532500       1532384     1532370.4     68.616809
Difference at 95.0% confidence
	-997056 +/- 54.9583
	-39.4183% +/- 0.00217276%
	(Student's t, pooled s = 58.4914)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_member_pointer_v.cc
x /tmp/tmp.9441YLswCw/total_mem_A.txt
+ /tmp/tmp.9441YLswCw/total_mem_B.txt
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
x  10          2934          2934          2934          2934             0
+  10          1702          1702          1702          1702             0
Difference at 95.0% confidence
	-1232 +/- 0
	-41.9905% +/- 0%
	(Student's t, pooled s = 0)
```

---

