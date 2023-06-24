## Sat Jun 24 04:48:15 AM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/9a0ae22762b6771b5539a8282e0c50469b04ad64/is_const.cc

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230624 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
ad5ab848cc487b3f7fd82c7cb3c408747bd10422
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
11652e3a2136732de2b7b8c83c2aeddf98d2c67c
d4a9d9e969967e02e561cf2257eec0153cb2b882
```

### Time

```console
$ perf stat xg++ -c is_const.cc
x /tmp/tmp.fHBeLn1UQY/time_before.txt
+ /tmp/tmp.fHBeLn1UQY/time_after.txt
+----------------------------------------------------------------------+
|    +  +              x       x                                       |
|    +  +++++          x       x    x    +* x                   x  x  x|
||________M____A_________|___|____________MA_________________|         |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     2.8369596     2.9768198     2.8944361     2.8967748   0.053125532
+  10     2.7842257     2.8932365     2.7976753     2.8137918   0.042003456
Difference at 95.0% confidence
	-0.082983 +/- 0.0449958
	-2.86467% +/- 1.55331%
	(Student's t, pooled s = 0.0478885)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_const.cc
x /tmp/tmp.fHBeLn1UQY/peak_mem_before.txt
+ /tmp/tmp.fHBeLn1UQY/peak_mem_after.txt
+----------------------------------------------------------------------+
| +                                                                  x |
| +                                                                  x |
|++                                                                 xx |
|+++                                                                xxx|
|+++                                                                xxx|
||A                                                                 |A||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10        910780        911140        911000      910982.8     103.81265
+  10        901164        901424        901280      901277.2       86.8214
Difference at 95.0% confidence
	-9705.6 +/- 89.9145
	-1.0654% +/- 0.00987006%
	(Student's t, pooled s = 95.6949)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_const.cc
x /tmp/tmp.fHBeLn1UQY/total_mem_before.txt
+ /tmp/tmp.fHBeLn1UQY/total_mem_after.txt
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
x  10          1047          1047          1047          1047             0
+  10          1030          1030          1030          1030             0
Difference at 95.0% confidence
	-17 +/- 0
	-1.62369% +/- 0%
	(Student's t, pooled s = 0)
```

---

