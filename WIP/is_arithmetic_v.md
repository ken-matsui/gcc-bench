## Sun Jul  9 05:57:58 AM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/13815c0985c14a11e38fe00b2e67bbcad120f8d7/is_arithmetic.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230709 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
95b712928b479f7a65910cf1c550ed67b8976617
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
d7d77b2ae1c220bbaacaec96586f6af6e17fedd8
462eb9e7fec7bb4acb128a208af46759205436b0
```

### Time

```console
$ perf stat xg++ -c is_arithmetic.cc
x /tmp/tmp.ciheVSlXaZ/time_before.txt
+ /tmp/tmp.ciheVSlXaZ/time_after.txt
+----------------------------------------------------------------------+
| +                                                               x    |
|++                                                               x    |
|++                                                               x    |
|++                                                               x  x |
|+++                                                              x  xx|
||A                                                              |MA_| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.6313774     4.8061882     4.6518056     4.6857154    0.06922556
+  10     2.0715921     2.1603604     2.0946845     2.0962431   0.024843127
Difference at 95.0% confidence
	-2.58947 +/- 0.0488651
	-55.2631% +/- 1.04285%
	(Student's t, pooled s = 0.0520065)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_arithmetic.cc
x /tmp/tmp.ciheVSlXaZ/peak_mem_before.txt
+ /tmp/tmp.ciheVSlXaZ/peak_mem_after.txt
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
x  10       1387120       1387384       1387288       1387268     88.342767
+  10        849260        849592        849444      849422.8      91.25398
Difference at 95.0% confidence
	-537845 +/- 84.3853
	-38.7701% +/- 0.00608284%
	(Student's t, pooled s = 89.8102)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_arithmetic.cc
x /tmp/tmp.ciheVSlXaZ/total_mem_before.txt
+ /tmp/tmp.ciheVSlXaZ/total_mem_after.txt
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
x  10          1604          1604          1604          1604             0
+  10           954           954           954           954             0
Difference at 95.0% confidence
	-650 +/- 0
	-40.5237% +/- 0%
	(Student's t, pooled s = 0)
```

---

