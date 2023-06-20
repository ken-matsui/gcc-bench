## Mon Jun 19 09:11:05 PM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230615 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse origin/master
73a0d3bf895b5c322676178a51ac0d68cf603953
```

```console
$ git rev-parse HEAD
3359905613955122787dc631bceaf167fab4e4c2
```

### Time Benchmark

```console
$ perf stat xg++ -c remove_pointer_benchmark.cc
x /tmp/tmp.RAhxXYlHQu/time_before.txt
+ /tmp/tmp.RAhxXYlHQu/time_after.txt
+----------------------------------------------------------------------+
|  ++             +                              x                     |
|+ ++       ++    ++                  x   x    xxxx     x    x        x|
| |_______A_M____|                        |______M_A________|          |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     3.6200133     3.8247194     3.6889505     3.7033308   0.059972113
+  10      3.384799      3.502432      3.456113     3.4392256   0.046457171
Difference at 95.0% confidence
	-0.264105 +/- 0.0504018
	-7.13156% +/- 1.36098%
	(Student's t, pooled s = 0.053642)
```

### Peak Memory Usage Benchmark

```console
$ /usr/bin/time -v xg++ -c remove_pointer_benchmark.cc
x /tmp/tmp.RAhxXYlHQu/peak_mem_before.txt
+ /tmp/tmp.RAhxXYlHQu/peak_mem_after.txt
+----------------------------------------------------------------------+
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|++                                                                   x|
|A                                                                    A|
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1098172       1098444       1098300       1098298     89.784928
+  10       1050772       1051132       1050928     1050946.4      108.9946
Difference at 95.0% confidence
	-47351.6 +/- 93.8212
	-4.31136% +/- 0.00854242%
	(Student's t, pooled s = 99.8528)
```

### Total Memory Usage Benchmark

```console
$ xg++ -ftime-report -c remove_pointer_benchmark.cc
x /tmp/tmp.RAhxXYlHQu/total_mem_before.txt
+ /tmp/tmp.RAhxXYlHQu/total_mem_after.txt
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
x  10          1278          1278          1278          1278             0
+  10          1215          1215          1215          1215             0
Difference at 95.0% confidence
	-63 +/- 0
	-4.92958% +/- 0%
	(Student's t, pooled s = 0)
```

---

