## Wed Jan 10 11:20:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_scalar_v/time_no_builtin.txt
+ ./reports/builtins/is_scalar_v/time_builtin.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                     |
|++                                                                    |
|++                                                              x  x  |
|++                                                              xx x  |
|++                                                              xx xxx|
|A|                                                              |_AM| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     41.200917     44.182046     42.748221     42.432732     1.0653168
+  10     4.2431995     4.6530751     4.3770137      4.440648    0.15455544
Difference at 95.0% confidence
	-37.9921 +/- 0.715201
	-89.5349% +/- 1.68549%
	(Student's t, pooled s = 0.761179)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_scalar_v/peak_mem_no_builtin.txt
+ ./reports/builtins/is_scalar_v/peak_mem_builtin.txt
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
x  10       6507696       6508156       6507916     6507905.6     137.62686
+  10       1089636       1090092       1089940     1089893.6      154.1624
Difference at 95.0% confidence
	-5.41801e+06 +/- 137.302
	-83.2528% +/- 0.00210977%
	(Student's t, pooled s = 146.129)
```

### Total Memory Usage

```console
x ./reports/builtins/is_scalar_v/total_mem_no_builtin.txt
+ ./reports/builtins/is_scalar_v/total_mem_builtin.txt
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
x  10          8685          8685          8685          8685             0
+  10          1250          1250          1250          1250             0
Difference at 95.0% confidence
	-7435 +/- 0
	-85.6074% +/- 0%
	(Student's t, pooled s = 0)
```

---

