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

