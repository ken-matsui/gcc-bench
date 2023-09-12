## Mon Sep 11 07:26:08 PM PDT 2023

https://github.com/ken-matsui/gsoc23/blob/314b3ed53322daeda5574fde1f2362ece569a1d3/is_bounded_array_v.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230912 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
fb4b53d964b797e5f3380726175c95110c4ff9ff
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
629cedee1c7dfcdc3a9a8625a17a9fc02bf4a299
ad65d2fdeae4f2b8a2200ed36153989133cab077
```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_bounded_array_v.cc
x /tmp/tmp.L3RFIo1okc/time_A.txt
+ /tmp/tmp.L3RFIo1okc/time_B.txt
+----------------------------------------------------------------------+
|               ++ +                                xx            x    |
|+ +           +++++                               xxx            xxx x|
|      |______A__M___|                              |_______A_____M_|  |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     15.332521     16.247809     16.056069     15.766173    0.39079761
+  10     12.940513     13.796551     13.701025     13.566828    0.31598051
Difference at 95.0% confidence
	-2.19935 +/- 0.333898
	-13.9498% +/- 2.11781%
	(Student's t, pooled s = 0.355364)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_bounded_array_v.cc
x /tmp/tmp.L3RFIo1okc/peak_mem_A.txt
+ /tmp/tmp.L3RFIo1okc/peak_mem_B.txt
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
x  10       2257000       2257164       2257128       2257106     59.635932
+  10       2161668       2161880       2161792     2161785.2     76.896468
Difference at 95.0% confidence
	-95320.8 +/- 64.6532
	-4.22314% +/- 0.00286443%
	(Student's t, pooled s = 68.8096)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_bounded_array_v.cc
x /tmp/tmp.L3RFIo1okc/total_mem_A.txt
+ /tmp/tmp.L3RFIo1okc/total_mem_B.txt
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
x  10          2871          2871          2871          2871             0
+  10          2624          2624          2624          2624             0
Difference at 95.0% confidence
	-247 +/- 0
	-8.60327% +/- 0%
	(Student's t, pooled s = 0)
```

---
