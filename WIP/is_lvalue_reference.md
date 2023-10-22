## Tue Jul 18 03:37:08 PM PDT 2023

https://github.com/ken-matsui/gcc-benches/blob/c842c329ecaadeeab0093e9187e71317935facb8/is_lvalue_reference.cc


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
$ perf stat xg++ -c is_lvalue_reference.cc
x /tmp/tmp.l3LvTkcBzm/time_before.txt
+ /tmp/tmp.l3LvTkcBzm/time_after.txt
+----------------------------------------------------------------------+
| x                  +                 x                               |
|xx x  x       ++    +         x    x xx     +       ++  +          + +|
| |_________________|__________M______|___A__________M__________|      |
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10     3.3455646     3.4237918     3.4076759     3.3843574   0.036949056
+  10     3.3734433     3.4878366     3.4526346     3.4301923   0.045171782
Difference at 95.0% confidence
	0.0458349 +/- 0.0387731
	1.35432% +/- 1.14566%
	(Student's t, pooled s = 0.0412657)
```

### Peak Memory Usage

```console
$ /usr/bin/time -v xg++ -c is_lvalue_reference.cc
x /tmp/tmp.l3LvTkcBzm/peak_mem_before.txt
+ /tmp/tmp.l3LvTkcBzm/peak_mem_after.txt
+----------------------------------------------------------------------+
|       +                                                            x |
|++     +                                                    x      xx |
|++   + +++                                            x  x  x      xxx|
| |___A_M|                                                 |_____A__M_||
+----------------------------------------------------------------------+
    N           Min           Max        Median           Avg        Stddev
x  10       1008712       1008972       1008948     1008882.4     94.679812
+  10       1007760       1007912       1007888     1007840.4     62.778624
Difference at 95.0% confidence
	-1042 +/- 75.4766
	-0.103283% +/- 0.00748121%
	(Student's t, pooled s = 80.3288)
```

### Total Memory Usage

```console
$ xg++ -ftime-report -c is_lvalue_reference.cc
x /tmp/tmp.l3LvTkcBzm/total_mem_before.txt
+ /tmp/tmp.l3LvTkcBzm/total_mem_after.txt
[no plot, span is zero width]
    N           Min           Max        Median           Avg        Stddev
x  10          1186          1186          1186          1186             0
+  10          1186          1186          1186          1186             0
No difference proven at 95.0% confidence
```

---

