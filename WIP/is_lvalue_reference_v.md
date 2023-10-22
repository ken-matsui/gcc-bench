## Tue Jul 18 03:42:36 PM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/c842c329ecaadeeab0093e9187e71317935facb8/is_lvalue_reference_v.cc


```console
$ xg++ --version
xg++ (GCC) 14.0.0 20230718 (experimental)
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

```console
$ git rev-parse HEAD~10  # base commit
0a9f30c50a1ee539372fb4f6db3e8db229fc2ff8
```

```console
$ git log -n 10 --pretty=format:%H  # changes from the base
0630c6012b49e50be1880dc5ff7eeffcbe2dcd4f
1e9587a4858060fe562ad43154b0b2e332b79f63
49f67fa2a3d55c72cf776280a33758fd5f349edc
63bd6bc09aea027ea2220c3bb2b7aa21e2ce8eef
652cbcd0e12a3fd66f58d8cfe9242778674d4e0c
5c79f919eac8090876ce94dd336b9c9a415dbfe9
c05c2894568bcf466221bc729c3063891698d613
18106f7b1aebddadf2fb15bcdd200ae991aff58b
04a699f2234dcb1b5e3d963d48ffa602c9ee2b71
cf97e85afcacf82c1257b958813cbde585ff9bcd
```

### Time

```console
$ perf stat xg++ -c is_lvalue_reference_v.cc
x /tmp/tmp.OtdYfueKnI/time_before.txt
+ /tmp/tmp.OtdYfueKnI/time_after.txt
+----------------------------------------------------------------------+
|+ +  +              x x   x       x+   ++    ++ *x     x     x      x+|
|          |___________|__________A______M_______M_______|_|           |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     2.7773561     2.8569484     2.8236825     2.8110121   0.030113476
+  10     2.7437415     2.8594013     2.8106256     2.7990369    0.03852083
No difference proven at 95.0% confidence
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_lvalue_reference_v.cc
x /tmp/tmp.OtdYfueKnI/peak_mem_before.txt
+ /tmp/tmp.OtdYfueKnI/peak_mem_after.txt
+----------------------------------------------------------------------+
| +                                                                    |
| +                                                               xx   |
|++ ++                                                            xx xx|
|++ ++                                                            xx xx|
||MA|                                                             |MA| |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10        898600        898856        898708        898724     99.223653
+  10        894780        894996        894852      894887.6     84.020104
Difference at 95.0% confidence
	-3836.4 +/- 86.3833
	-0.426872% +/- 0.00961177%
	(Student's t, pooled s = 91.9367)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_lvalue_reference_v.cc
x /tmp/tmp.OtdYfueKnI/total_mem_before.txt
+ /tmp/tmp.OtdYfueKnI/total_mem_after.txt
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
x  10          1033          1033          1033          1033             0
+  10          1026          1026          1026          1026             0
Difference at 95.0% confidence
	-7 +/- 0
	-0.677638% +/- 0%
	(Student's t, pooled s = 0)
```

---

