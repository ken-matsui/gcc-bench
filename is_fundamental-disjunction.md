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

