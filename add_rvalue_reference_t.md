## Wed Feb 28 07:07:01 AM PST 2024

### Time

```console
x ./reports/builtins/add_rvalue_reference_t/time_no_builtin.txt
+ ./reports/builtins/add_rvalue_reference_t/time_builtin.txt
+----------------------------------------------------------------------+
| + +                                                   x x x         x|
|++++ +  ++  +                                         xx x x       x x|
||__MA___|                                             |____MA_____|   |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.1308645     4.3991223     4.2091127     4.2345177    0.10812079
+  10     3.1417098      3.358806     3.2028053     3.2216785   0.071523339
Difference at 95.0% confidence
	-1.01284 +/- 0.08613
	-23.9186% +/- 2.034%
	(Student's t, pooled s = 0.091667)
```

### Peak Memory Usage

```console
x ./reports/builtins/add_rvalue_reference_t/peak_mem_no_builtin.txt
+ ./reports/builtins/add_rvalue_reference_t/peak_mem_builtin.txt
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
x  10       1147804       1148176       1147944     1147939.6     126.49743
+  10        951020        951448        951292      951284.8     123.53029
Difference at 95.0% confidence
	-196655 +/- 117.471
	-17.1311% +/- 0.0102332%
	(Student's t, pooled s = 125.023)
```

### Total Memory Usage

```console
x ./reports/builtins/add_rvalue_reference_t/total_mem_no_builtin.txt
+ ./reports/builtins/add_rvalue_reference_t/total_mem_builtin.txt
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
x  10          1363          1363          1363          1363             0
+  10          1096          1096          1096          1096             0
Difference at 95.0% confidence
	-267 +/- 0
	-19.5891% +/- 0%
	(Student's t, pooled s = 0)
```

---

