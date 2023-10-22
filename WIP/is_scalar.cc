#include <cstddef>
#include <type_traits>

#include "./Common.hpp"

template <typename _Tp>
struct is_scalar
    : public std::disjunction<
          std::is_arithmetic<_Tp>, std::is_enum<_Tp>, std::is_pointer<_Tp>,
          std::is_member_pointer<_Tp>, std::is_null_pointer<_Tp> >::type
{
};

#ifdef GSOC23_BENCH_A
template <typename T> inline constexpr bool is_scalar_v = is_scalar<T>::value;
#endif
#ifdef GSOC23_BENCH_B
template <typename T> inline constexpr bool is_scalar_v = __is_scalar (T);
#endif

enum EnumType
{
  e0
};

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (is_scalar_v<int>);
  static_assert (is_scalar_v<float>);
  static_assert (is_scalar_v<EnumType>);
  static_assert (is_scalar_v<int *>);
  static_assert (is_scalar_v<int (*) (int)>);
  static_assert (is_scalar_v<int (Instantiator::*)>);
  static_assert (is_scalar_v<int (Instantiator::*) (int)>);
  static_assert (is_scalar_v<std::nullptr_t>);
  static_assert (!is_scalar_v<Instantiator>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (is_scalar_v<int>);
  static_assert (is_scalar_v<float>);
  static_assert (is_scalar_v<EnumType>);
  static_assert (is_scalar_v<int *>);
  static_assert (is_scalar_v<int (*) (int)>);
  static_assert (is_scalar_v<int (Instantiator::*)>);
  static_assert (is_scalar_v<int (Instantiator::*) (int)>);
  static_assert (is_scalar_v<std::nullptr_t>);
  static_assert (!is_scalar_v<Instantiator>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
