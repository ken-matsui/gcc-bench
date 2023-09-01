#include <type_traits>

#include "./Common.hpp"

#ifdef GSOC23_BENCH_A
template <typename T>
struct is_fundamental
    : public std::bool_constant<
          __is_arithmetic (T)
          || std::__or_<std::is_void<T>, std::is_null_pointer<T> >::value>
{
};
#endif
#ifdef GSOC23_BENCH_B
template <typename T>
struct is_fundamental
    : public std::bool_constant<__is_arithmetic (T) || std::is_void<T>::value
                                || std::is_null_pointer<T>::value>
{
};
#endif

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (is_fundamental<int>::value);
  static_assert (is_fundamental<void>::value);
  static_assert (is_fundamental<std::nullptr_t>::value);
  static_assert (!is_fundamental<Instantiator>::value);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (is_fundamental<int>::value);
  static_assert (is_fundamental<void>::value);
  static_assert (is_fundamental<std::nullptr_t>::value);
  static_assert (!is_fundamental<Instantiator>::value);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
