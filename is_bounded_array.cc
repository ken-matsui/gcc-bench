#include <type_traits>

#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (std::is_bounded_array<Instantiator[2]>::value);
  static_assert (std::is_bounded_array<const Instantiator[2]>::value);
  static_assert (std::is_bounded_array<volatile Instantiator[2]>::value);
  static_assert (std::is_bounded_array<const volatile Instantiator[2]>::value);

  static_assert (!std::is_bounded_array<Instantiator[]>::value);
  static_assert (!std::is_bounded_array<const Instantiator[]>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator[]>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator[]>::value);

  static_assert (std::is_bounded_array<Instantiator[2][3]>::value);
  static_assert (std::is_bounded_array<const Instantiator[2][3]>::value);
  static_assert (std::is_bounded_array<volatile Instantiator[2][3]>::value);
  static_assert (std::is_bounded_array<const volatile Instantiator[2][3]>::value);

  static_assert (!std::is_bounded_array<Instantiator[][3]>::value);
  static_assert (!std::is_bounded_array<const Instantiator[][3]>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator[][3]>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator[][3]>::value);

  static_assert (std::is_bounded_array<Instantiator *[2]>::value);
  static_assert (std::is_bounded_array<const Instantiator *[2]>::value);
  static_assert (std::is_bounded_array<volatile Instantiator *[2]>::value);
  static_assert (std::is_bounded_array<const volatile Instantiator *[2]>::value);

  static_assert (!std::is_bounded_array<Instantiator *[]>::value);
  static_assert (!std::is_bounded_array<const Instantiator *[]>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator *[]>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator *[]>::value);

  static_assert (std::is_bounded_array<Instantiator *[2][3]>::value);
  static_assert (std::is_bounded_array<const Instantiator *[2][3]>::value);
  static_assert (std::is_bounded_array<volatile Instantiator *[2][3]>::value);
  static_assert (std::is_bounded_array<const volatile Instantiator *[2][3]>::value);

  static_assert (!std::is_bounded_array<Instantiator *[][3]>::value);
  static_assert (!std::is_bounded_array<const Instantiator *[][3]>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator *[][3]>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator *[][3]>::value);

  static_assert (!std::is_bounded_array<Instantiator (*)[2]>::value);
  static_assert (!std::is_bounded_array<const Instantiator (*)[2]>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator (*)[2]>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator (*)[2]>::value);

  static_assert (!std::is_bounded_array<Instantiator (*)[]>::value);
  static_assert (!std::is_bounded_array<const Instantiator (*)[]>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator (*)[]>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator (*)[]>::value);

  static_assert (!std::is_bounded_array<Instantiator (&)[2]>::value);
  static_assert (!std::is_bounded_array<const Instantiator (&)[2]>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator (&)[2]>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator (&)[2]>::value);

  static_assert (!std::is_bounded_array<Instantiator (&)[]>::value);
  static_assert (!std::is_bounded_array<const Instantiator (&)[]>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator (&)[]>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator (&)[]>::value);

  static_assert (!std::is_bounded_array<Instantiator>::value);
  static_assert (!std::is_bounded_array<const Instantiator>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator>::value);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (std::is_bounded_array<Instantiator[2]>::value);
  static_assert (std::is_bounded_array<const Instantiator[2]>::value);
  static_assert (std::is_bounded_array<volatile Instantiator[2]>::value);
  static_assert (std::is_bounded_array<const volatile Instantiator[2]>::value);

  static_assert (!std::is_bounded_array<Instantiator[]>::value);
  static_assert (!std::is_bounded_array<const Instantiator[]>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator[]>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator[]>::value);

  static_assert (std::is_bounded_array<Instantiator[2][3]>::value);
  static_assert (std::is_bounded_array<const Instantiator[2][3]>::value);
  static_assert (std::is_bounded_array<volatile Instantiator[2][3]>::value);
  static_assert (std::is_bounded_array<const volatile Instantiator[2][3]>::value);

  static_assert (!std::is_bounded_array<Instantiator[][3]>::value);
  static_assert (!std::is_bounded_array<const Instantiator[][3]>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator[][3]>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator[][3]>::value);

  static_assert (std::is_bounded_array<Instantiator *[2]>::value);
  static_assert (std::is_bounded_array<const Instantiator *[2]>::value);
  static_assert (std::is_bounded_array<volatile Instantiator *[2]>::value);
  static_assert (std::is_bounded_array<const volatile Instantiator *[2]>::value);

  static_assert (!std::is_bounded_array<Instantiator *[]>::value);
  static_assert (!std::is_bounded_array<const Instantiator *[]>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator *[]>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator *[]>::value);

  static_assert (std::is_bounded_array<Instantiator *[2][3]>::value);
  static_assert (std::is_bounded_array<const Instantiator *[2][3]>::value);
  static_assert (std::is_bounded_array<volatile Instantiator *[2][3]>::value);
  static_assert (std::is_bounded_array<const volatile Instantiator *[2][3]>::value);

  static_assert (!std::is_bounded_array<Instantiator *[][3]>::value);
  static_assert (!std::is_bounded_array<const Instantiator *[][3]>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator *[][3]>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator *[][3]>::value);

  static_assert (!std::is_bounded_array<Instantiator (*)[2]>::value);
  static_assert (!std::is_bounded_array<const Instantiator (*)[2]>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator (*)[2]>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator (*)[2]>::value);

  static_assert (!std::is_bounded_array<Instantiator (*)[]>::value);
  static_assert (!std::is_bounded_array<const Instantiator (*)[]>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator (*)[]>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator (*)[]>::value);

  static_assert (!std::is_bounded_array<Instantiator (&)[2]>::value);
  static_assert (!std::is_bounded_array<const Instantiator (&)[2]>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator (&)[2]>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator (&)[2]>::value);

  static_assert (!std::is_bounded_array<Instantiator (&)[]>::value);
  static_assert (!std::is_bounded_array<const Instantiator (&)[]>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator (&)[]>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator (&)[]>::value);

  static_assert (!std::is_bounded_array<Instantiator>::value);
  static_assert (!std::is_bounded_array<const Instantiator>::value);
  static_assert (!std::is_bounded_array<volatile Instantiator>::value);
  static_assert (!std::is_bounded_array<const volatile Instantiator>::value);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
