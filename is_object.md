## Mon Jun 19 10:31:57 PM PDT 2023

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

