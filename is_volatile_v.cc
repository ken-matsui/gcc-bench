#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!std::is_volatile_v<Instantiator>);
  static_assert (!std::is_volatile_v<const Instantiator>);
  static_assert (std::is_volatile_v<volatile Instantiator>);
  static_assert (std::is_volatile_v<const volatile Instantiator>);
  static_assert (!std::is_volatile_v<Instantiator&>);
  static_assert (!std::is_volatile_v<const Instantiator&>);
  static_assert (std::is_volatile_v<volatile Instantiator&>);
  static_assert (std::is_volatile_v<const volatile Instantiator&>);
  static_assert (!std::is_volatile_v<Instantiator&&>);
  static_assert (!std::is_volatile_v<const Instantiator&&>);
  static_assert (std::is_volatile_v<volatile Instantiator&&>);
  static_assert (std::is_volatile_v<const volatile Instantiator&&>);
  static_assert (!std::is_volatile_v<Instantiator[N]>);
  static_assert (!std::is_volatile_v<const Instantiator[N]>);
  static_assert (std::is_volatile_v<volatile Instantiator[N]>);
  static_assert (std::is_volatile_v<const volatile Instantiator[N]>);
  static_assert (!std::is_volatile_v<Instantiator(int)>);
  static_assert (!std::is_volatile_v<const Instantiator(int)>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!std::is_volatile_v<Instantiator>);
  static_assert (!std::is_volatile_v<const Instantiator>);
  static_assert (std::is_volatile_v<volatile Instantiator>);
  static_assert (std::is_volatile_v<const volatile Instantiator>);
  static_assert (!std::is_volatile_v<Instantiator&>);
  static_assert (!std::is_volatile_v<const Instantiator&>);
  static_assert (std::is_volatile_v<volatile Instantiator&>);
  static_assert (std::is_volatile_v<const volatile Instantiator&>);
  static_assert (!std::is_volatile_v<Instantiator&&>);
  static_assert (!std::is_volatile_v<const Instantiator&&>);
  static_assert (std::is_volatile_v<volatile Instantiator&&>);
  static_assert (std::is_volatile_v<const volatile Instantiator&&>);
  static_assert (!std::is_volatile_v<Instantiator[N]>);
  static_assert (!std::is_volatile_v<const Instantiator[N]>);
  static_assert (std::is_volatile_v<volatile Instantiator[N]>);
  static_assert (std::is_volatile_v<const volatile Instantiator[N]>);
  static_assert (!std::is_volatile_v<Instantiator(int)>);
  static_assert (!std::is_volatile_v<const Instantiator(int)>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
