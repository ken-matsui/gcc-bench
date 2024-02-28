#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (std::rank<int>::value == 0);
  static_assert (std::rank<int[2]>::value == 1);
  static_assert (std::rank<int[][4]>::value == 2);
  static_assert (std::rank<int[2][2][4][4][6][6]>::value == 6);
  static_assert (std::rank<Instantiator>::value == 0);
  static_assert (std::rank<Instantiator[2]>::value == 1);
  static_assert (std::rank<Instantiator[][4]>::value == 2);
  static_assert (std::rank<Instantiator[2][2][4][4][6][6]>::value == 6);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (std::rank<int>::value == 0);
  static_assert (std::rank<int[2]>::value == 1);
  static_assert (std::rank<int[][4]>::value == 2);
  static_assert (std::rank<int[2][2][4][4][6][6]>::value == 6);
  static_assert (std::rank<Instantiator>::value == 0);
  static_assert (std::rank<Instantiator[2]>::value == 1);
  static_assert (std::rank<Instantiator[][4]>::value == 2);
  static_assert (std::rank<Instantiator[2][2][4][4][6][6]>::value == 6);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
