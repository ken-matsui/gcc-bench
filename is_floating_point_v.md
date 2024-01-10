## Wed Jan 10 11:20:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_floating_point_v/time_no_builtin.txt
+ ./reports/builtins/is_floating_point_v/time_builtin.txt
+----------------------------------------------------------------------+
|  +                                                                 x |
| ++                                                                 x |
|+++                                                           x     x |
|++++                                                       x  x  x xxx|
||AM                                                           |___A_M||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     5.6382557     6.0346015     5.9971465     5.9055604    0.13911481
+  10     3.2019617     3.3064277     3.2666168     3.2526449   0.033995703
Difference at 95.0% confidence
	-2.65292 +/- 0.0951469
	-44.9223% +/- 1.61114%
	(Student's t, pooled s = 0.101264)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_floating_point_v/peak_mem_no_builtin.txt
+ ./reports/builtins/is_floating_point_v/peak_mem_builtin.txt
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
x  10       1448648       1449064       1448836     1448820.8     126.68491
+  10        912156        912456        912324      912316.8     104.47413
Difference at 95.0% confidence
	-536504 +/- 109.098
	-37.0304% +/- 0.00753014%
	(Student's t, pooled s = 116.112)
```

### Total Memory Usage

```console
x ./reports/builtins/is_floating_point_v/total_mem_no_builtin.txt
+ ./reports/builtins/is_floating_point_v/total_mem_builtin.txt
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
x  10          1659          1659          1659          1659             0
+  10          1057          1057          1057          1057             0
Difference at 95.0% confidence
	-602 +/- 0
	-36.2869% +/- 0%
	(Student's t, pooled s = 0)
```

---

