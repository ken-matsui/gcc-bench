## Fri Jul 14 09:11:46 PM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/23fc89499ca5093d0e6404e4f0fe05fe55abb1e4/is_fundamental.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230709 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~1  # base commit
6404ccec9e4f794c88ea660a8b6f9224bcba0c96
```

```console
$ git log -n 1 --pretty=format:%H  # changes from the base
7976f3dfea017b10740de7af8011746c2c953e93
```

### Time

```console
$ perf stat xg++ -c is_fundamental.cc
x /tmp/tmp.XqsU1WqRA8/time_before.txt
+ /tmp/tmp.XqsU1WqRA8/time_after.txt
+----------------------------------------------------------------------+
|+                                                                x    |
|+                                                                x    |
|+ +                                                              x    |
|+ +                                                              x    |
|+ +                                                              x  xx|
|+ +                                                              x  xx|
|MA|                                                             |MA_| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.6113169     4.7258888     4.6199018       4.65111   0.047845565
+  10     2.8995079     2.9576735     2.9070222     2.9226708   0.025522971
Difference at 95.0% confidence
	-1.72844 +/- 0.0360284
	-37.1619% +/- 0.77462%
	(Student's t, pooled s = 0.0383446)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_fundamental.cc
x /tmp/tmp.XqsU1WqRA8/peak_mem_before.txt
+ /tmp/tmp.XqsU1WqRA8/peak_mem_after.txt
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
x  10       1355664       1356004       1355884     1355867.6     100.46027
+  10        956748        957012        956840      956844.4     72.552204
Difference at 95.0% confidence
	-399023 +/- 82.3316
	-29.4294% +/- 0.00607224%
	(Student's t, pooled s = 87.6245)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_fundamental.cc
x /tmp/tmp.XqsU1WqRA8/total_mem_before.txt
+ /tmp/tmp.XqsU1WqRA8/total_mem_after.txt
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
x  10          1591          1591          1591          1591             0
+  10          1122          1122          1122          1122             0
Difference at 95.0% confidence
	-469 +/- 0
	-29.4783% +/- 0%
	(Student's t, pooled s = 0)
```

---

