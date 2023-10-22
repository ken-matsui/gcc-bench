#include <type_traits>

#include "./Common.hpp"

#ifdef GSOC23_BENCH_A
template <typename _Tp> inline constexpr bool is_pointer_v = false;
template <typename _Tp> inline constexpr bool is_pointer_v<_Tp *> = true;
template <typename _Tp> inline constexpr bool is_pointer_v<_Tp *const> = true;
template <typename _Tp>
inline constexpr bool is_pointer_v<_Tp *volatile> = true;
template <typename _Tp>
inline constexpr bool is_pointer_v<_Tp *const volatile> = true;
#endif
#ifdef GSOC23_BENCH_B
template <typename T> inline constexpr bool is_pointer_v = __is_pointer (T);
#endif

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!is_pointer_v<Instantiator>);
  static_assert (!is_pointer_v<const Instantiator>);
  static_assert (!is_pointer_v<volatile Instantiator>);
  static_assert (!is_pointer_v<const volatile Instantiator>);
  static_assert (is_pointer_v<Instantiator *>);
  static_assert (is_pointer_v<const Instantiator *>);
  static_assert (is_pointer_v<volatile Instantiator *>);
  static_assert (is_pointer_v<const volatile Instantiator *>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!is_pointer_v<Instantiator>);
  static_assert (!is_pointer_v<const Instantiator>);
  static_assert (!is_pointer_v<volatile Instantiator>);
  static_assert (!is_pointer_v<const volatile Instantiator>);
  static_assert (is_pointer_v<Instantiator *>);
  static_assert (is_pointer_v<const Instantiator *>);
  static_assert (is_pointer_v<volatile Instantiator *>);
  static_assert (is_pointer_v<const volatile Instantiator *>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
