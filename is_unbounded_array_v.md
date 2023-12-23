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
## Sun Oct 22 01:12:23 AM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_unbounded_array_v.cc
x /tmp/tmp.oCe0BzTXa0/time_no_builtin.txt
+ /tmp/tmp.oCe0BzTXa0/time_builtin.txt
+----------------------------------------------------------------------+
|      +                x                                              |
|  +++ +     +  x xx    x           +        +       +    x+x x       x|
||___________M__|______AM_____________A_______|____________|           |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     5.1385485     5.5765146      5.208049     5.3142596    0.17719252
+  10     5.0362949     5.4911015     5.1182503     5.2000873    0.18129655
No difference proven at 95.0% confidence
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_unbounded_array_v.cc
x /tmp/tmp.oCe0BzTXa0/peak_mem_no_builtin.txt
+ /tmp/tmp.oCe0BzTXa0/peak_mem_builtin.txt
+----------------------------------------------------------------------+
| +                                                                  x |
| +                                                                  x |
| +                                                                  xx|
| +                                                                  xx|
|+++                                                                 xx|
|+++                                                                 xx|
||A|                                                                 A||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1156472       1156748       1156628     1156607.2     98.932974
+  10       1143776       1144148       1143952     1143952.4       118.576
Difference at 95.0% confidence
	-12654.8 +/- 102.601
	-1.09413% +/- 0.00887087%
	(Student's t, pooled s = 109.197)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_unbounded_array_v.cc
x /tmp/tmp.oCe0BzTXa0/total_mem_no_builtin.txt
+ /tmp/tmp.oCe0BzTXa0/total_mem_builtin.txt
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
x  10          1384          1384          1384          1384             0
+  10          1350          1350          1350          1350             0
Difference at 95.0% confidence
	-34 +/- 0
	-2.45665% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_unbounded_array_v/time_no_builtin.txt
+ ./reports/built-ins/is_unbounded_array_v/time_builtin.txt
+----------------------------------------------------------------------+
|                                           + x                        |
|x                 +  x +      +  xx x+     ++x +     xx +      +     x|
|                    |_____|____________AA__M_M_________|__|           |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     5.7446241     6.6997584     6.3638928     6.2827713    0.26603871
+  10     5.9903458     6.6227069     6.3431399     6.3041859    0.19581215
No difference proven at 95.0% confidence
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_unbounded_array_v/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_unbounded_array_v/peak_mem_builtin.txt
+----------------------------------------------------------------------+
|  +                                                                  x|
| ++                                                                  x|
| +++                                                                xx|
|++++                                                               xxx|
| |A                                                                 |A|
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1155588       1155868       1155816     1155789.2     83.651127
+  10       1142964       1143456       1143308       1143268     140.08252
Difference at 95.0% confidence
	-12521.2 +/- 108.401
	-1.08335% +/- 0.009379%
	(Student's t, pooled s = 115.37)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_unbounded_array_v/total_mem_no_builtin.txt
+ ./reports/built-ins/is_unbounded_array_v/total_mem_builtin.txt
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
x  10          1383          1383          1383          1383             0
+  10          1350          1350          1350          1350             0
Difference at 95.0% confidence
	-33 +/- 0
	-2.38612% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sat Dec 23 01:00:46 PM PST 2023

### Time

```console
x ./reports/builtins/is_unbounded_array_v/time_no_builtin.txt
+ ./reports/builtins/is_unbounded_array_v/time_builtin.txt
+----------------------------------------------------------------------+
|             +                  x                   x                 |
| +  + +      +  +    +x+        xx    x  x    +     x      x         +|
||_______________M____A______|_________MA__|________|                  |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     5.2044149     5.3629073     5.2714271     5.2792207   0.050184465
+  10     5.1105067      5.408215     5.1764473     5.2000193   0.091703503
Difference at 95.0% confidence
	-0.0792014 +/- 0.0694539
	-1.50025% +/- 1.31561%
	(Student's t, pooled s = 0.0739189)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_unbounded_array_v/peak_mem_no_builtin.txt
+ ./reports/builtins/is_unbounded_array_v/peak_mem_builtin.txt
+----------------------------------------------------------------------+
|  +                                                                 x |
|  +                                                                 x |
|  +                                                                 x |
|  +                                                                 xx|
| ++                                                                 xx|
|++++                                                                xx|
| |A                                                                 A||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1179588       1179840       1179712     1179710.4     89.882887
+  10       1166744       1167304       1167068       1167042     164.92692
Difference at 95.0% confidence
	-12668.4 +/- 124.793
	-1.07386% +/- 0.0105783%
	(Student's t, pooled s = 132.815)
```

### Total Memory Usage

```console
x ./reports/builtins/is_unbounded_array_v/total_mem_no_builtin.txt
+ ./reports/builtins/is_unbounded_array_v/total_mem_builtin.txt
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
x  10          1420          1420          1420          1420             0
+  10          1387          1387          1387          1387             0
Difference at 95.0% confidence
	-33 +/- 0
	-2.32394% +/- 0%
	(Student's t, pooled s = 0)
```

---

