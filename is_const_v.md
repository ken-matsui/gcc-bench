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

## Sat Oct 21 09:07:10 PM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_const_v.cc
x /tmp/tmp.shmGiKjlLP/time_no_builtin.txt
+ /tmp/tmp.shmGiKjlLP/time_builtin.txt
+----------------------------------------------------------------------+
|            +x   x                                                    |
|   +     ++ ** + x x +*                                              +|
||___________|M_A_M_A_________________|                                |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     3.0253811     3.1380586     3.0845513     3.0694214   0.036943147
+  10     2.9346009     3.6644088     3.0363344     3.1034796    0.20638017
No difference proven at 95.0% confidence
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_const_v.cc
x /tmp/tmp.shmGiKjlLP/peak_mem_no_builtin.txt
+ /tmp/tmp.shmGiKjlLP/peak_mem_builtin.txt
+----------------------------------------------------------------------+
|  +                                                                   |
|  +                                                                 x |
|  +                                                                xx |
| +++                                                               xx |
|++++                                                            x xxxx|
| |A|                                                              |AM||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10        910328        910704        910624      910573.6     108.24171
+  10        905228        905492        905404      905373.6     84.710225
Difference at 95.0% confidence
	-5200 +/- 91.32
	-0.571069% +/- 0.0100288%
	(Student's t, pooled s = 97.1908)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_const_v.cc
x /tmp/tmp.shmGiKjlLP/total_mem_no_builtin.txt
+ /tmp/tmp.shmGiKjlLP/total_mem_builtin.txt
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
x  10          1052          1052          1052          1052             0
+  10          1044          1044          1044          1044             0
Difference at 95.0% confidence
	-8 +/- 0
	-0.760456% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_const_v/time_no_builtin.txt
+ ./reports/built-ins/is_const_v/time_builtin.txt
+----------------------------------------------------------------------+
|x +  x       ++++    x+   +    +    +   x xx    x   x              + x|
|      |_____|_________M_A_________A_______|_____________|             |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     3.5120669      4.030555     3.8247304     3.7676719    0.16274897
+  10     3.5273867     4.0135123      3.677902     3.6938835    0.13430699
No difference proven at 95.0% confidence
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_const_v/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_const_v/peak_mem_builtin.txt
+----------------------------------------------------------------------+
| +                                                                    |
| ++                                                               xx x|
|+++                                                               xx x|
|++++                                                             xxx x|
||A|                                                               |A| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10        909988        910304        910108      910137.2     111.58733
+  10        904236        904496        904352      904351.2     84.175478
Difference at 95.0% confidence
	-5786 +/- 92.8662
	-0.635728% +/- 0.0102035%
	(Student's t, pooled s = 98.8363)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_const_v/total_mem_no_builtin.txt
+ ./reports/built-ins/is_const_v/total_mem_builtin.txt
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
x  10          1052          1052          1052          1052             0
+  10          1044          1044          1044          1044             0
Difference at 95.0% confidence
	-8 +/- 0
	-0.760456% +/- 0%
	(Student's t, pooled s = 0)
```

---

