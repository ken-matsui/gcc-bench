## Wed Jan 10 11:20:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_floating_point/time_no_builtin.txt
+ ./reports/builtins/is_floating_point/time_builtin.txt
+----------------------------------------------------------------------+
|   +                                                                  |
|  ++                                                      x         x |
|++++ ++ +                                        x    x   x xx   x  xx|
| |_A__|                                               |______A_____|  |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.8891086     5.2758131      5.115731     5.1171223    0.12694066
+  10     3.9208447     4.0784819     3.9820969     3.9841239   0.047845741
Difference at 95.0% confidence
	-1.133 +/- 0.0901306
	-22.1413% +/- 1.76135%
	(Student's t, pooled s = 0.0959248)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_floating_point/peak_mem_no_builtin.txt
+ ./reports/builtins/is_floating_point/peak_mem_builtin.txt
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
x  10       1360280       1360688       1360524     1360497.2      132.9334
+  10       1020468       1020720       1020612     1020603.2     85.910548
Difference at 95.0% confidence
	-339894 +/- 105.159
	-24.9831% +/- 0.00772945%
	(Student's t, pooled s = 111.919)
```

### Total Memory Usage

```console
x ./reports/builtins/is_floating_point/total_mem_no_builtin.txt
+ ./reports/builtins/is_floating_point/total_mem_builtin.txt
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
x  10          1559          1559          1559          1559             0
+  10          1209          1209          1209          1209             0
Difference at 95.0% confidence
	-350 +/- 0
	-22.4503% +/- 0%
	(Student's t, pooled s = 0)
```

---

