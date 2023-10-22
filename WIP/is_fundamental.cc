#include <type_traits>

#include "./Common.hpp"

#ifdef GSOC23_BENCH_A
template <typename _Tp>
struct is_fundamental
    : public std::disjunction<std::is_arithmetic<_Tp>, std::is_void<_Tp>,
                              std::is_null_pointer<_Tp> >::type
{
};
#endif
#ifdef GSOC23_BENCH_B
template <typename _Tp>
struct is_fundamental
    : public std::bool_constant<__is_arithmetic (_Tp)
                                || std::is_void<_Tp>::value
                                || std::is_null_pointer<_Tp>::value>
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
