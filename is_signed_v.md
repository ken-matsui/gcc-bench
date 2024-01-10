## Wed Jan 10 11:20:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_signed_v/time_no_builtin.txt
+ ./reports/builtins/is_signed_v/time_builtin.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                     |
|++                                                                    |
|++                                                                 x  |
|++                                                              x  xx |
|++                                                            x xx xxx|
|A|                                                              |_AM| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     14.652377     15.900658     15.542068     15.361632     0.4379127
+  10     3.0160139     3.2758125     3.0581801     3.0820807   0.077601883
Difference at 95.0% confidence
	-12.2796 +/- 0.29548
	-79.9365% +/- 1.92349%
	(Student's t, pooled s = 0.314475)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_signed_v/peak_mem_no_builtin.txt
+ ./reports/builtins/is_signed_v/peak_mem_builtin.txt
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
x  10       2757784       2758080       2757960     2757950.8     104.71633
+  10        910812        911136        911012      910995.6     118.63595
Difference at 95.0% confidence
	-1.84696e+06 +/- 105.134
	-66.9684% +/- 0.00381203%
	(Student's t, pooled s = 111.893)
```

### Total Memory Usage

```console
x ./reports/builtins/is_signed_v/total_mem_no_builtin.txt
+ ./reports/builtins/is_signed_v/total_mem_builtin.txt
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
x  10          3501          3501          3501          3501             0
+  10          1056          1056          1056          1056             0
Difference at 95.0% confidence
	-2445 +/- 0
	-69.8372% +/- 0%
	(Student's t, pooled s = 0)
```

---

