## Fri Jul 14 09:17:57 PM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/32545d585dccbd3dc233b7f4ece70ad100390f40/is_fundamental_v.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230709 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~1  # base commit
6404ccec9e4f794c88ea660a8b6f9224bcba0c96
```

```console
$ git log -n 1 --pretty=format:%H  # changes from the base
7976f3dfea017b10740de7af8011746c2c953e93
```

### Time

```console
$ perf stat xg++ -c is_fundamental_v.cc
x /tmp/tmp.spydFRoGh3/time_before.txt
+ /tmp/tmp.spydFRoGh3/time_after.txt
+----------------------------------------------------------------------+
| +                                                                    |
| +                                                                  x |
| +                                                                  x |
|++ +                                                                xx|
|++ ++                                                           xxxxxx|
||MA|                                                              |AM||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.7858175     4.9002479     4.8858507     4.8597628   0.044267648
+  10     3.0927975     3.2078276     3.1133857     3.1323793   0.038180027
Difference at 95.0% confidence
	-1.72738 +/- 0.0388392
	-35.5446% +/- 0.799199%
	(Student's t, pooled s = 0.0413361)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_fundamental_v.cc
x /tmp/tmp.spydFRoGh3/peak_mem_before.txt
+ /tmp/tmp.spydFRoGh3/peak_mem_after.txt
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
x  10       1374560       1374720       1374696     1374659.6     66.035679
+  10        962016        962220        962196      962129.6     82.218138
Difference at 95.0% confidence
	-412530 +/- 70.063
	-30.0096% +/- 0.00509675%
	(Student's t, pooled s = 74.5672)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_fundamental_v.cc
x /tmp/tmp.spydFRoGh3/total_mem_before.txt
+ /tmp/tmp.spydFRoGh3/total_mem_after.txt
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
x  10          1611          1611          1611          1611             0
+  10          1118          1118          1118          1118             0
Difference at 95.0% confidence
	-493 +/- 0
	-30.6021% +/- 0%
	(Student's t, pooled s = 0)
```

---

