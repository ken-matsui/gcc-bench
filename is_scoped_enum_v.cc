#include <type_traits>

#include "./Common.hpp"

#ifdef GSOC23_BENCH_A
template <typename _Tp>
inline constexpr bool is_scoped_enum_v = std::is_scoped_enum<_Tp>::value;
#endif
#ifdef GSOC23_BENCH_B
template <typename _Tp>
inline constexpr bool is_scoped_enum_v = __is_scoped_enum (_Tp);
#endif

enum class E
{
  e1,
  e2
};
enum U
{
  u1,
  u2
};

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (is_scoped_enum_v<E>);
  static_assert (is_scoped_enum_v<const E>);
  static_assert (is_scoped_enum_v<volatile E>);
  static_assert (is_scoped_enum_v<const volatile E>);

  static_assert (!is_scoped_enum_v<U>);
  static_assert (!is_scoped_enum_v<const U>);
  static_assert (!is_scoped_enum_v<volatile U>);
  static_assert (!is_scoped_enum_v<const volatile U>);

  static_assert (!is_scoped_enum_v<Instantiator>);
  static_assert (!is_scoped_enum_v<const Instantiator>);
  static_assert (!is_scoped_enum_v<volatile Instantiator>);
  static_assert (!is_scoped_enum_v<const volatile Instantiator>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (is_scoped_enum_v<E>);
  static_assert (is_scoped_enum_v<const E>);
  static_assert (is_scoped_enum_v<volatile E>);
  static_assert (is_scoped_enum_v<const volatile E>);

  static_assert (!is_scoped_enum_v<U>);
  static_assert (!is_scoped_enum_v<const U>);
  static_assert (!is_scoped_enum_v<volatile U>);
  static_assert (!is_scoped_enum_v<const volatile U>);

  static_assert (!is_scoped_enum_v<Instantiator>);
  static_assert (!is_scoped_enum_v<const Instantiator>);
  static_assert (!is_scoped_enum_v<volatile Instantiator>);
  static_assert (!is_scoped_enum_v<const volatile Instantiator>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
