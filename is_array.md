## Sat Oct 21 07:29:02 PM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_array.cc
x /tmp/tmp.KJ9zAzayGd/time_no_builtin.txt
+ /tmp/tmp.KJ9zAzayGd/time_builtin.txt
+----------------------------------------------------------------------+
|                           +            x                             |
|  +++  +      xx ++ x     ++xx          x  xx                  x     +|
||_________________M_A_____________A_____|________|                    |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     3.4399033     3.8748801     3.6669653     3.6123705    0.13654333
+  10     3.3338054     3.9291399     3.4725172     3.4906398    0.17861395
No difference proven at 95.0% confidence
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_array.cc
x /tmp/tmp.KJ9zAzayGd/peak_mem_no_builtin.txt
+ /tmp/tmp.KJ9zAzayGd/peak_mem_builtin.txt
+----------------------------------------------------------------------+
| +                                                                    |
| +                                                                    |
| ++                                                               xxx |
| ++                                                               xxx |
|++++                                                              xxxx|
| MA                                                               |A| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10        982208        982540        982304        982326     105.88463
+  10        974280        974652        974456      974466.4     101.59965
Difference at 95.0% confidence
	-7859.6 +/- 97.4965
	-0.800101% +/- 0.00992506%
	(Student's t, pooled s = 103.764)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_array.cc
x /tmp/tmp.KJ9zAzayGd/total_mem_no_builtin.txt
+ /tmp/tmp.KJ9zAzayGd/total_mem_builtin.txt
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
x  10          1188          1188          1188          1188             0
+  10          1151          1151          1151          1151             0
Difference at 95.0% confidence
	-37 +/- 0
	-3.11448% +/- 0%
	(Student's t, pooled s = 0)
```

---

