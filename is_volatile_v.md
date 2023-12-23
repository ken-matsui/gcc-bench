## Sat Jun 24 07:40:36 AM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/4c4310e08be128f5781a76e27815696fc5fe775f/is_volatile.cc

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230624 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
31b7659995caccca626709ecb634339f75980ff2
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
9aa3c857842984a307c959278ccb7491cb4efe21
7c332d241cfe6be2fa6b22456a564e0c03b8cbf3
```

### Time

```console
$ perf stat xg++ -c is_volatile.cc
x /tmp/tmp.IAvyC5OMf7/time_before.txt
+ /tmp/tmp.IAvyC5OMf7/time_after.txt
+----------------------------------------------------------------------+
|+  +++   +     +          xx x   +*      ++                     x x  x|
|  |____________M___A___|__________M_|_______A___________________|     |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     2.8518002     2.9742907     2.8745644     2.9021609   0.057199974
+  10     2.7789344     2.8969829     2.8215754     2.8318313   0.047785726
Difference at 95.0% confidence
	-0.0703296 +/- 0.04952
	-2.42335% +/- 1.70631%
	(Student's t, pooled s = 0.0527035)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_volatile.cc
x /tmp/tmp.IAvyC5OMf7/peak_mem_before.txt
+ /tmp/tmp.IAvyC5OMf7/peak_mem_after.txt
+----------------------------------------------------------------------+
|  +                                                                   |
|  +                                                                 x |
|  +                                                                 x |
|  +                                                                 x |
|+ +                                                                xxx|
|++++                                                              xxxx|
| AM                                                                |A||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10        910980        911364        911244      911204.8     124.59071
+  10        901188        901576        901424      901395.6     122.03388
Difference at 95.0% confidence
	-9809.2 +/- 115.87
	-1.07651% +/- 0.0127161%
	(Student's t, pooled s = 123.319)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_volatile.cc
x /tmp/tmp.IAvyC5OMf7/total_mem_before.txt
+ /tmp/tmp.IAvyC5OMf7/total_mem_after.txt
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
x  10          1047          1047          1047          1047             0
+  10          1030          1030          1030          1030             0
Difference at 95.0% confidence
	-17 +/- 0
	-1.62369% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 01:26:25 AM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_volatile_v.cc
x /tmp/tmp.oFeMkAwSaW/time_no_builtin.txt
+ /tmp/tmp.oFeMkAwSaW/time_builtin.txt
+----------------------------------------------------------------------+
|        x              +                                              |
|  +     x              ++                                             |
|+ ++ x xx   x          ++  +      x     x        x                   x|
| |__|_______M__A_______MA__|___________________|                      |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     2.9725935     3.5246324     3.0300143     3.1351698    0.19508824
+  10     2.9272503     3.1602678     3.1286058     3.0578955    0.10020114
No difference proven at 95.0% confidence
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_volatile_v.cc
x /tmp/tmp.oFeMkAwSaW/peak_mem_no_builtin.txt
+ /tmp/tmp.oFeMkAwSaW/peak_mem_builtin.txt
+----------------------------------------------------------------------+
|  +                                                                   |
|  +                                                                   |
|+ +                                                               xxx |
|+++                                                               xxx |
|+++                                                               xxxx|
| AM                                                               |A| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10        911260        911488        911364      911350.8     66.960685
+  10        905952        906092        906076      906046.8     53.766573
Difference at 95.0% confidence
	-5304 +/- 57.0551
	-0.581993% +/- 0.0062605%
	(Student's t, pooled s = 60.7231)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_volatile_v.cc
x /tmp/tmp.oFeMkAwSaW/total_mem_no_builtin.txt
+ /tmp/tmp.oFeMkAwSaW/total_mem_builtin.txt
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
x  10          1053          1053          1053          1053             0
+  10          1045          1045          1045          1045             0
Difference at 95.0% confidence
	-8 +/- 0
	-0.759734% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_volatile_v/time_no_builtin.txt
+ ./reports/built-ins/is_volatile_v/time_builtin.txt
+----------------------------------------------------------------------+
|x    x   x        +   x x +xx+    +      ++x +   ++x    +            x|
|      |____________________|A__________A__M______|_|                  |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     3.3293151       4.08098     3.6194359     3.6305969     0.2336407
+  10     3.5307851     3.9366232     3.7919022     3.7554129    0.13002218
No difference proven at 95.0% confidence
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_volatile_v/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_volatile_v/peak_mem_builtin.txt
+----------------------------------------------------------------------+
| +   +                                                              x |
| +  ++                                                            x xx|
|++ +++                                                           xxxxx|
| |_AM|                                                            |AM||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10        910648        911016        910900        910874     120.16655
+  10        904776        905268        905100      905044.8     181.44898
Difference at 95.0% confidence
	-5829.2 +/- 144.594
	-0.639957% +/- 0.0158742%
	(Student's t, pooled s = 153.889)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_volatile_v/total_mem_no_builtin.txt
+ ./reports/built-ins/is_volatile_v/total_mem_builtin.txt
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
x  10          1052          1052          1052          1052             0
+  10          1045          1045          1045          1045             0
Difference at 95.0% confidence
	-7 +/- 0
	-0.665399% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sat Dec 23 09:15:18 AM PST 2023

### Time

```console
x ./reports/builtins/is_volatile_v/time_no_builtin.txt
+ ./reports/builtins/is_volatile_v/time_builtin.txt
+----------------------------------------------------------------------+
|    +                                                                 |
|++  ++ + +++              +              xx x       x xx      x x  x x|
||______MA______|                             |_________A_________|    |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     3.0499187     3.1243953     3.0862962     3.0874403   0.027531939
+  10     2.9418402      3.009593     2.9595272     2.9618384   0.019462435
Difference at 95.0% confidence
	-0.125602 +/- 0.022401
	-4.06816% +/- 0.725552%
	(Student's t, pooled s = 0.0238411)
```

### Peak Memory Usage

```console
x ./reports/builtins/is_volatile_v/peak_mem_no_builtin.txt
+ ./reports/builtins/is_volatile_v/peak_mem_builtin.txt
+----------------------------------------------------------------------+
| +                                                                   x|
|++                                                                 x x|
|+++                                                                x x|
|++++                                                             xxxxx|
||A|                                                               |AM||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10        915760        916136        916032      916005.6     126.90084
+  10        910332        910568        910424      910424.4     76.232394
Difference at 95.0% confidence
	-5581.2 +/- 98.3555
	-0.609298% +/- 0.0107374%
	(Student's t, pooled s = 104.679)
```

### Total Memory Usage

```console
x ./reports/builtins/is_volatile_v/total_mem_no_builtin.txt
+ ./reports/builtins/is_volatile_v/total_mem_builtin.txt
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
x  10          1062          1062          1062          1062             0
+  10          1055          1055          1055          1055             0
Difference at 95.0% confidence
	-7 +/- 0
	-0.659134% +/- 0%
	(Student's t, pooled s = 0)
```

---

