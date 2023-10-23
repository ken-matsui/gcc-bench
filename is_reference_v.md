## Wed Jul 12 07:47:02 PM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/4b6fbc0e666bcd8f792c46628b44287cee226e1e/is_reference.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230610 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~5  # base commit
a53a83b63b4c4b3f7d2d997b3a26d82abb883f9a
```

```console
$ git log -n 5 --pretty=format:%H  # changes from the base
a566ed7fb9649d3e031d9f29b3df200f1f930607
b191896d2efb30fb361e1b0555eecebb680a0144
88fd0a7aaf4b783cf4571b9dfa57acd5e7b97ce2
4efd3179279f1a3c5295927426e7ac939400c577
e742a22609fd9b8131e41e7b4c8aaad9a9404898
```

### Time

```console
$ perf stat xg++ -c is_reference.cc
x /tmp/tmp.lXuYgWeRo6/time_before.txt
+ /tmp/tmp.lXuYgWeRo6/time_after.txt
+----------------------------------------------------------------------+
| ++ +                                                 x      x        |
|+++ +++       +                  xx                   x  x   x x     x|
||___A___|                                 |___________A__M________|   |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.1560666     4.4094337     4.3232672     4.3038541    0.08287272
+  10     3.9269023     4.0237778     3.9533177     3.9528347    0.02815017
Difference at 95.0% confidence
	-0.351019 +/- 0.05815
	-8.15593% +/- 1.35111%
	(Student's t, pooled s = 0.0618883)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_reference.cc
x /tmp/tmp.lXuYgWeRo6/peak_mem_before.txt
+ /tmp/tmp.lXuYgWeRo6/peak_mem_after.txt
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
|A|                                                                   A|
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1073108       1073388       1073260     1073237.6     102.85178
+  10       1024836       1025184       1025168     1025112.8     110.12397
Difference at 95.0% confidence
	-48124.8 +/- 100.114
	-4.48408% +/- 0.00932821%
	(Student's t, pooled s = 106.55)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_reference.cc
x /tmp/tmp.lXuYgWeRo6/total_mem_before.txt
+ /tmp/tmp.lXuYgWeRo6/total_mem_after.txt
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
x  10          1269          1269          1269          1269             0
+  10          1167          1167          1167          1167             0
Difference at 95.0% confidence
	-102 +/- 0
	-8.03783% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 12:37:37 AM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_reference_v.cc
x /tmp/tmp.jM35859Xc1/time_no_builtin.txt
+ /tmp/tmp.jM35859Xc1/time_builtin.txt
+----------------------------------------------------------------------+
|+++ +            +      x  +xx+   + +      x x   x      x   x   x    *|
||_____________________A____M___|____________|__A_M____________|       |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.1277528     4.5367967     4.3592024     4.3343231    0.14360304
+  10     3.9074657     4.5379897     4.1568448     4.1072274     0.2005892
Difference at 95.0% confidence
	-0.227096 +/- 0.163902
	-5.23947% +/- 3.78149%
	(Student's t, pooled s = 0.174439)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_reference_v.cc
x /tmp/tmp.jM35859Xc1/peak_mem_no_builtin.txt
+ /tmp/tmp.jM35859Xc1/peak_mem_builtin.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                     |
|+                                                                    x|
|+                                                                    x|
|+                                                                   xx|
|+                                                                   xx|
|++                                                                  xx|
|++                                                                  xx|
|A                                                                   |A|
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1061744       1062164       1062036     1061971.6     147.57838
+  10       1027832       1028100       1027988     1027976.8     88.157435
Difference at 95.0% confidence
	-33994.8 +/- 114.212
	-3.2011% +/- 0.0107547%
	(Student's t, pooled s = 121.555)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_reference_v.cc
x /tmp/tmp.jM35859Xc1/total_mem_no_builtin.txt
+ /tmp/tmp.jM35859Xc1/total_mem_builtin.txt
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
x  10          1231          1231          1231          1231             0
+  10          1179          1179          1179          1179             0
Difference at 95.0% confidence
	-52 +/- 0
	-4.22421% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_reference_v/time_no_builtin.txt
+ ./reports/built-ins/is_reference_v/time_builtin.txt
+----------------------------------------------------------------------+
|+                +  +       +*    +x + x+    * x  x  +     x  x      x|
|               |______________A___M__|_______|____A____________|      |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.8633777     5.4048222     5.1526156     5.1448928    0.17685639
+  10      4.476712     5.1843802     4.9277647     4.8826028    0.20482542
Difference at 95.0% confidence
	-0.26229 +/- 0.179794
	-5.09806% +/- 3.49461%
	(Student's t, pooled s = 0.191353)
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_reference_v/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_reference_v/peak_mem_builtin.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                     |
|+                                                                     |
|+                                                                     |
|+                                                                   x |
|+                                                                   x |
|+                                                                   xx|
|+                                                                   xx|
|+                                                                   xx|
|+                                                                   xx|
|A                                                                   MA|
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1060948       1061364       1061104     1061160.4     135.80967
+  10       1027224       1027412       1027384     1027343.6     71.166784
Difference at 95.0% confidence
	-33816.8 +/- 101.869
	-3.18678% +/- 0.00959979%
	(Student's t, pooled s = 108.418)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_reference_v/total_mem_no_builtin.txt
+ ./reports/built-ins/is_reference_v/total_mem_builtin.txt
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
x  10          1231          1231          1231          1231             0
+  10          1179          1179          1179          1179             0
Difference at 95.0% confidence
	-52 +/- 0
	-4.22421% +/- 0%
	(Student's t, pooled s = 0)
```

---

