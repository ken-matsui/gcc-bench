## Wed Jan 10 11:20:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_unsigned_v/time_no_builtin.txt
+ ./reports/builtins/is_unsigned_v/time_builtin.txt
+----------------------------------------------------------------------+
|+                                                                     |
|++                                                                    |
|++                                                              x     |
|++                                                            x x    x|
|+++                                                           xxxx  xx|
||A                                                             |MA__| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     16.370458     17.805606     16.819517      16.97525    0.55382764
+  10     2.9816933     3.3346694     3.0907617     3.1024487     0.1154807
Difference at 95.0% confidence
	-13.8728 +/- 0.375874
	-81.7237% +/- 2.21425%
	(Student's t, pooled s = 0.400038)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_unsigned_v/peak_mem_no_builtin.txt
+ ./reports/builtins/is_unsigned_v/peak_mem_builtin.txt
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
x  10       3049408       3049720       3049552       3049536     98.088396
+  10        911096        911452        911300      911278.4     111.58972
Difference at 95.0% confidence
	-2.13826e+06 +/- 98.7103
	-70.1175% +/- 0.0032369%
	(Student's t, pooled s = 105.056)
```

### Total Memory Usage

```console
x ./reports/builtins/is_unsigned_v/total_mem_no_builtin.txt
+ ./reports/builtins/is_unsigned_v/total_mem_builtin.txt
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
x  10          3977          3977          3977          3977             0
+  10          1056          1056          1056          1056             0
Difference at 95.0% confidence
	-2921 +/- 0
	-73.4473% +/- 0%
	(Student's t, pooled s = 0)
```

---

