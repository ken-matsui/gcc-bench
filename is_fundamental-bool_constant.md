## Fri Jul 14 09:42:37 PM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/5035eb29421eefd2b9a7fe4c44fe4180cf30084c/is_fundamental-bool_constant.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230715 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~0  # base commit
18dac101678b8c0aed4bd995351e47f26cd54dec
```

```console
$ git log -n 0 --pretty=format:%H  # changes from the base

```

### Time

```console
$ perf stat xg++ -c is_fundamental-bool_constant.cc
x /tmp/tmp.SoRFMliSZu/time_before.txt
+ /tmp/tmp.SoRFMliSZu/time_after.txt
+----------------------------------------------------------------------+
|   ++                                                               x |
|   ++                                                               x |
|   ++                                                           x   x |
|+ +++                                                         xxx   xx|
|  |A|                                                           |_A_M||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     6.8642611     7.0781259     7.0467373     6.9950245   0.081173879
+  10     4.9154266     5.0429495     5.0236199     5.0090844    0.03968254
Difference at 95.0% confidence
	-1.98594 +/- 0.0600309
	-28.3908% +/- 0.858194%
	(Student's t, pooled s = 0.0638902)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_fundamental-bool_constant.cc
x /tmp/tmp.SoRFMliSZu/peak_mem_before.txt
+ /tmp/tmp.SoRFMliSZu/peak_mem_after.txt
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
x  10       1732064       1732272       1732148     1732165.2     69.718164
+  10       1410900       1411132       1411008     1411016.4     86.604079
Difference at 95.0% confidence
	-321149 +/- 73.8671
	-18.5403% +/- 0.00426444%
	(Student's t, pooled s = 78.6158)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_fundamental-bool_constant.cc
x /tmp/tmp.SoRFMliSZu/total_mem_before.txt
+ /tmp/tmp.SoRFMliSZu/total_mem_after.txt
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
x  10          2095          2095          2095          2095             0
+  10          1678          1678          1678          1678             0
Difference at 95.0% confidence
	-417 +/- 0
	-19.9045% +/- 0%
	(Student's t, pooled s = 0)
```

---

