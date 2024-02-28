## Wed Feb 28 07:23:30 AM PST 2024

### Time

```console
x ./reports/builtins/decay_t/time_no_builtin.txt
+ ./reports/builtins/decay_t/time_builtin.txt
+----------------------------------------------------------------------+
|++                                                                    |
|+++                                                         x      x  |
|++++ +                                                     xx x xx xxx|
||MA|                                                        |___AM__| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     9.3416965     10.021175      9.757935     9.6908521    0.24111464
+  10     5.4779343     5.8129355     5.5703451     5.5811942    0.09991516
Difference at 95.0% confidence
	-4.10966 +/- 0.173405
	-42.4076% +/- 1.78937%
	(Student's t, pooled s = 0.184553)
```

### Peak Memory Usage

```console
x ./reports/builtins/decay_t/peak_mem_no_builtin.txt
+ ./reports/builtins/decay_t/peak_mem_builtin.txt
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
x  10       1902628       1902820       1902720     1902722.4     72.497049
+  10       1346716       1347160       1347004     1346980.4     129.11253
Difference at 95.0% confidence
	-555742 +/- 98.3795
	-29.2077% +/- 0.00517046%
	(Student's t, pooled s = 104.704)
```

### Total Memory Usage

```console
x ./reports/builtins/decay_t/total_mem_no_builtin.txt
+ ./reports/builtins/decay_t/total_mem_builtin.txt
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
x  10          2342          2342          2342          2342             0
+  10          1567          1567          1567          1567             0
Difference at 95.0% confidence
	-775 +/- 0
	-33.0914% +/- 0%
	(Student's t, pooled s = 0)
```

---

