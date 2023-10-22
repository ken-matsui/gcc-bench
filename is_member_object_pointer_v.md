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

## Sat Oct 21 10:30:08 PM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_member_object_pointer_v.cc
x /tmp/tmp.4jNwK7938T/time_no_builtin.txt
+ /tmp/tmp.4jNwK7938T/time_builtin.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                     |
|+                                                                     |
|+                                                                     |
|++                                                               x    |
|++                                                               xxx  |
|++                                                              xxxxxx|
|A|                                                               |A_| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     32.807999     34.661151     33.453374      33.53208    0.59918445
+  10     7.1223124      7.430112      7.177147     7.2236858    0.11092963
Difference at 95.0% confidence
	-26.3084 +/- 0.40486
	-78.4574% +/- 1.20738%
	(Student's t, pooled s = 0.430887)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_member_object_pointer_v.cc
x /tmp/tmp.4jNwK7938T/peak_mem_no_builtin.txt
+ /tmp/tmp.4jNwK7938T/peak_mem_builtin.txt
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
x  10       5513656       5513880       5513848     5513775.6     97.332406
+  10       1540908       1541272       1541096     1541077.2     121.20946
Difference at 95.0% confidence
	-3.9727e+06 +/- 103.281
	-72.0504% +/- 0.00187315%
	(Student's t, pooled s = 109.921)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_member_object_pointer_v.cc
x /tmp/tmp.4jNwK7938T/total_mem_no_builtin.txt
+ /tmp/tmp.4jNwK7938T/total_mem_builtin.txt
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
x  10          6743          6743          6743          6743             0
+  10          1714          1714          1714          1714             0
Difference at 95.0% confidence
	-5029 +/- 0
	-74.581% +/- 0%
	(Student's t, pooled s = 0)
```

---

