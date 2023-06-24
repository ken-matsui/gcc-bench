## Sat Jun 24 07:06:30 AM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/6b5e8d73aea95b4c2b3b7d2d39ee40e1488a5473/is_array.cc

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230624 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
31b7659995caccca626709ecb634339f75980ff2
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
1d8c22aa3e1fba66f39b7301bc8667a303f985bb
d473102e3c9c2d24682e564a5219f79dbd70db8b
```

### Time

```console
$ perf stat xg++ -c is_array.cc
x /tmp/tmp.kxsLEkDQ2k/time_before.txt
+ /tmp/tmp.kxsLEkDQ2k/time_after.txt
+----------------------------------------------------------------------+
|  +                                                                   |
| +++         +                                       x           x    |
| +++         ++                                     xx xx        xxx x|
||__M_A_____|                                         |______A____M_|  |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     2.8377872     2.9796726      2.950709     2.9065102   0.056136848
+  10     2.4202279     2.5236702     2.4333184     2.4556808   0.044907731
Difference at 95.0% confidence
	-0.450829 +/- 0.0477628
	-15.511% +/- 1.6433%
	(Student's t, pooled s = 0.0508333)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_array.cc
x /tmp/tmp.kxsLEkDQ2k/peak_mem_before.txt
+ /tmp/tmp.kxsLEkDQ2k/peak_mem_after.txt
+----------------------------------------------------------------------+
|        x                                                     +   +   |
|       xx   x                                                 ++  +   |
|x   x  xx x x                                              +  ++  +  +|
|    |___A__|                                                 |_MA__|  |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10        894668        895004        894888      894880.8     99.094567
+  10        896320        896584        896420      896437.2     81.060745
Difference at 95.0% confidence
	1556.4 +/- 85.0596
	0.173923% +/- 0.00950513%
	(Student's t, pooled s = 90.5278)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_array.cc
x /tmp/tmp.kxsLEkDQ2k/total_mem_before.txt
+ /tmp/tmp.kxsLEkDQ2k/total_mem_after.txt
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
x  10          1080          1080          1080          1080             0
+  10          1013          1013          1013          1013             0
Difference at 95.0% confidence
	-67 +/- 0
	-6.2037% +/- 0%
	(Student's t, pooled s = 0)
```

---

