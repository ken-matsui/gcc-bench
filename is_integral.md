## Wed Jan 10 11:20:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_integral/time_no_builtin.txt
+ ./reports/builtins/is_integral/time_builtin.txt
+----------------------------------------------------------------------+
|  +                                                                   |
| ++                     x                                             |
| ++                    xx                                             |
|++++     +     x    x  xx  x           x                             x|
||_A__|       |__________M____A______________|                         |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.7619057     8.0277239     5.3008075     5.5923999    0.93169155
+  10      3.875781     4.3932147     3.9750223     3.9951787    0.14659613
Difference at 95.0% confidence
	-1.59722 +/- 0.626626
	-28.5606% +/- 11.205%
	(Student's t, pooled s = 0.666911)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_integral/peak_mem_no_builtin.txt
+ ./reports/builtins/is_integral/peak_mem_builtin.txt
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
x  10       1360296       1360680       1360556     1360523.2     132.82302
+  10       1020124       1020520       1020376     1020362.4     112.25685
Difference at 95.0% confidence
	-340161 +/- 115.543
	-25.0022% +/- 0.00849252%
	(Student's t, pooled s = 122.971)
```

### Total Memory Usage

```console
x ./reports/builtins/is_integral/total_mem_no_builtin.txt
+ ./reports/builtins/is_integral/total_mem_builtin.txt
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
x  10          1559          1559          1559          1559             0
+  10          1209          1209          1209          1209             0
Difference at 95.0% confidence
	-350 +/- 0
	-22.4503% +/- 0%
	(Student's t, pooled s = 0)
```

---

