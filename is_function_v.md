## Wed Jul 12 07:25:10 PM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/83ccb4c733e6723761d736b6c17827d7614da3f5/is_function.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230610 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~5  # base commit
a53a83b63b4c4b3f7d2d997b3a26d82abb883f9a
```

```console
$ git log -n 5 --pretty=format:%H  # changes from the base
a0cc4677880503a6bc55a11747cd9cdb6a3ee433
5e2fd5ec13dda849aa790b2f7846b0530293f117
88fd0a7aaf4b783cf4571b9dfa57acd5e7b97ce2
4efd3179279f1a3c5295927426e7ac939400c577
e742a22609fd9b8131e41e7b4c8aaad9a9404898
```

### Time

```console
$ perf stat xg++ -c is_function.cc
x /tmp/tmp.A1kXBw0wku/time_before.txt
+ /tmp/tmp.A1kXBw0wku/time_after.txt
+----------------------------------------------------------------------+
|      +                                                               |
|      +                                                      x        |
|++    +                                                      x x     x|
|+++   + +                                                    xxx  x xx|
| |__A_M|                                                     |_MA___| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.4153194     4.5480166     4.4540415     4.4737739    0.05328236
+  10     3.4622855     3.5804473     3.5503822     3.5175129   0.047061812
Difference at 95.0% confidence
	-0.956261 +/- 0.047232
	-21.3748% +/- 1.05575%
	(Student's t, pooled s = 0.0502684)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_function.cc
x /tmp/tmp.A1kXBw0wku/peak_mem_before.txt
+ /tmp/tmp.A1kXBw0wku/peak_mem_after.txt
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
x  10       1093056       1093324       1093188     1093199.6     90.851772
+  10        973136        973604        973400      973363.2     141.67004
Difference at 95.0% confidence
	-119836 +/- 111.817
	-10.962% +/- 0.0102284%
	(Student's t, pooled s = 119.005)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_function.cc
x /tmp/tmp.A1kXBw0wku/total_mem_before.txt
+ /tmp/tmp.A1kXBw0wku/total_mem_after.txt
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
x  10          1293          1293          1293          1293             0
+  10          1127          1127          1127          1127             0
Difference at 95.0% confidence
	-166 +/- 0
	-12.8384% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sat Oct 21 09:21:07 PM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_function_v.cc
x /tmp/tmp.pikFbGZUHI/time_no_builtin.txt
+ /tmp/tmp.pikFbGZUHI/time_builtin.txt
+----------------------------------------------------------------------+
|           +                               x          x               |
|++    +++++++                              x   xx     xxx        x   x|
|   |____AM__|                                |_______AM_______|       |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.5059371       4.97961     4.7021162     4.6921538    0.15706799
+  10     3.7080168     3.9268816      3.877854     3.8472117   0.079449808
Difference at 95.0% confidence
	-0.844942 +/- 0.116946
	-18.0076% +/- 2.49237%
	(Student's t, pooled s = 0.124464)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_function_v.cc
x /tmp/tmp.pikFbGZUHI/peak_mem_no_builtin.txt
+ /tmp/tmp.pikFbGZUHI/peak_mem_builtin.txt
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
x  10       1081776       1082304       1082084     1082087.6      174.5949
+  10        974164        974344        974288      974273.2     56.664313
Difference at 95.0% confidence
	-107814 +/- 121.956
	-9.96356% +/- 0.0112705%
	(Student's t, pooled s = 129.796)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_function_v.cc
x /tmp/tmp.pikFbGZUHI/total_mem_no_builtin.txt
+ /tmp/tmp.pikFbGZUHI/total_mem_builtin.txt
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
x  10          1269          1269          1269          1269             0
+  10          1138          1138          1138          1138             0
Difference at 95.0% confidence
	-131 +/- 0
	-10.3231% +/- 0%
	(Student's t, pooled s = 0)
```

---

