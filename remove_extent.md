## Wed Feb 28 06:30:21 AM PST 2024

### Time

```console
x ./reports/builtins/remove_extent/time_no_builtin.txt
+ ./reports/builtins/remove_extent/time_builtin.txt
+----------------------------------------------------------------------+
|   + +                                                              x |
|+ ++ ++ +  ++                                     xx  x    x x    xxxx|
|  |__MA___|                                           |______A____M__||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     5.4737016     5.7437724     5.7012583      5.632036    0.10792236
+  10     4.7383485      4.909582     4.8179486     4.8205241   0.056338785
Difference at 95.0% confidence
	-0.811512 +/- 0.0808852
	-14.4089% +/- 1.43616%
	(Student's t, pooled s = 0.0860851)
```

### Peak Memory Usage

```console
x ./reports/builtins/remove_extent/peak_mem_no_builtin.txt
+ ./reports/builtins/remove_extent/peak_mem_builtin.txt
+----------------------------------------------------------------------+
|++                                                                   x|
|++                                                                  xx|
|++                                                                  xx|
|++                                                                  xx|
|++                                                                  xx|
|AM                                                                  |A|
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1221128       1221476       1221252     1221250.4     107.41736
+  10       1187880       1188172       1188132     1188052.4     111.78471
Difference at 95.0% confidence
	-33198 +/- 103.001
	-2.71836% +/- 0.00843407%
	(Student's t, pooled s = 109.623)
```

### Total Memory Usage

```console
x ./reports/builtins/remove_extent/total_mem_no_builtin.txt
+ ./reports/builtins/remove_extent/total_mem_builtin.txt
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
x  10          1540          1540          1540          1540             0
+  10          1388          1388          1388          1388             0
Difference at 95.0% confidence
	-152 +/- 0
	-9.87013% +/- 0%
	(Student's t, pooled s = 0)
```

---

