## Wed Jan 10 11:20:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_compound/time_no_builtin.txt
+ ./reports/builtins/is_compound/time_builtin.txt
+----------------------------------------------------------------------+
|+   +                                                                 |
|+   +                                                                 |
|+   ++                                                      x    x   x|
|+   ++                                                     xxxx xx   x|
||__AM|                                                      |__AM__|  |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     16.018385     17.518409     16.778367     16.645981    0.55536209
+  10     6.8658884     7.6421038     7.4588667     7.2713566    0.33032114
Difference at 95.0% confidence
	-9.37462 +/- 0.429314
	-56.3176% +/- 2.57908%
	(Student's t, pooled s = 0.456913)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_compound/peak_mem_no_builtin.txt
+ ./reports/builtins/is_compound/peak_mem_builtin.txt
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
x  10       3069248       3069552       3069360     3069366.8     104.98762
+  10       1663544       1663900       1663668     1663684.4     113.91147
Difference at 95.0% confidence
	-1.40568e+06 +/- 102.924
	-45.7971% +/- 0.00335326%
	(Student's t, pooled s = 109.54)
```

### Total Memory Usage

```console
x ./reports/builtins/is_compound/total_mem_no_builtin.txt
+ ./reports/builtins/is_compound/total_mem_builtin.txt
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
x  10          3916          3916          3916          3916             0
+  10          1979          1979          1979          1979             0
Difference at 95.0% confidence
	-1937 +/- 0
	-49.4637% +/- 0%
	(Student's t, pooled s = 0)
```

---

