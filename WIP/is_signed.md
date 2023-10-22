## Sun Jul  9 01:47:07 AM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/1a8acd529d62de3c319999c0a1e575ec50d7add7/is_signed.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230709 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
95b712928b479f7a65910cf1c550ed67b8976617
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
8e56cfff36415b33a5a580f65518865e70e49688
457e17a312e26ee2d416ed9de16994c1b7f9416f
```

### Time

```console
$ perf stat xg++ -c is_signed.cc
x /tmp/tmp.mHJZMLlRKM/time_before.txt
+ /tmp/tmp.mHJZMLlRKM/time_after.txt
+----------------------------------------------------------------------+
|+                                                                     |
|+                                                                     |
|+ +                                                                   |
|+++                                                          xxx     x|
|+++                                                         xxxxx    x|
||A|                                                         |__A__|   |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     4.8554246     5.2770445     4.9694751     5.0053913    0.14603619
+  10     1.9881776     2.0928469     2.0481691      2.030237    0.04009556
Difference at 95.0% confidence
	-2.97515 +/- 0.100616
	-59.439% +/- 2.01016%
	(Student's t, pooled s = 0.107085)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_signed.cc
x /tmp/tmp.mHJZMLlRKM/peak_mem_before.txt
+ /tmp/tmp.mHJZMLlRKM/peak_mem_after.txt
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
x  10       1381172       1381360       1381220     1381240.8     69.507475
+  10        849124        849400        849264        849246     87.984847
Difference at 95.0% confidence
	-531995 +/- 74.497
	-38.5157% +/- 0.00539349%
	(Student's t, pooled s = 79.2863)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_signed.cc
x /tmp/tmp.mHJZMLlRKM/total_mem_before.txt
+ /tmp/tmp.mHJZMLlRKM/total_mem_after.txt
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
x  10          1636          1636          1636          1636             0
+  10           954           954           954           954             0
Difference at 95.0% confidence
	-682 +/- 0
	-41.687% +/- 0%
	(Student's t, pooled s = 0)
```

---

