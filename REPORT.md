# GSoC'23 Final Report

Student: Ken Matsui

Mentor: Patrick Palka

Organization: GNU Compiler Collection

## Short description

C++: Implement compiler built-ins for the standard library traits

Many C++ standard library traits are often implemented using template metaprogramming, which can result in worse compilation performance due to expensive instantiations of multiple class templates.  The most likely way to address the costly instantiations is to define compiler built-in traits and get library traits to dispatch to these built-ins.  It is also essential to conduct thorough benchmarking and compare the existing implementations with built-in traits, as there may be some library traits that are already optimal or non-built-in approaches that outperform built-ins.  Thus, the main goal of this project is to optimize the standard library traits by incorporating built-ins and investigating alternative approaches, with the aim of enhancing the compilation performance.

## What I did so far

35 patches have been created, 33 of which are awaiting review.  Those patches include not only built-in trait implementations but also improvements in how we deal with built-in trait identifiers.  Specifically, built-in traits were previously handled as registered keywords, but since keywords are limited to 8 bits (i.e., up to 255 keywords), adding hundreds of built-in traits exceeded the limit.  As increasing the limit decreased the performance of compilation, we instead used the identifier kind to handle built-in traits.  Through it, we can look up for built-ins in O(1).  Also, before our patches, the following code could not be accepted:

```cpp
#include <type_traits>

template<typename T>
struct __is_pointer : std::bool_constant<__is_pointer(T)> {};
```

However, our patches can now accept the code like this by recognizing built-in traits only with the preceding token `(` or `<` (only for `__type_pack_element`) to reduce potential breakage of existing codes.

So far, I have implemented 15 built-in traits, resulting in 24.31% compilation time improvements, 20.37% compilation peak memory improvements, and 21.81% compilation total memory improvements on average.

```console
$ python3 ./scripts/stat-builtins.py  # update `base_directory` in main to `./final-report-assets/built-ins/`
...

Overall averages:
time: 24.31%
peak_mem: 20.37%
total_mem: 21.81%
```

<p float="left">
  <img src="/final-report-assets/time.png" width="33%" />
  <img src="/final-report-assets/peak_mem.png" width="33%" /> 
  <img src="/final-report-assets/total_mem.png" width="33%" />
</p>

## The current state

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

* [libstdc++: Use __is_enum built-in trait](https://gcc.gnu.org/git/?p=gcc.git;a=commit;h=ef42efe373b012a297e534f7fb5b30e601cc7017)
* [libstdc++: Define _GLIBCXX_USE_BUILTIN_TRAIT](https://gcc.gnu.org/git/?p=gcc.git;a=commit;h=286655d04678cb61dee9cac43b139571247c4ad1)

### Under review

Overview of the patch series:

https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633775.html

* [c++: Sort built-in traits alphabetically](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633736.html)
* [c-family, c++: Look up built-in traits via identifier node](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633737.html)
* [c++: Accept the use of built-in trait identifiers](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633739.html)
* [c++: Implement __is_const built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633740.html)
* [libstdc++: Optimize std::is_const compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633749.html)
* [c++: Implement __is_volatile built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633769.html)
* [libstdc++: Optimize std::is_volatile compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633753.html)
* [c++: Implement __is_array built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633760.html)
* [libstdc++: Optimize std::is_array compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633743.html)
* [c++: Implement __is_unbounded_array built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633744.html)
* [libstdc++: Optimize std::is_unbounded_array compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633747.html)
* [c++: Implement __is_bounded_array built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633754.html)
* [libstdc++: Optimize std::is_bounded_array compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633746.html)
* [c++: Implement __is_scoped_enum built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633767.html)
* [libstdc++: Optimize std::is_scoped_enum compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633741.html)
* [c++: Implement __is_member_pointer built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633759.html)
* [libstdc++: Optimize std::is_member_pointer compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633745.html)
* [c++: Implement __is_member_function_pointer built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633758.html)
* [libstdc++: Optimize std::is_member_function_pointer compilation](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633748.html)
* [c++: Implement __is_member_object_pointer built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633764.html)
* [libstdc++: Optimize std::is_member_object_pointer compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633751.html)
* [c++: Implement __is_reference built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633755.html)
* [libstdc++: Optimize std::is_reference compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633768.html)
* [c++: Implement __is_function built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633757.html)
* [libstdc++: Optimize std::is_function compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633742.html)
* [c++: Implement __is_object built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633756.html)
* [libstdc++: Optimize std::is_object compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633761.html)
* [c++: Implement __remove_pointer built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633752.html)
* [libstdc++: Optimize std::remove_pointer compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633766.html)
* [c++: Implement __is_pointer built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633750.html)
* [libstdc++: Optimize std::is_pointer compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633762.html)
* [c++: Implement __is_invocable built-in trait](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633765.html)
* [libstdc++: Optimize std::is_invocable compilation performance](https://gcc.gnu.org/pipermail/gcc-patches/2023-October/633776.html)

## Any challenges or important things I learned during the project

