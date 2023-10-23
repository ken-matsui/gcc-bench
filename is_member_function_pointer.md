## Sat Oct 21 09:28:35 PM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_member_function_pointer.cc
x /tmp/tmp.LdgN1355ME/time_no_builtin.txt
+ /tmp/tmp.LdgN1355ME/time_builtin.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+ ++ +                                                            xx x|
|+ ++ ++                                                    xx  xx xx x|
||__A_|                                                        |__AM_| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     11.620972     12.606592     12.308325     12.199701    0.34567983
+  10     5.4506609     6.1017486     5.7478449     5.7223694    0.23030448
Difference at 95.0% confidence
	-6.47733 +/- 0.275972
	-53.0942% +/- 2.26212%
	(Student's t, pooled s = 0.293713)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_member_function_pointer.cc
x /tmp/tmp.LdgN1355ME/peak_mem_no_builtin.txt
+ /tmp/tmp.LdgN1355ME/peak_mem_builtin.txt
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
x  10       2532564       2533080       2532888     2532860.4      146.7206
+  10       1387580       1387900       1387816     1387780.8     99.004827
Difference at 95.0% confidence
	-1.14508e+06 +/- 117.598
	-45.209% +/- 0.00464288%
	(Student's t, pooled s = 125.158)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_member_function_pointer.cc
x /tmp/tmp.LdgN1355ME/total_mem_no_builtin.txt
+ /tmp/tmp.LdgN1355ME/total_mem_builtin.txt
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
x  10          3038          3038          3038          3038             0
+  10          1613          1613          1613          1613             0
Difference at 95.0% confidence
	-1425 +/- 0
	-46.9059% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_member_function_pointer/time_no_builtin.txt
+ ./reports/built-ins/is_member_function_pointer/time_builtin.txt
+----------------------------------------------------------------------+
|++++                                                           xx  x x|
|+++++  +                                                     x xx xx x|
||_A_|                                                          |_AM_| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     13.288512     14.156486     13.775392     13.732569    0.30261664
+  10     6.3350962     7.1361802     6.5828788     6.5973803    0.23744575
Difference at 95.0% confidence
	-7.13519 +/- 0.255561
	-51.9581% +/- 1.86098%
	(Student's t, pooled s = 0.27199)
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_member_function_pointer/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_member_function_pointer/peak_mem_builtin.txt
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
x  10       2531864       2532336       2532184     2532129.6      145.4886
+  10       1386784       1387320       1386956     1386979.2     155.72968
Difference at 95.0% confidence
	-1.14515e+06 +/- 141.593
	-45.2248% +/- 0.00559187%
	(Student's t, pooled s = 150.696)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_member_function_pointer/total_mem_no_builtin.txt
+ ./reports/built-ins/is_member_function_pointer/total_mem_builtin.txt
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
x  10          3038          3038          3038          3038             0
+  10          1613          1613          1613          1613             0
Difference at 95.0% confidence
	-1425 +/- 0
	-46.9059% +/- 0%
	(Student's t, pooled s = 0)
```

---

