#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (std::is_same_v<std::add_lvalue_reference_t<int>, int &>);
  static_assert (std::is_same_v<std::add_lvalue_reference_t<int &>, int &>);
  static_assert (
      std::is_same_v<std::add_lvalue_reference_t<const int>, const int &>);
  static_assert (std::is_same_v<std::add_lvalue_reference_t<int *>, int *&>);
  static_assert (std::is_same_v<std::add_lvalue_reference_t<Instantiator &>,
                                Instantiator &>);
  static_assert (std::is_same_v<std::add_lvalue_reference_t<Instantiator>,
                                Instantiator &>);
  static_assert (
      std::is_same_v<std::add_lvalue_reference_t<int (int)>, int (&) (int)>);
  static_assert (std::is_same_v<std::add_lvalue_reference_t<int &&>, int &>);
  static_assert (std::is_same_v<std::add_lvalue_reference_t<Instantiator &&>,
                                Instantiator &>);
  static_assert (std::is_same_v<std::add_lvalue_reference_t<void>, void>);
  static_assert (
      std::is_same_v<std::add_lvalue_reference_t<const void>, const void>);
  static_assert (std::is_same_v<std::add_lvalue_reference_t<bool (int) const>,
                                bool (int) const>);
  static_assert (
      std::is_same_v<std::add_lvalue_reference_t<bool (int) &>, bool (int) &>);
  static_assert (
      std::is_same_v<std::add_lvalue_reference_t<bool (int) const &&>,
                     bool (int) const &&>);
  static_assert (
      std::is_same_v<std::add_lvalue_reference_t<bool (int)>, bool (&) (int)>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (std::is_same_v<std::add_lvalue_reference_t<int>, int &>);
  static_assert (std::is_same_v<std::add_lvalue_reference_t<int &>, int &>);
  static_assert (
      std::is_same_v<std::add_lvalue_reference_t<const int>, const int &>);
  static_assert (std::is_same_v<std::add_lvalue_reference_t<int *>, int *&>);
  static_assert (std::is_same_v<std::add_lvalue_reference_t<Instantiator &>,
                                Instantiator &>);
  static_assert (std::is_same_v<std::add_lvalue_reference_t<Instantiator>,
                                Instantiator &>);
  static_assert (
      std::is_same_v<std::add_lvalue_reference_t<int (int)>, int (&) (int)>);
  static_assert (std::is_same_v<std::add_lvalue_reference_t<int &&>, int &>);
  static_assert (std::is_same_v<std::add_lvalue_reference_t<Instantiator &&>,
                                Instantiator &>);
  static_assert (std::is_same_v<std::add_lvalue_reference_t<void>, void>);
  static_assert (
      std::is_same_v<std::add_lvalue_reference_t<const void>, const void>);
  static_assert (std::is_same_v<std::add_lvalue_reference_t<bool (int) const>,
                                bool (int) const>);
  static_assert (
      std::is_same_v<std::add_lvalue_reference_t<bool (int) &>, bool (int) &>);
  static_assert (
      std::is_same_v<std::add_lvalue_reference_t<bool (int) const &&>,
                     bool (int) const &&>);
  static_assert (
      std::is_same_v<std::add_lvalue_reference_t<bool (int)>, bool (&) (int)>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
