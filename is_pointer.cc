#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!std::is_pointer<Instantiator>::value);
  static_assert (std::is_pointer<Instantiator *>::value);
  static_assert (std::is_pointer<Instantiator **>::value);

  static_assert (std::is_pointer<const Instantiator *>::value);
  static_assert (std::is_pointer<const Instantiator **>::value);
  static_assert (std::is_pointer<Instantiator *const>::value);
  static_assert (std::is_pointer<Instantiator **const>::value);
  static_assert (std::is_pointer<Instantiator *const *const>::value);

  static_assert (std::is_pointer<volatile Instantiator *>::value);
  static_assert (std::is_pointer<volatile Instantiator **>::value);
  static_assert (std::is_pointer<Instantiator *volatile>::value);
  static_assert (std::is_pointer<Instantiator **volatile>::value);
  static_assert (std::is_pointer<Instantiator *volatile *volatile>::value);

  static_assert (std::is_pointer<const volatile Instantiator *>::value);
  static_assert (std::is_pointer<const volatile Instantiator **>::value);
  static_assert (std::is_pointer<const Instantiator *volatile>::value);
  static_assert (std::is_pointer<volatile Instantiator *const>::value);
  static_assert (std::is_pointer<Instantiator *const volatile>::value);
  static_assert (std::is_pointer<const Instantiator **volatile>::value);
  static_assert (std::is_pointer<volatile Instantiator **const>::value);
  static_assert (std::is_pointer<Instantiator **const volatile>::value);
  static_assert (std::is_pointer<Instantiator *const *const volatile>::value);
  static_assert (
      std::is_pointer<Instantiator *volatile *const volatile>::value);
  static_assert (
      std::is_pointer<Instantiator *const volatile *const volatile>::value);

  static_assert (!std::is_pointer<Instantiator &>::value);
  static_assert (!std::is_pointer<const Instantiator &>::value);
  static_assert (!std::is_pointer<volatile Instantiator &>::value);
  static_assert (!std::is_pointer<const volatile Instantiator &>::value);

  static_assert (!std::is_pointer<Instantiator &&>::value);
  static_assert (!std::is_pointer<const Instantiator &&>::value);
  static_assert (!std::is_pointer<volatile Instantiator &&>::value);
  static_assert (!std::is_pointer<const volatile Instantiator &&>::value);

  static_assert (!std::is_pointer<Instantiator[3]>::value);
  static_assert (!std::is_pointer<const Instantiator[3]>::value);
  static_assert (!std::is_pointer<volatile Instantiator[3]>::value);
  static_assert (!std::is_pointer<const volatile Instantiator[3]>::value);

  static_assert (!std::is_pointer<Instantiator (int)>::value);
  static_assert (std::is_pointer<Instantiator (*const) (int)>::value);
  static_assert (std::is_pointer<Instantiator (*volatile) (int)>::value);
  static_assert (std::is_pointer<Instantiator (*const volatile) (int)>::value);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!std::is_pointer<Instantiator>::value);
  static_assert (std::is_pointer<Instantiator *>::value);
  static_assert (std::is_pointer<Instantiator **>::value);

  static_assert (std::is_pointer<const Instantiator *>::value);
  static_assert (std::is_pointer<const Instantiator **>::value);
  static_assert (std::is_pointer<Instantiator *const>::value);
  static_assert (std::is_pointer<Instantiator **const>::value);
  static_assert (std::is_pointer<Instantiator *const *const>::value);

  static_assert (std::is_pointer<volatile Instantiator *>::value);
  static_assert (std::is_pointer<volatile Instantiator **>::value);
  static_assert (std::is_pointer<Instantiator *volatile>::value);
  static_assert (std::is_pointer<Instantiator **volatile>::value);
  static_assert (std::is_pointer<Instantiator *volatile *volatile>::value);

  static_assert (std::is_pointer<const volatile Instantiator *>::value);
  static_assert (std::is_pointer<const volatile Instantiator **>::value);
  static_assert (std::is_pointer<const Instantiator *volatile>::value);
  static_assert (std::is_pointer<volatile Instantiator *const>::value);
  static_assert (std::is_pointer<Instantiator *const volatile>::value);
  static_assert (std::is_pointer<const Instantiator **volatile>::value);
  static_assert (std::is_pointer<volatile Instantiator **const>::value);
  static_assert (std::is_pointer<Instantiator **const volatile>::value);
  static_assert (std::is_pointer<Instantiator *const *const volatile>::value);
  static_assert (
      std::is_pointer<Instantiator *volatile *const volatile>::value);
  static_assert (
      std::is_pointer<Instantiator *const volatile *const volatile>::value);

  static_assert (!std::is_pointer<Instantiator &>::value);
  static_assert (!std::is_pointer<const Instantiator &>::value);
  static_assert (!std::is_pointer<volatile Instantiator &>::value);
  static_assert (!std::is_pointer<const volatile Instantiator &>::value);

  static_assert (!std::is_pointer<Instantiator &&>::value);
  static_assert (!std::is_pointer<const Instantiator &&>::value);
  static_assert (!std::is_pointer<volatile Instantiator &&>::value);
  static_assert (!std::is_pointer<const volatile Instantiator &&>::value);

  static_assert (!std::is_pointer<Instantiator[3]>::value);
  static_assert (!std::is_pointer<const Instantiator[3]>::value);
  static_assert (!std::is_pointer<volatile Instantiator[3]>::value);
  static_assert (!std::is_pointer<const volatile Instantiator[3]>::value);

  static_assert (!std::is_pointer<Instantiator (int)>::value);
  static_assert (std::is_pointer<Instantiator (*const) (int)>::value);
  static_assert (std::is_pointer<Instantiator (*volatile) (int)>::value);
  static_assert (std::is_pointer<Instantiator (*const volatile) (int)>::value);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
