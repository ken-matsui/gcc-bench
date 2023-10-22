#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (std::is_member_pointer<int (Instantiator::*)>::value);
  static_assert (std::is_member_pointer<const int (Instantiator::*)>::value);
  static_assert (
      std::is_member_pointer<volatile int (Instantiator::*)>::value);
  static_assert (
      std::is_member_pointer<const volatile int (Instantiator::*)>::value);

  static_assert (
      std::is_member_pointer<Instantiator (Instantiator::*)>::value);
  static_assert (
      std::is_member_pointer<const Instantiator (Instantiator::*)>::value);
  static_assert (
      std::is_member_pointer<volatile Instantiator (Instantiator::*)>::value);
  static_assert (std::is_member_pointer<
                 const volatile Instantiator (Instantiator::*)>::value);

  static_assert (std::is_member_pointer<int (Instantiator::*) (int)>::value);
  static_assert (
      std::is_member_pointer<int (Instantiator::*) (int) const>::value);

  static_assert (
      std::is_member_pointer<int (Instantiator::*) (float, ...)>::value);
  static_assert (
      std::is_member_pointer<int (Instantiator::*) (float, ...) const>::value);

  static_assert (std::is_member_pointer<
                 Instantiator (Instantiator::*) (Instantiator)>::value);
  static_assert (std::is_member_pointer<
                 Instantiator (Instantiator::*) (Instantiator) const>::value);

  static_assert (std::is_member_pointer<
                 int (Instantiator::*) (int, float, int[], int &)>::value);
  static_assert (std::is_member_pointer<int (Instantiator::*) (
                     int, float, int[], int &) const>::value);

  static_assert (!std::is_member_pointer<Instantiator>::value);
  static_assert (!std::is_member_pointer<const Instantiator>::value);
  static_assert (!std::is_member_pointer<volatile Instantiator>::value);
  static_assert (!std::is_member_pointer<const volatile Instantiator>::value);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (std::is_member_pointer<int (Instantiator::*)>::value);
  static_assert (std::is_member_pointer<const int (Instantiator::*)>::value);
  static_assert (
      std::is_member_pointer<volatile int (Instantiator::*)>::value);
  static_assert (
      std::is_member_pointer<const volatile int (Instantiator::*)>::value);

  static_assert (
      std::is_member_pointer<Instantiator (Instantiator::*)>::value);
  static_assert (
      std::is_member_pointer<const Instantiator (Instantiator::*)>::value);
  static_assert (
      std::is_member_pointer<volatile Instantiator (Instantiator::*)>::value);
  static_assert (std::is_member_pointer<
                 const volatile Instantiator (Instantiator::*)>::value);

  static_assert (std::is_member_pointer<int (Instantiator::*) (int)>::value);
  static_assert (
      std::is_member_pointer<int (Instantiator::*) (int) const>::value);

  static_assert (
      std::is_member_pointer<int (Instantiator::*) (float, ...)>::value);
  static_assert (
      std::is_member_pointer<int (Instantiator::*) (float, ...) const>::value);

  static_assert (std::is_member_pointer<
                 Instantiator (Instantiator::*) (Instantiator)>::value);
  static_assert (std::is_member_pointer<
                 Instantiator (Instantiator::*) (Instantiator) const>::value);

  static_assert (std::is_member_pointer<
                 int (Instantiator::*) (int, float, int[], int &)>::value);
  static_assert (std::is_member_pointer<int (Instantiator::*) (
                     int, float, int[], int &) const>::value);

  static_assert (!std::is_member_pointer<Instantiator>::value);
  static_assert (!std::is_member_pointer<const Instantiator>::value);
  static_assert (!std::is_member_pointer<volatile Instantiator>::value);
  static_assert (!std::is_member_pointer<const volatile Instantiator>::value);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
