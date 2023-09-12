## Tue Sep 12 12:24:33 AM PDT 2023

https://github.com/ken-matsui/gsoc23/blob/c61ab7b102f7a79b4a2a3563eac987773d1eb0db/is_member_object_pointer_v.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230912 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
26da1970a4011893cdf3f38793dc856e2a88be25
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
943edc3da96bc00296504fd4c9ccb8ffc7670375
5e6187bfdcaa720ee5ae89a37437826743867baf
```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_member_object_pointer_v.cc
x /tmp/tmp.jy2AHnMzdD/time_A.txt
+ /tmp/tmp.jy2AHnMzdD/time_B.txt
+----------------------------------------------------------------------+
|    +                                                                 |
|    +                                                                 |
|    +                                                                 |
|    +                                                         x       |
|+   ++                                                 x      x       |
|+   ++                                                 x   x xxx    xx|
|  |AM|                                                   |____A___|   |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     13.725107     15.422765      14.54268     14.531978    0.56302239
+  10     7.0670158     7.6375817     7.5416912     7.4665382    0.20676666
Difference at 95.0% confidence
	-7.06544 +/- 0.398496
	-48.6199% +/- 2.7422%
	(Student's t, pooled s = 0.424115)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_member_object_pointer_v.cc
x /tmp/tmp.jy2AHnMzdD/peak_mem_A.txt
+ /tmp/tmp.jy2AHnMzdD/peak_mem_B.txt
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
x  10       2535504       2535912       2535840       2535770     142.60123
+  10       1538556       1538864       1538740     1538726.4     100.68565
Difference at 95.0% confidence
	-997044 +/- 115.98
	-39.3192% +/- 0.00457374%
	(Student's t, pooled s = 123.436)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_member_object_pointer_v.cc
x /tmp/tmp.jy2AHnMzdD/total_mem_A.txt
+ /tmp/tmp.jy2AHnMzdD/total_mem_B.txt
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
x  10          2944          2944          2944          2944             0
+  10          1712          1712          1712          1712             0
Difference at 95.0% confidence
	-1232 +/- 0
	-41.8478% +/- 0%
	(Student's t, pooled s = 0)
```

---

