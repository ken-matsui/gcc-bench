#include <type_traits>

#include "./Common.hpp"

#ifdef GSOC23_BENCH_A
template <typename _Tp>
inline constexpr bool is_member_function_pointer_v
    = std::is_member_function_pointer<_Tp>::value;
#endif
#ifdef GSOC23_BENCH_B
template <typename _Tp>
inline constexpr bool is_member_function_pointer_v
    = __is_member_function_pointer (_Tp);
#endif

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (is_member_function_pointer_v<int (Instantiator::*) (int)>);
  static_assert (
      is_member_function_pointer_v<int (Instantiator::*) (int) const>);
  static_assert (
      is_member_function_pointer_v<int (Instantiator::*) (float, ...)>);
  static_assert (is_member_function_pointer_v<
                 Instantiator (Instantiator::*) (Instantiator)>);
  static_assert (is_member_function_pointer_v<
                 float (Instantiator::*) (int, float, int[], int &)>);

  static_assert (!is_member_function_pointer_v<int>);
  static_assert (!is_member_function_pointer_v<Instantiator>);
  static_assert (!is_member_function_pointer_v<int (Instantiator::*)>);
  static_assert (
      !is_member_function_pointer_v<Instantiator (Instantiator::*)>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (is_member_function_pointer_v<int (Instantiator::*) (int)>);
  static_assert (
      is_member_function_pointer_v<int (Instantiator::*) (int) const>);
  static_assert (
      is_member_function_pointer_v<int (Instantiator::*) (float, ...)>);
  static_assert (is_member_function_pointer_v<
                 Instantiator (Instantiator::*) (Instantiator)>);
  static_assert (is_member_function_pointer_v<
                 float (Instantiator::*) (int, float, int[], int &)>);

  static_assert (!is_member_function_pointer_v<int>);
  static_assert (!is_member_function_pointer_v<Instantiator>);
  static_assert (!is_member_function_pointer_v<int (Instantiator::*)>);
  static_assert (
      !is_member_function_pointer_v<Instantiator (Instantiator::*)>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
