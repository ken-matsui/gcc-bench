## Wed Jan 10 11:20:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_compound_v/time_no_builtin.txt
+ ./reports/builtins/is_compound_v/time_builtin.txt
+----------------------------------------------------------------------+
|    +                                                                x|
|+++ +                                                            x xxx|
|+++ ++                                                          xx xxx|
| |A_|                                                            |_AM||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     16.816255     17.614225     17.409623     17.326815    0.28464297
+  10     7.2736831     7.9523784     7.5285684     7.6102308    0.25923491
Difference at 95.0% confidence
	-9.71658 +/- 0.255791
	-56.0783% +/- 1.47627%
	(Student's t, pooled s = 0.272236)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_compound_v/peak_mem_no_builtin.txt
+ ./reports/builtins/is_compound_v/peak_mem_builtin.txt
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
x  10       3035628       3035936       3035728     3035762.4     103.67814
+  10       1586144       1586324       1586240     1586235.6     53.014043
Difference at 95.0% confidence
	-1.44953e+06 +/- 77.366
	-47.7484% +/- 0.00254849%
	(Student's t, pooled s = 82.3397)
```

### Total Memory Usage

```console
x ./reports/builtins/is_compound_v/total_mem_no_builtin.txt
+ ./reports/builtins/is_compound_v/total_mem_builtin.txt
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
x  10          3843          3843          3843          3843             0
+  10          1823          1823          1823          1823             0
Difference at 95.0% confidence
	-2020 +/- 0
	-52.5631% +/- 0%
	(Student's t, pooled s = 0)
```

---

