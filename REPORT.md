# GSoC'23 Final Report

Student: Ken Matsui

Mentor: Patrick Palka

Organization: GNU Compiler Collection

## Short description

C++: Implement compiler built-ins for the standard library traits

Many C++ standard library traits are often implemented using template metaprogramming, which can result in worse compilation performance due to expensive instantiations of multiple class templates.  The most likely way to address the costly instantiations is to define compiler built-in traits and get library traits to dispatch to these built-ins.  It is also essential to conduct thorough benchmarking and compare the existing implementations with built-in traits, as there may be some library traits that are already optimal or non-built-in approaches that outperform built-ins.  Thus, the main goal of this project is to optimize the standard library traits by incorporating built-ins and investigating alternative approaches, with the aim of enhancing the compilation performance.

## What I did so far

I have created a total of 35 patches, out of which 33 are currently waiting for review.  These patches not only include the implementation of built-in traits, but also address the issue of handling built-in trait identifiers more efficiently.  Earlier, built-in traits were handled as registered keywords, but since number of keywords is limited to 8 bits (i.e., up to 255 keywords), adding built-in traits though our project exceeded the limit.  As increasing the limit had a negative impact on the compilation performance, we decided to use the identifier kind to handle built-in traits instead.  With this approach, we can look up built-ins in O(1) time complexity.  Also, our patches now allow for the acceptance of code that was not previously possible:

```cpp
#include <type_traits>

template<typename T>
struct __is_pointer : std::bool_constant<__is_pointer(T)> {};
```

Before our patches, the above code could not be accepted.  Our patches, however, can now accept the code like this by recognizing built-in traits only with the preceding token `(` or `<` (only for `__type_pack_element`) to reduce potential breakage of existing codes.

I have implemented 15 built-in traits so far, resulting in significant improvements in compilation time, peak memory usage during compilation, and total memory usage during compilation.

## The current state

On average, I have seen a 24.31% improvement in compilation time, a 20.37% improvement in peak memory usage, and a 21.81% improvement in total memory usage.

```console
$ python3 ./scripts/stat-builtins.py  # update `base_directory` in main to `./final-report-assets/builtins/`
...

Overall averages:
time: 24.31%
peak_mem: 20.37%
total_mem: 21.81%
```

<p align="center">
  <img src="/final-report-assets/time.png" width="45%" />
</p>

<p align="center">
  <img src="/final-report-assets/peak_mem.png" width="45%" /> 
  <img src="/final-report-assets/total_mem.png" width="45%" />
</p>

Most patches are still under review.

## What's left to do

Implement the following remaining built-in traits:

* is(_nothrow)_invocable(_r)
* invoke_result
* is_integral
* add_lvalue_reference
* add_rvalue_reference
* is_floating_point
* add_pointer
* negation
* remove_extent
* remove_all_extent
* extent
* make_signed
* make_unsigned
* decay
* rank
* is_arithmetic
* is_fundamental
* is_compound
* is_unsigned
* is_signed
* is_scalar

The following traits need research on if it is possible to implement:

* common_type
* common_reference
* is_destructible
* is_swappable
* aligned_storage
* aligned_union
* result_of
* conjunction
* disjunction

## What code got merged (or not) upstream

### Merged

1. [libstdc++: Use __is_enum built-in trait](https://gcc.gnu.org/git/?p=gcc.git;a=commit;h=ef42efe373b012a297e534f7fb5b30e601cc7017)
2. [libstdc++: Define _GLIBCXX_USE_BUILTIN_TRAIT](https://gcc.gnu.org/git/?p=gcc.git;a=commit;h=286655d04678cb61dee9cac43b139571247c4ad1)

### Under review

Overview of the patch series:

https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633775.html

1. [c++: Sort built-in traits alphabetically](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633736.html)
2. [c-family, c++: Look up built-in traits via identifier node](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633737.html)
3. [c++: Accept the use of built-in trait identifiers](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633739.html)
4. [c++: Implement __is_const built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633740.html)
5. [libstdc++: Optimize std::is_const compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633749.html)
6. [c++: Implement __is_volatile built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633769.html)
7. [libstdc++: Optimize std::is_volatile compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633753.html)
8. [c++: Implement __is_array built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633760.html)
9. [libstdc++: Optimize std::is_array compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633743.html)
10. [c++: Implement __is_unbounded_array built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633744.html)
11. [libstdc++: Optimize std::is_unbounded_array compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633747.html)
12. [c++: Implement __is_bounded_array built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633754.html)
13. [libstdc++: Optimize std::is_bounded_array compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633746.html)
14. [c++: Implement __is_scoped_enum built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633767.html)
15. [libstdc++: Optimize std::is_scoped_enum compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633741.html)
16. [c++: Implement __is_member_pointer built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633759.html)
17. [libstdc++: Optimize std::is_member_pointer compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633745.html)
18. [c++: Implement __is_member_function_pointer built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633758.html)
19. [libstdc++: Optimize std::is_member_function_pointer compilation](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633748.html)
20. [c++: Implement __is_member_object_pointer built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633764.html)
21. [libstdc++: Optimize std::is_member_object_pointer compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633751.html)
22. [c++: Implement __is_reference built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633755.html)
23. [libstdc++: Optimize std::is_reference compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633768.html)
24. [c++: Implement __is_function built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633757.html)
25. [libstdc++: Optimize std::is_function compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633742.html)
26. [c++: Implement __is_object built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633756.html)
27. [libstdc++: Optimize std::is_object compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633761.html)
28. [c++: Implement __remove_pointer built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633752.html)
29. [libstdc++: Optimize std::remove_pointer compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633766.html)
30. [c++: Implement __is_pointer built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633750.html)
31. [libstdc++: Optimize std::is_pointer compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633762.html)
32. [c++: Implement __is_invocable built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633765.html)
33. [libstdc++: Optimize std::is_invocable compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633776.html)

## Any challenges or important things I learned during the project



## Acknowledgment

Firstly, I wish to express my profound gratitude to Patrick Palka, my mentor, for his continuous support, patience, and guidance throughout the course of this project.  His insights and expertise have been invaluable to the evolution and success of this project.

I would also like to extend my gratitude to the reviewers of my code, in particular Jonathan Wakely and Jason Merrill, as well as my mentor, for providing constructive criticism, insights, and suggestions.  Their thorough examination and feedback have significantly improved the quality of the final patches.

In addition, I am grateful to the myriad of contributors on the GCC mailing list.  Their prompt assistance, insightful discussions, and shared experiences have enriched this project and contributed significantly to its fruition.

## Related Links

* https://summerofcode.withgoogle.com/programs/2023/projects/SuvI1tlp
* https://github.com/ken-matsui/gsoc23
* https://github.com/ken-matsui/gcc-gsoc23
