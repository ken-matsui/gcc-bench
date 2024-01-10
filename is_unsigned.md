## Wed Jan 10 11:20:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_unsigned/time_no_builtin.txt
+ ./reports/builtins/is_unsigned/time_builtin.txt
+----------------------------------------------------------------------+
|  +                                                                   |
|+++                                                               x   |
|+++                                                              xx  x|
|+++                                                            xxxx xx|
||A|                                                             |_A_| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     15.755533     16.799935     16.302327     16.276185    0.35468141
+  10     3.7075102     4.0983615     3.9865464     3.9198804    0.15482202
Difference at 95.0% confidence
	-12.3563 +/- 0.25712
	-75.9165% +/- 1.57973%
	(Student's t, pooled s = 0.27365)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_unsigned/peak_mem_no_builtin.txt
+ ./reports/builtins/is_unsigned/peak_mem_builtin.txt
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
x  10       2967628       2968024       2967876     2967874.8      113.4517
+  10       1019756       1020128       1020048     1019998.4     118.90164
Difference at 95.0% confidence
	-1.94788e+06 +/- 109.189
	-65.632% +/- 0.00367903%
	(Student's t, pooled s = 116.209)
```

### Total Memory Usage

```console
x ./reports/builtins/is_unsigned/total_mem_no_builtin.txt
+ ./reports/builtins/is_unsigned/total_mem_builtin.txt
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
x  10          3886          3886          3886          3886             0
+  10          1209          1209          1209          1209             0
Difference at 95.0% confidence
	-2677 +/- 0
	-68.8883% +/- 0%
	(Student's t, pooled s = 0)
```

---

