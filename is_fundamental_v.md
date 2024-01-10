## Wed Jan 10 11:20:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_fundamental_v/time_no_builtin.txt
+ ./reports/builtins/is_fundamental_v/time_builtin.txt
+----------------------------------------------------------------------+
| +                                                                    |
|++                                                                    |
|++                                                               x    |
|++                                                               x  xx|
|+++                                                            x xxxxx|
||A                                                              |__A_||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     16.170021      17.02113     16.739339      16.66738    0.29850641
+  10     7.0548455     7.3059699     7.1867127     7.1682095   0.080668789
Difference at 95.0% confidence
	-9.49917 +/- 0.20544
	-56.9926% +/- 1.23259%
	(Student's t, pooled s = 0.218648)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_fundamental_v/peak_mem_no_builtin.txt
+ ./reports/builtins/is_fundamental_v/peak_mem_builtin.txt
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
x  10       2951996       2952556       2952240     2952232.4     151.05496
+  10       1496188       1496472       1496324     1496334.8     75.331565
Difference at 95.0% confidence
	-1.4559e+06 +/- 112.148
	-49.3151% +/- 0.00379875%
	(Student's t, pooled s = 119.358)
```

### Total Memory Usage

```console
x ./reports/builtins/is_fundamental_v/total_mem_no_builtin.txt
+ ./reports/builtins/is_fundamental_v/total_mem_builtin.txt
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
x  10          3752          3752          3752          3752             0
+  10          1730          1730          1730          1730             0
Difference at 95.0% confidence
	-2022 +/- 0
	-53.8913% +/- 0%
	(Student's t, pooled s = 0)
```

---

