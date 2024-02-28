#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (std::rank_v<int> == 0);
  static_assert (std::rank_v<int[2]> == 1);
  static_assert (std::rank_v<int[][4]> == 2);
  static_assert (std::rank_v<int[2][2][4][4][6][6]> == 6);
  static_assert (std::rank_v<Instantiator> == 0);
  static_assert (std::rank_v<Instantiator[2]> == 1);
  static_assert (std::rank_v<Instantiator[][4]> == 2);
  static_assert (std::rank_v<Instantiator[2][2][4][4][6][6]> == 6);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (std::rank_v<int> == 0);
  static_assert (std::rank_v<int[2]> == 1);
  static_assert (std::rank_v<int[][4]> == 2);
  static_assert (std::rank_v<int[2][2][4][4][6][6]> == 6);
  static_assert (std::rank_v<Instantiator> == 0);
  static_assert (std::rank_v<Instantiator[2]> == 1);
  static_assert (std::rank_v<Instantiator[][4]> == 2);
  static_assert (std::rank_v<Instantiator[2][2][4][4][6][6]> == 6);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
