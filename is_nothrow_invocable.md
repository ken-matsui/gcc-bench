## Wed Feb 28 11:24:14 AM PST 2024

### Time

```console
x ./reports/builtins/is_nothrow_invocable/time_no_builtin.txt
+ ./reports/builtins/is_nothrow_invocable/time_builtin.txt
+----------------------------------------------------------------------+
|   +                                                                  |
|++ +                                                               x  |
|++ +                                                          x    xxx|
|++ +                                                          xx   xxx|
||A_|                                                            |_AM_||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     3.5691491     3.8327879     3.7647826     3.7292433    0.10772859
+  10     1.0513619     1.1734022     1.0813036     1.1034738   0.049624189
Difference at 95.0% confidence
	-2.62577 +/- 0.0788029
	-70.4102% +/- 2.11311%
	(Student's t, pooled s = 0.083869)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_nothrow_invocable/peak_mem_no_builtin.txt
+ ./reports/builtins/is_nothrow_invocable/peak_mem_builtin.txt
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
x  10        706688        706944        706816        706816     104.51156
+  10        264448        264832        264704      264691.2     112.07616
Difference at 95.0% confidence
	-442125 +/- 101.814
	-62.5516% +/- 0.0144047%
	(Student's t, pooled s = 108.36)
```

### Total Memory Usage

```console
x ./reports/builtins/is_nothrow_invocable/total_mem_no_builtin.txt
+ ./reports/builtins/is_nothrow_invocable/total_mem_builtin.txt
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
x  10           709           709           709           709             0
+  10           244           244           244           244             0
Difference at 95.0% confidence
	-465 +/- 0
	-65.5853% +/- 0%
	(Student's t, pooled s = 0)
```

---

