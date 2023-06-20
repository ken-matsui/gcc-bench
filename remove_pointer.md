## Mon Jun 19 10:54:24 PM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/bff3bde532cf1a4d6f0ffea0b1db2a2b431bd74f/remove_pointer.cc

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230615 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
73a0d3bf895b5c322676178a51ac0d68cf603953
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
3359905613955122787dc631bceaf167fab4e4c2
270dd10662a0f0e27d8952c6c4291123d0b349b6
```

### Time

```console
$ perf stat xg++ -c remove_pointer.cc
x /tmp/tmp.vynQ6BRCPO/time_before.txt
+ /tmp/tmp.vynQ6BRCPO/time_after.txt
+----------------------------------------------------------------------+
|+                                                        x           x|
|++      ++     ++ +  ++                        x x    x  x x     x x x|
|  |________A___M____|                              |_______A_______|  |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     3.6578385     3.7823199     3.7285758     3.7278216   0.045107315
+  10     3.3921297     3.5173889     3.4771778     3.4543354   0.049036166
Difference at 95.0% confidence
	-0.273486 +/- 0.0442669
	-7.33635% +/- 1.18747%
	(Student's t, pooled s = 0.0471127)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c remove_pointer.cc
x /tmp/tmp.vynQ6BRCPO/peak_mem_before.txt
+ /tmp/tmp.vynQ6BRCPO/peak_mem_after.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                   xx|
|A                                                                    A|
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1098000       1098356       1098244     1098233.2     95.238647
+  10       1050804       1051052       1050928     1050922.8     74.524865
Difference at 95.0% confidence
	-47310.4 +/- 80.346
	-4.30786% +/- 0.00731594%
	(Student's t, pooled s = 85.5113)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c remove_pointer.cc
x /tmp/tmp.vynQ6BRCPO/total_mem_before.txt
+ /tmp/tmp.vynQ6BRCPO/total_mem_after.txt
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

