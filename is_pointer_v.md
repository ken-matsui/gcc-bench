## Sun Jul  9 10:39:48 PM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/87f68fe8618c83bb5c87b234dd934359231776a9/is_pointer.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230710 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
361a6fc4bc5d3073e8e19fba0af51380720e677a
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
b12e0ee48cb9b188e0e8fe48d24a0c7bb46282f0
50968079e028d6e563da195d407fd418f9e20680
```

### Time

```console
$ perf stat xg++ -c is_pointer.cc
x /tmp/tmp.OYPKGd0inb/time_before.txt
+ /tmp/tmp.OYPKGd0inb/time_after.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                  x  |
|++                                                                 x x|
|++                                                                 x x|
|++                                                                 x x|
|++                                                                xx x|
|MA                                                                 MA||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     9.2387801     9.4586466      9.303951     9.3375497    0.09175971
+  10     3.4903902     3.6144858     3.5269891     3.5357179   0.041507228
Difference at 95.0% confidence
	-5.80183 +/- 0.0669118
	-62.1344% +/- 0.716588%
	(Student's t, pooled s = 0.0712134)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_pointer.cc
x /tmp/tmp.OYPKGd0inb/peak_mem_before.txt
+ /tmp/tmp.OYPKGd0inb/peak_mem_after.txt
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
x  10       2092768       2093028       2092940     2092926.4     93.622409
+  10        995548        995800        995656        995644     72.980972
Difference at 95.0% confidence
	-1.09728e+06 +/- 78.8684
	-52.4281% +/- 0.00376833%
	(Student's t, pooled s = 83.9386)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_pointer.cc
x /tmp/tmp.OYPKGd0inb/total_mem_before.txt
+ /tmp/tmp.OYPKGd0inb/total_mem_after.txt
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
x  10          2452          2452          2452          2452             0
+  10          1138          1138          1138          1138             0
Difference at 95.0% confidence
	-1314 +/- 0
	-53.5889% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Wed Jul 12 05:56:54 PM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/cf9b29ba2c9f73259056f4ddd84694b12c1e5eac/is_pointer.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230710 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
361a6fc4bc5d3073e8e19fba0af51380720e677a
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
9699ad059847698ebd42bfd37aa3c09b4ed17e69
94f7a4e2079bdf0d14f994edd531017d4621e834
```

### Time

```console
$ perf stat xg++ -c is_pointer.cc
x /tmp/tmp.oc4oQEkEqd/time_before.txt
+ /tmp/tmp.oc4oQEkEqd/time_after.txt
+----------------------------------------------------------------------+
|+                                                                     |
|++         +  +  +++ +xxx*        x x   xx   x                       x|
|   |_________A___M____|_____________A_____________|                   |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     3.5862862     3.7885596     3.6448261      3.645138   0.061975904
+  10     3.4886965     3.5967585     3.5633557     3.5432609   0.040157785
Difference at 95.0% confidence
	-0.101877 +/- 0.0490648
	-2.79488% +/- 1.34603%
	(Student's t, pooled s = 0.0522191)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_pointer.cc
x /tmp/tmp.oc4oQEkEqd/peak_mem_before.txt
+ /tmp/tmp.oc4oQEkEqd/peak_mem_after.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                     |
|+                                                                    x|
|+                                                                    x|
|+                                                                   xx|
|+                                                                   xx|
|++                                                                  xx|
|++                                                                  xx|
|A                                                                   AM|
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1019752       1020136       1020000       1019954     120.77159
+  10        995444        995676        995528      995538.4     75.594239
Difference at 95.0% confidence
	-24415.6 +/- 94.6623
	-2.39379% +/- 0.00928103%
	(Student's t, pooled s = 100.748)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_pointer.cc
x /tmp/tmp.oc4oQEkEqd/total_mem_before.txt
+ /tmp/tmp.oc4oQEkEqd/total_mem_after.txt
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
x  10          1178          1178          1178          1178             0
+  10          1138          1138          1138          1138             0
Difference at 95.0% confidence
	-40 +/- 0
	-3.39559% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 12:22:57 AM PDT 2023

```console
$ xg++ --version
xg++ (GCC) 14.0.0 20231016 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Time

```console
$ perf stat xg++ -std=c++2b -c is_pointer_v.cc
x /tmp/tmp.jdFXo27J7C/time_no_builtin.txt
+ /tmp/tmp.jdFXo27J7C/time_builtin.txt
+----------------------------------------------------------------------+
| +           x       +          x                                     |
|+++ ++     xxxx  +  ++  x       xx                                   x|
||____M_|_A________|_____MA_________________|                          |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     3.8548788     4.5428405     4.0114779     4.0243839    0.21214624
+  10     3.7283664     3.9718619     3.7841415        3.8347    0.10912737
Difference at 95.0% confidence
	-0.189684 +/- 0.158503
	-4.71336% +/- 3.93858%
	(Student's t, pooled s = 0.168693)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -std=c++2b -c is_pointer_v.cc
x /tmp/tmp.jdFXo27J7C/peak_mem_no_builtin.txt
+ /tmp/tmp.jdFXo27J7C/peak_mem_builtin.txt
+----------------------------------------------------------------------+
|+                                                                    x|
|+                                                                    x|
|++                                                                  xx|
|++                                                                  xx|
|++                                                                  xx|
|++                                                                  xx|
|A|                                                                  AM|
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1019028       1019484       1019340     1019311.6     115.33834
+  10        996208        996580        996348      996374.4     124.53933
Difference at 95.0% confidence
	-22937.2 +/- 112.777
	-2.25026% +/- 0.011064%
	(Student's t, pooled s = 120.027)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -std=c++2b -c is_pointer_v.cc
x /tmp/tmp.jdFXo27J7C/total_mem_no_builtin.txt
+ /tmp/tmp.jdFXo27J7C/total_mem_builtin.txt
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
x  10          1184          1184          1184          1184             0
+  10          1147          1147          1147          1147             0
Difference at 95.0% confidence
	-37 +/- 0
	-3.125% +/- 0%
	(Student's t, pooled s = 0)
```

---

## Sun Oct 22 09:16:44 PM PDT 2023

### Time

```console
x ./reports/built-ins/is_pointer_v/time_no_builtin.txt
+ ./reports/built-ins/is_pointer_v/time_builtin.txt
+----------------------------------------------------------------------+
|+                      x +   +x ++xx x    + ++   +    x      +       x|
|                   |___|___________MAA____M________||                 |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.5603854     5.1598507     4.7146264      4.743916    0.18434949
+  10     4.2569437     5.0525431     4.8123094     4.7274485    0.21626771
No difference proven at 95.0% confidence
```

### Peak Memory Usage

```console
x ./reports/built-ins/is_pointer_v/peak_mem_no_builtin.txt
+ ./reports/built-ins/is_pointer_v/peak_mem_builtin.txt
+----------------------------------------------------------------------+
|++                                                                   x|
|++                                                                  xx|
|++                                                                  xx|
|++                                                                  xx|
|++                                                                 xxx|
|AM                                                                  AM|
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1018236       1018744       1018588     1018540.8     161.68886
+  10        995628        995908        995804        995774     91.937177
Difference at 95.0% confidence
	-22766.8 +/- 123.577
	-2.23524% +/- 0.0121327%
	(Student's t, pooled s = 131.521)
```

### Total Memory Usage

```console
x ./reports/built-ins/is_pointer_v/total_mem_no_builtin.txt
+ ./reports/built-ins/is_pointer_v/total_mem_builtin.txt
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
x  10          1184          1184          1184          1184             0
+  10          1147          1147          1147          1147             0
Difference at 95.0% confidence
	-37 +/- 0
	-3.125% +/- 0%
	(Student's t, pooled s = 0)
```

---

