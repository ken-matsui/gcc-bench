#include <type_traits>

#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!std::is_array<Instantiator>::value);
  static_assert (std::is_array<Instantiator[]>::value);
  static_assert (std::is_array<Instantiator[Count]>::value);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!std::is_array<Instantiator>::value);
  static_assert (std::is_array<Instantiator[]>::value);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
