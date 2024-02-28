## Wed Feb 28 06:00:44 AM PST 2024

### Time

```console
x ./reports/builtins/add_pointer/time_no_builtin.txt
+ ./reports/builtins/add_pointer/time_builtin.txt
+----------------------------------------------------------------------+
|    ++                                                                |
|    ++                                             x                 x|
|++  ++ ++                                         xx x x    x   x  x x|
|  |_AM_|                                           |_______AM______|  |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.5443588      4.894873     4.7196526     4.7037817    0.14491371
+  10     3.6044014     3.7471389     3.6914787     3.6846003   0.044224627
Difference at 95.0% confidence
	-1.01918 +/- 0.100664
	-21.6673% +/- 2.14006%
	(Student's t, pooled s = 0.107135)
```

### Peak Memory Usage

```console
x ./reports/builtins/add_pointer/peak_mem_no_builtin.txt
+ ./reports/builtins/add_pointer/peak_mem_builtin.txt
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
x  10       1172008       1172540       1172344     1172322.8     166.39498
+  10       1000116       1000560       1000368     1000383.2     141.28049
Difference at 95.0% confidence
	-171940 +/- 145.026
	-14.6666% +/- 0.0123708%
	(Student's t, pooled s = 154.349)
```

### Total Memory Usage

```console
x ./reports/builtins/add_pointer/total_mem_no_builtin.txt
+ ./reports/builtins/add_pointer/total_mem_builtin.txt
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
x  10          1408          1408          1408          1408             0
+  10          1162          1162          1162          1162             0
Difference at 95.0% confidence
	-246 +/- 0
	-17.4716% +/- 0%
	(Student's t, pooled s = 0)
```

---

