## Sun Oct 22 01:20:39 AM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_volatile.cc
x /tmp/tmp.iE92sC8zgQ/time_no_builtin.txt
+ /tmp/tmp.iE92sC8zgQ/time_builtin.txt
+----------------------------------------------------------------------+
|                                  +                                   |
|   x  +                           +                                   |
|  xxx ++++         xxx        x   + +x +                             x|
||______|____________MA____________M_|_____|                           |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     3.5655883      4.157077     3.7188424     3.7289819    0.18548644
+  10      3.597703     3.8859688     3.8457287     3.7337246    0.13234315
No difference proven at 95.0% confidence
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_volatile.cc
x /tmp/tmp.iE92sC8zgQ/peak_mem_no_builtin.txt
+ /tmp/tmp.iE92sC8zgQ/peak_mem_builtin.txt
+----------------------------------------------------------------------+
|  ++                                                               x  |
|  ++                                                               x  |
|  ++                                                               x  |
|+ ++ +                                                          xxxx x|
| |AM|                                                            |_A| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1024116       1024380       1024256       1024242     73.786479
+  10       1020536       1020812       1020676     1020669.2     68.974713
Difference at 95.0% confidence
	-3572.8 +/- 67.107
	-0.348824% +/- 0.00655187%
	(Student's t, pooled s = 71.4211)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_volatile.cc
x /tmp/tmp.iE92sC8zgQ/total_mem_no_builtin.txt
+ /tmp/tmp.iE92sC8zgQ/total_mem_builtin.txt
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
x  10          1210          1210          1210          1210             0
+  10          1207          1207          1207          1207             0
Difference at 95.0% confidence
	-3 +/- 0
	-0.247934% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_volatile/time_no_builtin.txt
+ ./reports/built-ins/is_volatile/time_builtin.txt
+----------------------------------------------------------------------+
|                                          +                          x|
|+                      x         + + +x + + +* xx +x          x x    x|
|                       |_____________A____M________|A_____________|   |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.1318568     4.8803761     4.5869424     4.5940815    0.23967823
+  10     3.7503757     4.5708379      4.438126      4.352817     0.2273095
Difference at 95.0% confidence
	-0.241265 +/- 0.219467
	-5.25164% +/- 4.77716%
	(Student's t, pooled s = 0.233576)
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_volatile/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_volatile/peak_mem_builtin.txt
+----------------------------------------------------------------------+
|+ ++                                                             x xxx|
|+++++++                                                         xxxxxx|
| |_A_|                                                           |_A_||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1023244       1023516       1023420     1023402.8     89.184951
+  10       1019804       1020100       1019948       1019944     102.90017
Difference at 95.0% confidence
	-3458.8 +/- 90.4709
	-0.337971% +/- 0.00884021%
	(Student's t, pooled s = 96.2871)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_volatile/total_mem_no_builtin.txt
+ ./reports/built-ins/is_volatile/total_mem_builtin.txt
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
x  10          1210          1210          1210          1210             0
+  10          1207          1207          1207          1207             0
Difference at 95.0% confidence
	-3 +/- 0
	-0.247934% +/- 0%
	(Student's t, pooled s = 0)
```

---

