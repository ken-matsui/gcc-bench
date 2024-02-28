## Wed Feb 28 11:10:01 AM PST 2024

### Time

```console
x ./reports/builtins/is_invocable/time_no_builtin.txt
+ ./reports/builtins/is_invocable/time_builtin.txt
+----------------------------------------------------------------------+
|+                                                                  x  |
|+                                                                  x  |
|+  +                                                          x    x  |
|++ +                                                          x    x  |
|++ +                                                          xx   x x|
||A|                                                            |_A_M| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     23.924572     25.513698     25.050352     24.677978    0.61542679
+  10     9.9701632     10.583014     10.016475     10.159747    0.25791813
Difference at 95.0% confidence
	-14.5182 +/- 0.443342
	-58.8307% +/- 1.79651%
	(Student's t, pooled s = 0.471843)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_invocable/peak_mem_no_builtin.txt
+ ./reports/builtins/is_invocable/peak_mem_builtin.txt
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
x  10       3957188       3957416       3957272       3957278     77.591523
+  10       1602748       1602936       1602832     1602833.2     63.078084
Difference at 95.0% confidence
	-2.35444e+06 +/- 66.4371
	-59.4966% +/- 0.00167886%
	(Student's t, pooled s = 70.7082)
```

### Total Memory Usage

```console
x ./reports/builtins/is_invocable/total_mem_no_builtin.txt
+ ./reports/builtins/is_invocable/total_mem_builtin.txt
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
x  10          4076          4076          4076          4076             0
+  10          1635          1635          1635          1635             0
Difference at 95.0% confidence
	-2441 +/- 0
	-59.8871% +/- 0%
	(Student's t, pooled s = 0)
```

---

