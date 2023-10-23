## Sat Oct 21 09:59:07 PM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_member_object_pointer.cc
x /tmp/tmp.cQ3oaFE3Ta/time_no_builtin.txt
+ /tmp/tmp.cQ3oaFE3Ta/time_builtin.txt
+----------------------------------------------------------------------+
|+                                                                   x |
|++                                                                  x |
|++                                                             x    x |
|+++++                                                          x x xxx|
||A_|                                                            |__AM||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     26.831152     28.324906     28.207873     27.834738     0.6025158
+  10     10.008676      10.97794     10.369352     10.353557    0.33067223
Difference at 95.0% confidence
	-17.4812 +/- 0.456633
	-62.8035% +/- 1.64051%
	(Student's t, pooled s = 0.485988)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_member_object_pointer.cc
x /tmp/tmp.cQ3oaFE3Ta/peak_mem_no_builtin.txt
+ /tmp/tmp.cQ3oaFE3Ta/peak_mem_builtin.txt
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
x  10       5067092       5067584       5067296     5067294.4     127.37626
+  10       2152848       2153140       2153020     2152994.8     117.87828
Difference at 95.0% confidence
	-2.9143e+06 +/- 115.306
	-57.5119% +/- 0.0022755%
	(Student's t, pooled s = 122.719)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_member_object_pointer.cc
x /tmp/tmp.cQ3oaFE3Ta/total_mem_no_builtin.txt
+ /tmp/tmp.cQ3oaFE3Ta/total_mem_builtin.txt
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
x  10          6263          6263          6263          6263             0
+  10          2514          2514          2514          2514             0
Difference at 95.0% confidence
	-3749 +/- 0
	-59.8595% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_member_object_pointer/time_no_builtin.txt
+ ./reports/built-ins/is_member_object_pointer/time_builtin.txt
+----------------------------------------------------------------------+
|+   +                                                     x           |
|++++++++                                            x xxx xx    x   xx|
| |_AM_|                                               |___MA_____|    |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     27.268067     32.580839      29.19491     29.532237     1.8107323
+  10      10.73341     12.859358     12.013739     11.745601    0.74341728
Difference at 95.0% confidence
	-17.7866 +/- 1.30049
	-60.2279% +/- 4.40362%
	(Student's t, pooled s = 1.38409)
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_member_object_pointer/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_member_object_pointer/peak_mem_builtin.txt
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
x  10       5066220       5066836       5066544       5066500     191.18345
+  10       2152064       2152248       2152140     2152134.8     62.312476
Difference at 95.0% confidence
	-2.91437e+06 +/- 133.598
	-57.5223% +/- 0.00263688%
	(Student's t, pooled s = 142.186)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_member_object_pointer/total_mem_no_builtin.txt
+ ./reports/built-ins/is_member_object_pointer/total_mem_builtin.txt
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
x  10          6262          6262          6262          6262             0
+  10          2513          2513          2513          2513             0
Difference at 95.0% confidence
	-3749 +/- 0
	-59.8691% +/- 0%
	(Student's t, pooled s = 0)
```

---

