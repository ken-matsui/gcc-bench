## Sun Oct 22 12:57:13 AM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_unbounded_array.cc
x /tmp/tmp.OaggHayRuJ/time_no_builtin.txt
+ /tmp/tmp.OaggHayRuJ/time_builtin.txt
+----------------------------------------------------------------------+
|       +                                                              |
|     +++      x                                                       |
|     +++    x x         x     x  xx   +++    x               x       x|
||______M______|_A_______________|MA__________________|                |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     9.4202467     10.445237     9.8050278     9.8097176    0.35473398
+  10     9.2891291     9.9230718     9.3204976     9.4893542     0.2867026
Difference at 95.0% confidence
	-0.320363 +/- 0.303036
	-3.26578% +/- 3.08914%
	(Student's t, pooled s = 0.322517)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_unbounded_array.cc
x /tmp/tmp.OaggHayRuJ/peak_mem_no_builtin.txt
+ /tmp/tmp.OaggHayRuJ/peak_mem_builtin.txt
+----------------------------------------------------------------------+
| +                                                                  x |
| +                                                                  xx|
| ++                                                                 xx|
|+++                                                                 xx|
|+++                                                                xxx|
||A|                                                                 A||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1825260       1825544       1825452     1825416.4     100.74302
+  10       1814164       1814520       1814352     1814344.8     113.93253
Difference at 95.0% confidence
	-11071.6 +/- 101.044
	-0.606525% +/- 0.00553541%
	(Student's t, pooled s = 107.54)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_unbounded_array.cc
x /tmp/tmp.OaggHayRuJ/total_mem_no_builtin.txt
+ /tmp/tmp.OaggHayRuJ/total_mem_builtin.txt
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
x  10          2179          2179          2179          2179             0
+  10          2145          2145          2145          2145             0
Difference at 95.0% confidence
	-34 +/- 0
	-1.56035% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_unbounded_array/time_no_builtin.txt
+ ./reports/built-ins/is_unbounded_array/time_builtin.txt
+----------------------------------------------------------------------+
|+ +     +            + +            +   +   x   x  x x   x* x +x + x x|
|       |________________________A___M____________|______|AM______|    |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     11.206138     11.937452     11.604629     11.582932    0.23467126
+  10     9.9328352     11.835372     10.984175       10.8494    0.71663665
Difference at 95.0% confidence
	-0.733532 +/- 0.501008
	-6.33287% +/- 4.32539%
	(Student's t, pooled s = 0.533216)
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_unbounded_array/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_unbounded_array/peak_mem_builtin.txt
+----------------------------------------------------------------------+
|+++                                                                x  |
|+++                                                                xxx|
|++++                                                              xxxx|
||A|                                                                MA |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1824344       1824796       1824532       1824550     142.97475
+  10       1813368       1813792       1813592     1813557.2      147.1634
Difference at 95.0% confidence
	-10992.8 +/- 136.32
	-0.602494% +/- 0.00747146%
	(Student's t, pooled s = 145.084)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_unbounded_array/total_mem_no_builtin.txt
+ ./reports/built-ins/is_unbounded_array/total_mem_builtin.txt
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
x  10          2179          2179          2179          2179             0
+  10          2145          2145          2145          2145             0
Difference at 95.0% confidence
	-34 +/- 0
	-1.56035% +/- 0%
	(Student's t, pooled s = 0)
```

---

