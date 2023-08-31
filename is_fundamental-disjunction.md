## Mon Jul 17 10:59:37 PM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/e62724ed4b900f218fc2871ed365b2e9b646dce9/is_fundamental-disjunction.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230709 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~0  # base commit
47ff88733d14eca8c666929421b6c1cf5de9cb48
```

```console
$ git log -n 0 --pretty=format:%H  # changes from the base

```

### Time

```console
$ perf stat xg++ -c is_fundamental-disjunction.cc
x /tmp/tmp.mkQHLsY3Ne/time_before.txt
+ /tmp/tmp.mkQHLsY3Ne/time_after.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+ +                                                               x x |
|+ +                                                              xx x |
|+++++                                                            xxxxx|
||_A|                                                              |A| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.2584788     4.3387018     4.2880514     4.2939221   0.029381724
+  10     2.8745783     2.9492243     2.9213327     2.9075413   0.026533257
Difference at 95.0% confidence
	-1.38638 +/- 0.0263028
	-32.2871% +/- 0.612559%
	(Student's t, pooled s = 0.0279937)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_fundamental-disjunction.cc
x /tmp/tmp.mkQHLsY3Ne/peak_mem_before.txt
+ /tmp/tmp.mkQHLsY3Ne/peak_mem_after.txt
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
x  10       1173988       1174256       1174116     1174097.6     99.191398
+  10        956688        956984        956840      956806.4     88.948425
Difference at 95.0% confidence
	-217291 +/- 88.5186
	-18.5071% +/- 0.00753929%
	(Student's t, pooled s = 94.2092)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_fundamental-disjunction.cc
x /tmp/tmp.mkQHLsY3Ne/total_mem_before.txt
+ /tmp/tmp.mkQHLsY3Ne/total_mem_after.txt
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
x  10          1406          1406          1406          1406             0
+  10          1122          1122          1122          1122             0
Difference at 95.0% confidence
	-284 +/- 0
	-20.1991% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Thu Aug 31 07:51:27 AM PDT 2023

https://github.com/ken-matsui/gsoc23/blob/d54c0518c2e9171c815e7550a9be0151b706d20a/is_fundamental-disjunction.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230709 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~4  # base commit
95b712928b479f7a65910cf1c550ed67b8976617
```

```console
$ git log -n 4 --pretty=format:%H  # changes from the base
69df6524815e5d07cc4f091b88ff4dd230e1f18c
ba58a14901a05a007f0fdf6ca74ffed82eef236e
dc0675eb9805eceefd5303b16fd02166045251ac
ba56ff423b098e2e473449edf82892c7134dc33c
```

### Time

```console
$ perf stat xg++ -c is_fundamental-disjunction.cc
x /tmp/tmp.bYzMmV1aG4/time_before.txt
+ /tmp/tmp.bYzMmV1aG4/time_after.txt
+----------------------------------------------------------------------+
|  +                                                        x          |
| ++                                                        x       x  |
| ++                                                        x      xx  |
| ++      +++                                               x      xx x|
||_M_A___|                                                   |___A_M_| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     3.7683339     3.9166941     3.8776492     3.8411126   0.061743645
+  10     2.8977091     3.0393896     2.9081901     2.9425434   0.061104622
Difference at 95.0% confidence
	-0.898569 +/- 0.0577146
	-23.3935% +/- 1.50255%
	(Student's t, pooled s = 0.061425)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_fundamental-disjunction.cc
x /tmp/tmp.bYzMmV1aG4/peak_mem_before.txt
+ /tmp/tmp.bYzMmV1aG4/peak_mem_after.txt
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
x  10       1065656       1065932       1065852     1065833.2      95.87121
+  10        955944        956244        956212      956142.8     98.991357
Difference at 95.0% confidence
	-109690 +/- 91.5578
	-10.2915% +/- 0.00859025%
	(Student's t, pooled s = 97.4438)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_fundamental-disjunction.cc
x /tmp/tmp.bYzMmV1aG4/total_mem_before.txt
+ /tmp/tmp.bYzMmV1aG4/total_mem_after.txt
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
x  10          1311          1311          1311          1311             0
+  10          1122          1122          1122          1122             0
Difference at 95.0% confidence
	-189 +/- 0
	-14.4165% +/- 0%
	(Student's t, pooled s = 0)
```

---
