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

## Tue Jun 20 03:03:13 PM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/e00a92d84d17979818fa5a6e71e52dfcb9e648a0/remove_pointer.cc

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
x /tmp/tmp.WgyLICAj71/time_before.txt
+ /tmp/tmp.WgyLICAj71/time_after.txt
+----------------------------------------------------------------------+
|    +                                                            x    |
| +  +                                                            xx   |
| + ++                                                            xx   |
|++ ++                                                          x xx xx|
| |_A|                                                           |_A|  |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     6.9392317     7.1111235     7.0048566     7.0118213   0.051724346
+  10     4.9765257     5.1118405     5.0836516     5.0542637   0.049035859
Difference at 95.0% confidence
	-1.95756 +/- 0.0473538
	-27.918% +/- 0.675342%
	(Student's t, pooled s = 0.050398)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c remove_pointer.cc
x /tmp/tmp.WgyLICAj71/peak_mem_before.txt
+ /tmp/tmp.WgyLICAj71/peak_mem_after.txt
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
x  10       1733468       1733836       1733668       1733660     113.60751
+  10       1402788       1403100       1403000     1402955.2     104.25269
Difference at 95.0% confidence
	-330705 +/- 102.445
	-19.0755% +/- 0.00590915%
	(Student's t, pooled s = 109.03)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c remove_pointer.cc
x /tmp/tmp.WgyLICAj71/total_mem_before.txt
+ /tmp/tmp.WgyLICAj71/total_mem_after.txt
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
x  10          2008          2008          2008          2008             0
+  10          1606          1606          1606          1606             0
Difference at 95.0% confidence
	-402 +/- 0
	-20.0199% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 01:31:29 AM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c remove_pointer.cc
x /tmp/tmp.MseBBtkz79/time_no_builtin.txt
+ /tmp/tmp.MseBBtkz79/time_builtin.txt
+----------------------------------------------------------------------+
|        +                                                             |
|        +                                                 x           |
|+      ++                                                 x         x |
|+   +  ++    +                                           xx     xx xxx|
|  |___A_M_|                                               |____A_M__| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     5.8632045     6.2543352     6.1061692      6.057887     0.1654708
+  10     3.9301066     4.3640645     4.1835562      4.142877    0.13157493
Difference at 95.0% confidence
	-1.91501 +/- 0.140457
	-31.6118% +/- 2.31858%
	(Student's t, pooled s = 0.149487)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c remove_pointer.cc
x /tmp/tmp.MseBBtkz79/peak_mem_no_builtin.txt
+ /tmp/tmp.MseBBtkz79/peak_mem_builtin.txt
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
x  10       1530472       1530736       1530608     1530594.4     69.312816
+  10       1083604       1083952       1083880     1083852.8     101.94203
Difference at 95.0% confidence
	-446742 +/- 81.9025
	-29.1875% +/- 0.00535102%
	(Student's t, pooled s = 87.1678)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c remove_pointer.cc
x /tmp/tmp.MseBBtkz79/total_mem_no_builtin.txt
+ /tmp/tmp.MseBBtkz79/total_mem_builtin.txt
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
x  10          1762          1762          1762          1762             0
+  10          1247          1247          1247          1247             0
Difference at 95.0% confidence
	-515 +/- 0
	-29.2281% +/- 0%
	(Student's t, pooled s = 0)
```

---

