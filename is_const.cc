#include <cstddef>

#include "./Common.hpp"

#ifdef GSOC23_BENCH_A
template <typename _Tp> inline constexpr bool is_const_v = false;
template <typename _Tp> inline constexpr bool is_const_v<const _Tp> = true;
#endif
#ifdef GSOC23_BENCH_B
template <typename _Tp> inline constexpr bool is_const_v = __is_const (_Tp);
#endif

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!is_const_v<Instantiator>);
  static_assert (is_const_v<const Instantiator>);
  static_assert (!is_const_v<volatile Instantiator>);
  static_assert (is_const_v<const volatile Instantiator>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!is_const_v<Instantiator>);
  static_assert (is_const_v<const Instantiator>);
  static_assert (!is_const_v<volatile Instantiator>);
  static_assert (is_const_v<const volatile Instantiator>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
