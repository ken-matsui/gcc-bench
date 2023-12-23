#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!std::is_const<Instantiator>::value);
  static_assert (std::is_const<const Instantiator>::value);
  static_assert (!std::is_const<volatile Instantiator>::value);
  static_assert (std::is_const<const volatile Instantiator>::value);
  static_assert (!std::is_const<Instantiator&>::value);
  static_assert (std::is_const<const Instantiator&>::value);
  static_assert (!std::is_const<volatile Instantiator&>::value);
  static_assert (std::is_const<const volatile Instantiator&>::value);
  static_assert (!std::is_const<Instantiator&&>::value);
  static_assert (std::is_const<const Instantiator&&>::value);
  static_assert (!std::is_const<volatile Instantiator&&>::value);
  static_assert (std::is_const<const volatile Instantiator&&>::value);
  static_assert (!std::is_const<Instantiator[N]>::value);
  static_assert (std::is_const<const Instantiator[N]>::value);
  static_assert (!std::is_const<volatile Instantiator[N]>::value);
  static_assert (std::is_const<const volatile Instantiator[N]>::value);
  static_assert (!std::is_const<Instantiator(int)>::value);
  static_assert (!std::is_const<const Instantiator(int)>::value);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!std::is_const<Instantiator>::value);
  static_assert (std::is_const<const Instantiator>::value);
  static_assert (!std::is_const<volatile Instantiator>::value);
  static_assert (std::is_const<const volatile Instantiator>::value);
  static_assert (!std::is_const<Instantiator&>::value);
  static_assert (std::is_const<const Instantiator&>::value);
  static_assert (!std::is_const<volatile Instantiator&>::value);
  static_assert (std::is_const<const volatile Instantiator&>::value);
  static_assert (!std::is_const<Instantiator&&>::value);
  static_assert (std::is_const<const Instantiator&&>::value);
  static_assert (!std::is_const<volatile Instantiator&&>::value);
  static_assert (std::is_const<const volatile Instantiator&&>::value);
  static_assert (!std::is_const<Instantiator[N]>::value);
  static_assert (std::is_const<const Instantiator[N]>::value);
  static_assert (!std::is_const<volatile Instantiator[N]>::value);
  static_assert (std::is_const<const volatile Instantiator[N]>::value);
  static_assert (!std::is_const<Instantiator(int)>::value);
  static_assert (!std::is_const<const Instantiator(int)>::value);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
