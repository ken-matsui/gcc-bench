## Sat Jul  8 04:15:10 AM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/881a44e393daf373f1e1ef96855f2321607ee88d/is_unsigned.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230708 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~2  # base commit
01405f01087b05d71a1f3bd1d4272bec332aeb58
```

```console
$ git log -n 2 --pretty=format:%H  # changes from the base
b2f387ec4f6557b12ec4764592a77e411680592c
e49563f190fa0ccea6227321667da455644d9939
```

### Time

```console
$ perf stat xg++ -c is_unsigned.cc
x /tmp/tmp.ECn34kUT8x/time_before.txt
+ /tmp/tmp.ECn34kUT8x/time_after.txt
+----------------------------------------------------------------------+
|++                                                                    |
|++                                                                x   |
|++                                                                x   |
|++                                                                xxxx|
|++                                                                xxxx|
||A                                                                |A| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     9.8970355     10.181023     9.9543783     10.005721    0.11044766
+  10     3.2510135         3.394     3.3098354     3.3110943   0.059826936
Difference at 95.0% confidence
	-6.69463 +/- 0.0834548
	-66.908% +/- 0.834071%
	(Student's t, pooled s = 0.0888199)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_unsigned.cc
x /tmp/tmp.ECn34kUT8x/peak_mem_before.txt
+ /tmp/tmp.ECn34kUT8x/peak_mem_after.txt
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
x  10       1368704       1369032       1368900       1368862     99.746345
+  10        786812        787084        786940      786905.2     87.717729
Difference at 95.0% confidence
	-581957 +/- 88.2513
	-42.5139% +/- 0.00644706%
	(Student's t, pooled s = 93.9248)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_unsigned.cc
x /tmp/tmp.ECn34kUT8x/total_mem_before.txt
+ /tmp/tmp.ECn34kUT8x/total_mem_after.txt
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
x  10          1780          1780          1780          1780             0
+  10           955           955           955           955             0
Difference at 95.0% confidence
	-825 +/- 0
	-46.3483% +/- 0%
	(Student's t, pooled s = 0)
```

---

