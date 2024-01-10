## Wed Jan 10 11:20:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_fundamental/time_no_builtin.txt
+ ./reports/builtins/is_fundamental/time_builtin.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                     |
|+                                                                     |
|+                                                                     |
|+                                                                     |
|+                                                                  x  |
|+                                                              x   xx |
|+++                                                            xxx xxx|
|A|                                                              |_AM| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     15.223089     16.168558     15.877673     15.734317    0.34068256
+  10     5.8335729     6.0650442     5.8807322     5.8941987   0.065081291
Difference at 95.0% confidence
	-9.84012 +/- 0.230441
	-62.5392% +/- 1.46457%
	(Student's t, pooled s = 0.245255)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_fundamental/peak_mem_no_builtin.txt
+ ./reports/builtins/is_fundamental/peak_mem_builtin.txt
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
x  10       2872952       2873256       2873064       2873082     97.328767
+  10       1450744       1451012       1450932     1450900.8     83.624559
Difference at 95.0% confidence
	-1.42218e+06 +/- 85.2549
	-49.5002% +/- 0.00296737%
	(Student's t, pooled s = 90.7358)
```

### Total Memory Usage

```console
x ./reports/builtins/is_fundamental/total_mem_no_builtin.txt
+ ./reports/builtins/is_fundamental/total_mem_builtin.txt
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
x  10          3661          3661          3661          3661             0
+  10          1707          1707          1707          1707             0
Difference at 95.0% confidence
	-1954 +/- 0
	-53.3734% +/- 0%
	(Student's t, pooled s = 0)
```

---

