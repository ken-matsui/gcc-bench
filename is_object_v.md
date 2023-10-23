## Mon Jun 19 10:31:57 PM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/bff3bde532cf1a4d6f0ffea0b1db2a2b431bd74f/is_object.cc

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230610 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~6  # base commit
a53a83b63b4c4b3f7d2d997b3a26d82abb883f9a
```

```console
$ git log -n 6 --pretty=format:%H  # changes from the base
612add931e1910cc181f798e07384dd75d282234
1beb806da32c45e6df3992311780090b1e85c82a
bfc7d57f57404c1866125eb1cde02dceec93fac7
5b60ced93ecbf54165da1f74ab6f1eb20276f8f8
0105651adc2c1f5dce207058681632a1826af889
fabddb6b34b1eaaadf71c278d4235863b91a58e0
```

### Time

```console
$ perf stat xg++ -c is_object.cc
x /tmp/tmp.SHpNCoOZeB/time_before.txt
+ /tmp/tmp.SHpNCoOZeB/time_after.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                     |
|+                                                                x    |
|+ +                                                              x  x |
|+ +                                                              xx x |
|+++                                                              xx xx|
|MA|                                                              |MA| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     5.6939672     5.9339897     5.7860704     5.7973985   0.085638761
+  10     2.0537099     2.1702986     2.0770306     2.1028979   0.046125505
Difference at 95.0% confidence
	-3.6945 +/- 0.064626
	-63.7269% +/- 1.11474%
	(Student's t, pooled s = 0.0687807)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_object.cc
x /tmp/tmp.SHpNCoOZeB/peak_mem_before.txt
+ /tmp/tmp.SHpNCoOZeB/peak_mem_after.txt
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
x  10       1523984       1524236       1524108     1524092.4      72.84565
+  10        850512        850648        850564      850563.2     38.357383
Difference at 95.0% confidence
	-673529 +/- 54.6978
	-44.1922% +/- 0.00358888%
	(Student's t, pooled s = 58.2142)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_object.cc
x /tmp/tmp.SHpNCoOZeB/total_mem_before.txt
+ /tmp/tmp.SHpNCoOZeB/total_mem_after.txt
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
x  10          1808          1808          1808          1808             0
+  10           959           959           959           959             0
Difference at 95.0% confidence
	-849 +/- 0
	-46.958% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sat Jun 24 08:01:10 AM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/f9a3fe05baae5f5320510443775274aff1d9a989/is_object.cc

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230610 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~6  # base commit
a53a83b63b4c4b3f7d2d997b3a26d82abb883f9a
```

```console
$ git log -n 6 --pretty=format:%H  # changes from the base
612add931e1910cc181f798e07384dd75d282234
1beb806da32c45e6df3992311780090b1e85c82a
bfc7d57f57404c1866125eb1cde02dceec93fac7
5b60ced93ecbf54165da1f74ab6f1eb20276f8f8
0105651adc2c1f5dce207058681632a1826af889
fabddb6b34b1eaaadf71c278d4235863b91a58e0
```

### Time

```console
$ perf stat xg++ -c is_object.cc
x /tmp/tmp.km4r5X1LK7/time_before.txt
+ /tmp/tmp.km4r5X1LK7/time_after.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                     |
|++                                                                    |
|++                                                                    |
|++                                                    xxx x           |
|++                                                    xxxxx          x|
|A|                                                   |__MA____|       |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     10.667472     12.797531     10.937395     11.082588    0.63608646
+  10     2.7567243     2.8562468     2.7667624     2.7978662   0.046878469
Difference at 95.0% confidence
	-8.28472 +/- 0.423759
	-74.7544% +/- 3.82364%
	(Student's t, pooled s = 0.451001)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_object.cc
x /tmp/tmp.km4r5X1LK7/peak_mem_before.txt
+ /tmp/tmp.km4r5X1LK7/peak_mem_after.txt
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
x  10       2369420       2369692       2369568     2369568.4     100.79594
+  10        886224        886496        886468      886425.6     84.752188
Difference at 95.0% confidence
	-1.48314e+06 +/- 87.4954
	-62.5913% +/- 0.00369246%
	(Student's t, pooled s = 93.1202)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_object.cc
x /tmp/tmp.km4r5X1LK7/total_mem_before.txt
+ /tmp/tmp.km4r5X1LK7/total_mem_after.txt
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
x  10          2866          2866          2866          2866             0
+  10          1024          1024          1024          1024             0
Difference at 95.0% confidence
	-1842 +/- 0
	-64.2708% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 12:05:09 AM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_object_v.cc
x /tmp/tmp.d4ICyjtWMB/time_no_builtin.txt
+ /tmp/tmp.d4ICyjtWMB/time_builtin.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                     |
|+                                                              x      |
|+                                                              x      |
|+++                                                            x    xx|
|+++                                                            x  xxxx|
|MA|                                                            |__AM| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     9.3532924     9.9809943     9.7568787     9.6586313    0.26037503
+  10     2.7893433     2.9944491     2.8071336     2.8482148   0.079909302
Difference at 95.0% confidence
	-6.81042 +/- 0.180955
	-70.5112% +/- 1.87351%
	(Student's t, pooled s = 0.192588)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_object_v.cc
x /tmp/tmp.d4ICyjtWMB/peak_mem_no_builtin.txt
+ /tmp/tmp.d4ICyjtWMB/peak_mem_builtin.txt
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
x  10       1972048       1972424       1972244       1972214     110.93542
+  10        880652        881008        880880      880859.2     91.967144
Difference at 95.0% confidence
	-1.09135e+06 +/- 95.7388
	-55.3365% +/- 0.00485438%
	(Student's t, pooled s = 101.894)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_object_v.cc
x /tmp/tmp.d4ICyjtWMB/total_mem_no_builtin.txt
+ /tmp/tmp.d4ICyjtWMB/total_mem_builtin.txt
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
x  10          2477          2477          2477          2477             0
+  10          1018          1018          1018          1018             0
Difference at 95.0% confidence
	-1459 +/- 0
	-58.9019% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_object_v/time_no_builtin.txt
+ ./reports/built-ins/is_object_v/time_builtin.txt
+----------------------------------------------------------------------+
|    +                                                                 |
|  +++                                                        x      x |
|+++++ +                                                x  x  x  xx xxx|
| |_A|                                                      |____AM__| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10      10.32886     12.075588     11.600183     11.408427    0.59859611
+  10     3.2172105     3.9302121     3.6120526     3.5777129    0.20498777
Difference at 95.0% confidence
	-7.83071 +/- 0.420377
	-68.6397% +/- 3.68479%
	(Student's t, pooled s = 0.447402)
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_object_v/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_object_v/peak_mem_builtin.txt
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
x  10       1971236       1971552       1971324     1971344.8     100.66093
+  10        880104        880616        880384        880366     141.00906
Difference at 95.0% confidence
	-1.09098e+06 +/- 115.108
	-55.3419% +/- 0.00583904%
	(Student's t, pooled s = 122.508)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_object_v/total_mem_no_builtin.txt
+ ./reports/built-ins/is_object_v/total_mem_builtin.txt
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
x  10          2477          2477          2477          2477             0
+  10          1018          1018          1018          1018             0
Difference at 95.0% confidence
	-1459 +/- 0
	-58.9019% +/- 0%
	(Student's t, pooled s = 0)
```

---

