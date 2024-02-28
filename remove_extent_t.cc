#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (std::is_same_v<std::remove_extent_t<int>, int>);
  static_assert (std::is_same_v<std::remove_extent_t<int[2]>, int>);
  static_assert (std::is_same_v<std::remove_extent_t<int[2][3]>, int[3]>);
  static_assert (std::is_same_v<std::remove_extent_t<int[][3]>, int[3]>);
  static_assert (
      std::is_same_v<std::remove_extent_t<const int[2]>, const int>);
  static_assert (
      std::is_same_v<std::remove_extent_t<Instantiator>, Instantiator>);
  static_assert (
      std::is_same_v<std::remove_extent_t<Instantiator[2]>, Instantiator>);
  static_assert (std::is_same_v<std::remove_extent_t<Instantiator[2][3]>,
                                Instantiator[3]>);
  static_assert (std::is_same_v<std::remove_extent_t<Instantiator[][3]>,
                                Instantiator[3]>);
  static_assert (std::is_same_v<std::remove_extent_t<const Instantiator[2]>,
                                const Instantiator>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (std::is_same_v<std::remove_extent_t<int>, int>);
  static_assert (std::is_same_v<std::remove_extent_t<int[2]>, int>);
  static_assert (std::is_same_v<std::remove_extent_t<int[2][3]>, int[3]>);
  static_assert (std::is_same_v<std::remove_extent_t<int[][3]>, int[3]>);
  static_assert (
      std::is_same_v<std::remove_extent_t<const int[2]>, const int>);
  static_assert (
      std::is_same_v<std::remove_extent_t<Instantiator>, Instantiator>);
  static_assert (
      std::is_same_v<std::remove_extent_t<Instantiator[2]>, Instantiator>);
  static_assert (std::is_same_v<std::remove_extent_t<Instantiator[2][3]>,
                                Instantiator[3]>);
  static_assert (std::is_same_v<std::remove_extent_t<Instantiator[][3]>,
                                Instantiator[3]>);
  static_assert (std::is_same_v<std::remove_extent_t<const Instantiator[2]>,
                                const Instantiator>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
