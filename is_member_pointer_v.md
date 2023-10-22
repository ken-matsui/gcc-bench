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

## Sat Oct 21 11:29:09 PM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_member_pointer_v.cc
x /tmp/tmp.Kdtg8sTlH9/time_no_builtin.txt
+ /tmp/tmp.Kdtg8sTlH9/time_builtin.txt
+----------------------------------------------------------------------+
| +                                                                    |
| +                                                                    |
| +                                                                    |
| +                                                                    |
| +                                                                x x |
|++                                                              x x x |
|++ +                                                            xxx xx|
||A|                                                              |A_| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     25.889729     27.316278     26.531799      26.55368    0.50949211
+  10     7.0407625     8.0450519     7.3328379     7.3506609    0.28491568
Difference at 95.0% confidence
	-19.203 +/- 0.387838
	-72.3177% +/- 1.46058%
	(Student's t, pooled s = 0.412771)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_member_pointer_v.cc
x /tmp/tmp.Kdtg8sTlH9/peak_mem_no_builtin.txt
+ /tmp/tmp.Kdtg8sTlH9/peak_mem_builtin.txt
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
x  10       4488228       4488588       4488364       4488378     107.10327
+  10       1534752       1535000       1534896     1534897.2     68.014379
Difference at 95.0% confidence
	-2.95348e+06 +/- 84.2945
	-65.8029% +/- 0.00187806%
	(Student's t, pooled s = 89.7136)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_member_pointer_v.cc
x /tmp/tmp.Kdtg8sTlH9/total_mem_no_builtin.txt
+ /tmp/tmp.Kdtg8sTlH9/total_mem_builtin.txt
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
x  10          5526          5526          5526          5526             0
+  10          1703          1703          1703          1703             0
Difference at 95.0% confidence
	-3823 +/- 0
	-69.182% +/- 0%
	(Student's t, pooled s = 0)
```

---

