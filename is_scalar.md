## Wed Jan 10 11:20:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_scalar/time_no_builtin.txt
+ ./reports/builtins/is_scalar/time_builtin.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                     |
|++                                                                    |
|++                                                                x  x|
|++                                                                x xx|
|++                                                              xxx xx|
|A|                                                               |_AM||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     39.758344     42.441266     41.721475     41.344636    0.91796568
+  10     5.0535677     5.5617051     5.2529028     5.2773872    0.20137729
Difference at 95.0% confidence
	-36.0672 +/- 0.624394
	-87.2356% +/- 1.51022%
	(Student's t, pooled s = 0.664535)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_scalar/peak_mem_no_builtin.txt
+ ./reports/builtins/is_scalar/peak_mem_builtin.txt
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
x  10       6367192       6367464       6367340       6367324     95.703245
+  10       1331284       1331664       1331520     1331481.2     120.70975
Difference at 95.0% confidence
	-5.03584e+06 +/- 102.347
	-79.0888% +/- 0.00160738%
	(Student's t, pooled s = 108.926)
```

### Total Memory Usage

```console
x ./reports/builtins/is_scalar/total_mem_no_builtin.txt
+ ./reports/builtins/is_scalar/total_mem_builtin.txt
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
x  10          8527          8527          8527          8527             0
+  10          1517          1517          1517          1517             0
Difference at 95.0% confidence
	-7010 +/- 0
	-82.2095% +/- 0%
	(Student's t, pooled s = 0)
```

---

