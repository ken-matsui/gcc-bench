## Wed Feb 28 07:36:32 AM PST 2024

### Time

```console
x ./reports/builtins/rank_v/time_no_builtin.txt
+ ./reports/builtins/rank_v/time_builtin.txt
+----------------------------------------------------------------------+
|++                                                                    |
|++  +                                                           x     |
|+++ + +                                              x    x    xxxxxxx|
||MA_|                                                      |____AM___||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     5.5542831     6.2000405     6.0564886     5.9881245    0.19425252
+  10     3.4695282     3.6902142      3.525185     3.5499136   0.073417389
Difference at 95.0% confidence
	-2.43821 +/- 0.137971
	-40.7174% +/- 2.30407%
	(Student's t, pooled s = 0.14684)
```

### Peak Memory Usage

```console
x ./reports/builtins/rank_v/peak_mem_no_builtin.txt
+ ./reports/builtins/rank_v/peak_mem_builtin.txt
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
x  10       1146524       1146888       1146680     1146677.6     111.27064
+  10        957760        958016        957872      957873.2     87.331806
Difference at 95.0% confidence
	-188804 +/- 93.9784
	-16.4653% +/- 0.00819571%
	(Student's t, pooled s = 100.02)
```

### Total Memory Usage

```console
x ./reports/builtins/rank_v/total_mem_no_builtin.txt
+ ./reports/builtins/rank_v/total_mem_builtin.txt
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
x  10          1447          1447          1447          1447             0
+  10          1114          1114          1114          1114             0
Difference at 95.0% confidence
	-333 +/- 0
	-23.0131% +/- 0%
	(Student's t, pooled s = 0)
```

---

