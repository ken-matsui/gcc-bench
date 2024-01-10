## Wed Jan 10 11:20:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_arithmetic/time_no_builtin.txt
+ ./reports/builtins/is_arithmetic/time_builtin.txt
+----------------------------------------------------------------------+
| +                                                                  x |
| +                                                                  x |
| + +                                                                x |
| + +                                                               xx |
|++++                                                          x   xxxx|
| MA|                                                             |_AM||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     11.353701     12.134939     12.030283     11.936057     0.2254561
+  10     3.6681622     4.0711432     3.8458846     3.8696108    0.12125698
Difference at 95.0% confidence
	-8.06645 +/- 0.170082
	-67.5805% +/- 1.42494%
	(Student's t, pooled s = 0.181016)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_arithmetic/peak_mem_no_builtin.txt
+ ./reports/builtins/is_arithmetic/peak_mem_builtin.txt
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
x  10       2284196       2284516       2284440     2284382.4     115.41153
+  10       1020128       1020548       1020460     1020391.6     138.04283
Difference at 95.0% confidence
	-1.26399e+06 +/- 119.546
	-55.3318% +/- 0.00523319%
	(Student's t, pooled s = 127.231)
```

### Total Memory Usage

```console
x ./reports/builtins/is_arithmetic/total_mem_no_builtin.txt
+ ./reports/builtins/is_arithmetic/total_mem_builtin.txt
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
x  10          2914          2914          2914          2914             0
+  10          1209          1209          1209          1209             0
Difference at 95.0% confidence
	-1705 +/- 0
	-58.5106% +/- 0%
	(Student's t, pooled s = 0)
```

---

