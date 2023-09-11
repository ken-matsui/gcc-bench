## Mon Sep 11 03:01:25 PM PDT 2023

https://github.com/ken-matsui/gsoc23/blob/0bae68a58131f09448439d7c2dd797cc5f1b6e2c/is_unbounded_array_v.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230911 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
048927ed8561ca994ad853fe85ccf8c2ca07a8fe
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
08426ca311407480cc0e9061f3ad04fea0256074
da6e03cb8d82fdd83ba2d4bd8c663337d2d5b6be
```

### Time

```console
$ perf stat xg++ -c is_unbounded_array_v.cc
x /tmp/tmp.yvBjKceVlC/time_A.txt
+ /tmp/tmp.yvBjKceVlC/time_B.txt
+----------------------------------------------------------------------+
|     +                                                   x            |
|    ++++  +             xx     x         +           +x xx+  +    xx x|
||_________M______________A_______|________________|A_____M__________| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.9503798     5.1994249      5.132203     5.0967866   0.097071969
+  10     4.8355337     5.1542334     4.8728828     4.9541236    0.13874402
Difference at 95.0% confidence
	-0.142663 +/- 0.112502
	-2.79908% +/- 2.20732%
	(Student's t, pooled s = 0.119735)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_unbounded_array_v.cc
x /tmp/tmp.yvBjKceVlC/peak_mem_A.txt
+ /tmp/tmp.yvBjKceVlC/peak_mem_B.txt
+----------------------------------------------------------------------+
| +                                                                   x|
| +                                                                   x|
|++                                                                   x|
|++                                                                   x|
|++                                                                  xx|
|++                                                                  xx|
||A                                                                  |A|
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1150760       1150888       1150828       1150822     37.010509
+  10       1137876       1138116       1137992     1137971.2     71.598882
Difference at 95.0% confidence
	-12850.8 +/- 53.5494
	-1.11666% +/- 0.00465315%
	(Student's t, pooled s = 56.992)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_unbounded_array_v.cc
x /tmp/tmp.yvBjKceVlC/total_mem_A.txt
+ /tmp/tmp.yvBjKceVlC/total_mem_B.txt
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
x  10          1369          1369          1369          1369             0
+  10          1335          1335          1335          1335             0
Difference at 95.0% confidence
	-34 +/- 0
	-2.48356% +/- 0%
	(Student's t, pooled s = 0)
```

---
