#include "./Common.hpp"

enum class E
{
  e1,
  e2
};
enum U
{
  u1,
  u2
};

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (std::is_scoped_enum<E>::value);
  static_assert (std::is_scoped_enum<const E>::value);
  static_assert (std::is_scoped_enum<volatile E>::value);
  static_assert (std::is_scoped_enum<const volatile E>::value);

  static_assert (!std::is_scoped_enum<U>::value);
  static_assert (!std::is_scoped_enum<const U>::value);
  static_assert (!std::is_scoped_enum<volatile U>::value);
  static_assert (!std::is_scoped_enum<const volatile U>::value);

  static_assert (!std::is_scoped_enum<Instantiator>::value);
  static_assert (!std::is_scoped_enum<const Instantiator>::value);
  static_assert (!std::is_scoped_enum<volatile Instantiator>::value);
  static_assert (!std::is_scoped_enum<const volatile Instantiator>::value);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (std::is_scoped_enum<E>::value);
  static_assert (std::is_scoped_enum<const E>::value);
  static_assert (std::is_scoped_enum<volatile E>::value);
  static_assert (std::is_scoped_enum<const volatile E>::value);

  static_assert (!std::is_scoped_enum<U>::value);
  static_assert (!std::is_scoped_enum<const U>::value);
  static_assert (!std::is_scoped_enum<volatile U>::value);
  static_assert (!std::is_scoped_enum<const volatile U>::value);

  static_assert (!std::is_scoped_enum<Instantiator>::value);
  static_assert (!std::is_scoped_enum<const Instantiator>::value);
  static_assert (!std::is_scoped_enum<volatile Instantiator>::value);
  static_assert (!std::is_scoped_enum<const volatile Instantiator>::value);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
