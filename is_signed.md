## Wed Jan 10 11:20:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_signed/time_no_builtin.txt
+ ./reports/builtins/is_signed/time_builtin.txt
+----------------------------------------------------------------------+
|  +                                                                   |
|  +                                                             x     |
| ++                                                             x     |
|+++                                                            xxx   x|
|+++                                                            xxx   x|
||AM                                                            |MA_|  |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     13.864335     14.887988     14.136221     14.249536     0.3438779
+  10      3.682875     4.0091532     3.9679974     3.8710165    0.13255204
Difference at 95.0% confidence
	-10.3785 +/- 0.244856
	-72.8341% +/- 1.71835%
	(Student's t, pooled s = 0.260597)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_signed/peak_mem_no_builtin.txt
+ ./reports/builtins/is_signed/peak_mem_builtin.txt
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
x  10       2678428       2678788       2678688     2678655.6     114.96782
+  10       1019732       1020060       1019984     1019926.8     118.01393
Difference at 95.0% confidence
	-1.65873e+06 +/- 109.464
	-61.9239% +/- 0.00408652%
	(Student's t, pooled s = 116.501)
```

### Total Memory Usage

```console
x ./reports/builtins/is_signed/total_mem_no_builtin.txt
+ ./reports/builtins/is_signed/total_mem_builtin.txt
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
x  10          3410          3410          3410          3410             0
+  10          1209          1209          1209          1209             0
Difference at 95.0% confidence
	-2201 +/- 0
	-64.5455% +/- 0%
	(Student's t, pooled s = 0)
```

---

