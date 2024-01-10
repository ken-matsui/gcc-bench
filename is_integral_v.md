## Wed Jan 10 11:20:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_integral_v/time_no_builtin.txt
+ ./reports/builtins/is_integral_v/time_builtin.txt
+----------------------------------------------------------------------+
| +                                                                    |
| +                                                                x   |
| +                                                                x   |
| +                                                                x   |
| + +                                                              xx  |
|++++                                                     x        xxxx|
||A|                                                            |__A__||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     5.6126365     6.0982797     6.0052901     5.9796576    0.13509767
+  10     3.2444016      3.371248     3.2868353     3.2943838   0.039824594
Difference at 95.0% confidence
	-2.68527 +/- 0.0935768
	-44.9068% +/- 1.56492%
	(Student's t, pooled s = 0.0995926)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_integral_v/peak_mem_no_builtin.txt
+ ./reports/builtins/is_integral_v/peak_mem_builtin.txt
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
x  10       1448100       1448472       1448196       1448222     108.96279
+  10        911516        911892        911712      911714.4     108.70061
Difference at 95.0% confidence
	-536508 +/- 102.258
	-37.046% +/- 0.00706093%
	(Student's t, pooled s = 108.832)
```

### Total Memory Usage

```console
x ./reports/builtins/is_integral_v/total_mem_no_builtin.txt
+ ./reports/builtins/is_integral_v/total_mem_builtin.txt
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
x  10          1658          1658          1658          1658             0
+  10          1056          1056          1056          1056             0
Difference at 95.0% confidence
	-602 +/- 0
	-36.3088% +/- 0%
	(Student's t, pooled s = 0)
```

---

