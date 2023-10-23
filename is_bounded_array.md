## Sat Oct 21 07:43:02 PM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_bounded_array.cc
x /tmp/tmp.cRO6FDhoSh/time_no_builtin.txt
+ /tmp/tmp.cRO6FDhoSh/time_builtin.txt
+----------------------------------------------------------------------+
| +    ++ ++    +  x *   x   +                  x+  xx   x        x +xx|
||______________M_____A_____|______________|____A____M______________|  |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     34.720051     37.512611     36.608516      36.32055     1.0763651
+  10      33.82108     37.380262     34.562138     34.901726      1.145242
Difference at 95.0% confidence
	-1.41882 +/- 1.04421
	-3.90639% +/- 2.87498%
	(Student's t, pooled s = 1.11134)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_bounded_array.cc
x /tmp/tmp.cRO6FDhoSh/peak_mem_no_builtin.txt
+ /tmp/tmp.cRO6FDhoSh/peak_mem_builtin.txt
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
x  10       4788332       4788752       4788636     4788553.6     182.10815
+  10       4725676       4726104       4725900     4725871.2     155.52406
Difference at 95.0% confidence
	-62682.4 +/- 159.11
	-1.309% +/- 0.00332271%
	(Student's t, pooled s = 169.339)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_bounded_array.cc
x /tmp/tmp.cRO6FDhoSh/total_mem_no_builtin.txt
+ /tmp/tmp.cRO6FDhoSh/total_mem_builtin.txt
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
x  10          6062          6062          6062          6062             0
+  10          5815          5815          5815          5815             0
Difference at 95.0% confidence
	-247 +/- 0
	-4.07456% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_bounded_array/time_no_builtin.txt
+ ./reports/built-ins/is_bounded_array/time_builtin.txt
+----------------------------------------------------------------------+
|+ +++            *  +      x  x+ +    +x    x+   x               x  xx|
|  |________________AM_|_____________|_____A_M__________________|      |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     35.150388      40.79389     38.108922     37.931424      2.174932
+  10     33.342434     38.167897     35.455992     35.409921     1.8068318
Difference at 95.0% confidence
	-2.5215 +/- 1.8786
	-6.64753% +/- 4.95262%
	(Student's t, pooled s = 1.99937)
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_bounded_array/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_bounded_array/peak_mem_builtin.txt
+----------------------------------------------------------------------+
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|+                                                                    x|
|++                                                                  xx|
|A                                                                    A|
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       4787448       4787996       4787732     4787722.8     154.22984
+  10       4724876       4725336       4725040       4725048     135.86922
Difference at 95.0% confidence
	-62674.8 +/- 136.561
	-1.30907% +/- 0.00285231%
	(Student's t, pooled s = 145.34)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_bounded_array/total_mem_no_builtin.txt
+ ./reports/built-ins/is_bounded_array/total_mem_builtin.txt
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
x  10          6062          6062          6062          6062             0
+  10          5815          5815          5815          5815             0
Difference at 95.0% confidence
	-247 +/- 0
	-4.07456% +/- 0%
	(Student's t, pooled s = 0)
```

---

