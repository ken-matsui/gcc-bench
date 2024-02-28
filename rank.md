## Wed Feb 28 07:49:17 AM PST 2024

### Time

```console
x ./reports/builtins/rank/time_no_builtin.txt
+ ./reports/builtins/rank/time_builtin.txt
+----------------------------------------------------------------------+
|  +                                                                   |
|  +                                                                   |
| ++                               x                                   |
| ++ ++     +  +                xx xx x x x                     x     x|
||_M__A___|                  |________M____A____________|              |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     7.2696959     10.066173      7.725028     8.0471376     0.9795768
+  10     5.0791047     6.0590157     5.1797671     5.3327422    0.33628726
Difference at 95.0% confidence
	-2.7144 +/- 0.688109
	-33.7312% +/- 8.55097%
	(Student's t, pooled s = 0.732345)
```

### Peak Memory Usage

```console
x ./reports/builtins/rank/peak_mem_no_builtin.txt
+ ./reports/builtins/rank/peak_mem_builtin.txt
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
x  10       1469192       1469556       1469300     1469326.4     103.24857
+  10       1063828       1064092       1063984     1063960.8     85.807018
Difference at 95.0% confidence
	-405366 +/- 89.1951
	-27.5885% +/- 0.00607047%
	(Student's t, pooled s = 94.9292)
```

### Total Memory Usage

```console
x ./reports/builtins/rank/total_mem_no_builtin.txt
+ ./reports/builtins/rank/total_mem_builtin.txt
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
x  10          1935          1935          1935          1935             0
+  10          1266          1266          1266          1266             0
Difference at 95.0% confidence
	-669 +/- 0
	-34.5736% +/- 0%
	(Student's t, pooled s = 0)
```

---

