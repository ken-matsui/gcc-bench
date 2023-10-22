#include <type_traits>

#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (
      std::is_member_function_pointer_v<int (Instantiator::*) (int)>);
  static_assert (
      std::is_member_function_pointer_v<int (Instantiator::*) (int) const>);
  static_assert (
      std::is_member_function_pointer_v<int (Instantiator::*) (float, ...)>);
  static_assert (std::is_member_function_pointer_v<
                 Instantiator (Instantiator::*) (Instantiator)>);
  static_assert (std::is_member_function_pointer_v<
                 float (Instantiator::*) (int, float, int[], int &)>);

  static_assert (!std::is_member_function_pointer_v<int>);
  static_assert (!std::is_member_function_pointer_v<Instantiator>);
  static_assert (!std::is_member_function_pointer_v<int (Instantiator::*)>);
  static_assert (
      !std::is_member_function_pointer_v<Instantiator (Instantiator::*)>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (
      std::is_member_function_pointer_v<int (Instantiator::*) (int)>);
  static_assert (
      std::is_member_function_pointer_v<int (Instantiator::*) (int) const>);
  static_assert (
      std::is_member_function_pointer_v<int (Instantiator::*) (float, ...)>);
  static_assert (std::is_member_function_pointer_v<
                 Instantiator (Instantiator::*) (Instantiator)>);
  static_assert (std::is_member_function_pointer_v<
                 float (Instantiator::*) (int, float, int[], int &)>);

  static_assert (!std::is_member_function_pointer_v<int>);
  static_assert (!std::is_member_function_pointer_v<Instantiator>);
  static_assert (!std::is_member_function_pointer_v<int (Instantiator::*)>);
  static_assert (
      !std::is_member_function_pointer_v<Instantiator (Instantiator::*)>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
