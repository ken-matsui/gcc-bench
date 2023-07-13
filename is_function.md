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

