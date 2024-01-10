## Wed Jan 10 11:20:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_arithmetic_v/time_no_builtin.txt
+ ./reports/builtins/is_arithmetic_v/time_builtin.txt
+----------------------------------------------------------------------+
| +                                                                    |
| +                                                                    |
| +                                                                 x  |
| +                                                                 x  |
|++                                                                 x  |
|++                                                               x x  |
|++                                                              xxxx x|
||A                                                               |AM| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10      12.30691     13.046256     12.716968     12.653584    0.20796761
+  10     3.1807219     3.3289197      3.278019     3.2653989   0.049012343
Difference at 95.0% confidence
	-9.38819 +/- 0.141958
	-74.1939% +/- 1.12188%
	(Student's t, pooled s = 0.151084)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_arithmetic_v/peak_mem_no_builtin.txt
+ ./reports/builtins/is_arithmetic_v/peak_mem_builtin.txt
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
x  10       2359528       2360084       2359820     2359768.4     201.04129
+  10        911680        911956        911716      911760.8     99.613475
Difference at 95.0% confidence
	-1.44801e+06 +/- 149.068
	-61.3623% +/- 0.00631706%
	(Student's t, pooled s = 158.651)
```

### Total Memory Usage

```console
x ./reports/builtins/is_arithmetic_v/total_mem_no_builtin.txt
+ ./reports/builtins/is_arithmetic_v/total_mem_builtin.txt
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
x  10          3005          3005          3005          3005             0
+  10          1056          1056          1056          1056             0
Difference at 95.0% confidence
	-1949 +/- 0
	-64.8586% +/- 0%
	(Student's t, pooled s = 0)
```

---

