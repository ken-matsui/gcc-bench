## Wed Feb 28 07:00:23 AM PST 2024

### Time

```console
x ./reports/builtins/add_lvalue_reference_t/time_no_builtin.txt
+ ./reports/builtins/add_lvalue_reference_t/time_builtin.txt
+----------------------------------------------------------------------+
| +                                                                    |
| +                                                                    |
| +                    x                                               |
| +                    x                                               |
|+++++  +              x  x   x x       x x           x               x|
||MA_|               |__________M___A_______________|                  |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.8157242     7.5185312     5.3786008     5.6016222    0.89646239
+  10     3.5833506     3.9855029     3.6556789     3.7036438    0.12012932
Difference at 95.0% confidence
	-1.89798 +/- 0.600929
	-33.8827% +/- 10.7278%
	(Student's t, pooled s = 0.639561)
```

### Peak Memory Usage

```console
x ./reports/builtins/add_lvalue_reference_t/peak_mem_no_builtin.txt
+ ./reports/builtins/add_lvalue_reference_t/peak_mem_builtin.txt
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
x  10       1348016       1348368       1348164     1348178.8     108.81258
+  10       1011960       1012236       1012108     1012088.8     98.048514
Difference at 95.0% confidence
	-336090 +/- 97.3144
	-24.9292% +/- 0.00721821%
	(Student's t, pooled s = 103.57)
```

### Total Memory Usage

```console
x ./reports/builtins/add_lvalue_reference_t/total_mem_no_builtin.txt
+ ./reports/builtins/add_lvalue_reference_t/total_mem_builtin.txt
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
x  10          1561          1561          1561          1561             0
+  10          1166          1166          1166          1166             0
Difference at 95.0% confidence
	-395 +/- 0
	-25.3043% +/- 0%
	(Student's t, pooled s = 0)
```

---

