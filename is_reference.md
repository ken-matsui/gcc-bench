## Sun Oct 22 12:29:24 AM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_reference.cc
x /tmp/tmp.hGZeNuBGTH/time_no_builtin.txt
+ /tmp/tmp.hGZeNuBGTH/time_builtin.txt
+----------------------------------------------------------------------+
|        +                                                             |
|     +  +      x                              x                       |
|     +  +     *x+x        x               ++ xx  x           x       +|
||_____________M|______A__________A__________|M_____|                  |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     5.0805993     5.4063435     5.2944328     5.2138544    0.12280612
+  10     5.0199095     5.4592584     5.0823371     5.1357095    0.14967194
No difference proven at 95.0% confidence
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_reference.cc
x /tmp/tmp.hGZeNuBGTH/peak_mem_no_builtin.txt
+ /tmp/tmp.hGZeNuBGTH/peak_mem_builtin.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                    x|
|+                                                                    x|
|+                                                                   xx|
|++                                                                  xx|
|++                                                                  xx|
|++                                                                  xx|
|A|                                                                  |A|
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1357908       1358148       1358092     1358030.4     109.88802
+  10       1330980       1331272       1331124     1331121.6     105.27762
Difference at 95.0% confidence
	-26908.8 +/- 101.108
	-1.98146% +/- 0.00744516%
	(Student's t, pooled s = 107.608)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_reference.cc
x /tmp/tmp.hGZeNuBGTH/total_mem_no_builtin.txt
+ /tmp/tmp.hGZeNuBGTH/total_mem_builtin.txt
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
x  10          1589          1589          1589          1589             0
+  10          1545          1545          1545          1545             0
Difference at 95.0% confidence
	-44 +/- 0
	-2.76904% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_reference/time_no_builtin.txt
+ ./reports/built-ins/is_reference/time_builtin.txt
+----------------------------------------------------------------------+
|       +                                        x                     |
|+     ++  +        +    x    + x  +     x x x   xx x             ++  x|
||__________________M____A________|___________A__|________|            |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     6.1490514     6.6785764     6.4289756     6.3902645    0.14289671
+  10     5.8614902     6.6381519     6.0892083     6.1498224    0.28579289
Difference at 95.0% confidence
	-0.240442 +/- 0.212292
	-3.76263% +/- 3.32211%
	(Student's t, pooled s = 0.225939)
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_reference/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_reference/peak_mem_builtin.txt
+----------------------------------------------------------------------+
| +                                                                   x|
| +                                                                   x|
| +                                                                   x|
| +                                                                   x|
|++                                                                  xx|
|++                                                                  xx|
|++                                                                  xx|
||A                                                                  |A|
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1356972       1357352       1357260     1357189.2     155.88087
+  10       1330040       1330492       1330320       1330298     141.61293
Difference at 95.0% confidence
	-26891.2 +/- 139.923
	-1.98139% +/- 0.0103097%
	(Student's t, pooled s = 148.918)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_reference/total_mem_no_builtin.txt
+ ./reports/built-ins/is_reference/total_mem_builtin.txt
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
x  10          1588          1588          1588          1588             0
+  10          1545          1545          1545          1545             0
Difference at 95.0% confidence
	-43 +/- 0
	-2.70781% +/- 0%
	(Student's t, pooled s = 0)
```

---

