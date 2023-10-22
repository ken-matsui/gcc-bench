#include <type_traits>

#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!std::is_pointer_v<std::remove_pointer_t<Instantiator> >);
  static_assert (!std::is_pointer_v<std::remove_pointer_t<Instantiator *> >);
  static_assert (
      !std::is_pointer_v<std::remove_pointer_t<const Instantiator> >);
  static_assert (
      !std::is_pointer_v<std::remove_pointer_t<Instantiator *const> >);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!std::is_pointer_v<std::remove_pointer_t<Instantiator> >);
  static_assert (!std::is_pointer_v<std::remove_pointer_t<Instantiator *> >);
  static_assert (
      !std::is_pointer_v<std::remove_pointer_t<const Instantiator> >);
  static_assert (
      !std::is_pointer_v<std::remove_pointer_t<Instantiator *const> >);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
