## Mon Jul  3 02:22:50 AM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/d73d92577ef92310f33c390e00071f1095a085de/is_scalar.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230702 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
67e0967b32af60cdf5a0c3e811bfa63c30dcdb76
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
4feb87bc3cca2ab3eaf890ad6e3de1dda5280e94
9bf58dae678cd742296a29c77723570f8f2b2431
```

### Time

```console
$ perf stat xg++ -c is_scalar.cc
x /tmp/tmp.mO5qK6yyI0/time_before.txt
+ /tmp/tmp.mO5qK6yyI0/time_after.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                     |
|+                                                                     |
|+                                                                     |
|+                                                                     |
|+                                                                     |
|+                                                                 x   |
|+                                                                 x x |
|+                                                                 x xx|
|+                                                                 xxxx|
|A                                                                 |AM||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     45.282811      47.28817      46.47663     46.283487    0.71434523
+  10     4.2778836     4.4026654     4.3592295     4.3396709   0.048139161
Difference at 95.0% confidence
	-41.9438 +/- 0.475684
	-90.6237% +/- 1.02776%
	(Student's t, pooled s = 0.506264)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_scalar.cc
x /tmp/tmp.mO5qK6yyI0/peak_mem_before.txt
+ /tmp/tmp.mO5qK6yyI0/peak_mem_after.txt
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
x  10       4014964       4015368       4015220     4015174.4     124.96684
+  10        862484        862760        862656      862640.8     90.072563
Difference at 95.0% confidence
	-3.15253e+06 +/- 102.346
	-78.5155% +/- 0.00254899%
	(Student's t, pooled s = 108.926)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_scalar.cc
x /tmp/tmp.mO5qK6yyI0/total_mem_before.txt
+ /tmp/tmp.mO5qK6yyI0/total_mem_after.txt
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
x  10          5817          5817          5817          5817             0
+  10          1036          1036          1036          1036             0
Difference at 95.0% confidence
	-4781 +/- 0
	-82.1901% +/- 0%
	(Student's t, pooled s = 0)
```

---

