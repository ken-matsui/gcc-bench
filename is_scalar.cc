#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  enum EnumType
  {
    e1
  };
  static_assert (std::is_scalar<int>::value);
  static_assert (std::is_scalar<float>::value);
  static_assert (std::is_scalar<EnumType>::value);
  static_assert (std::is_scalar<int *>::value);
  static_assert (std::is_scalar<int (*) (int)>::value);
  static_assert (std::is_scalar<int (Instantiator::*)>::value);
  static_assert (std::is_scalar<int (Instantiator::*) (int)>::value);
  static_assert (std::is_scalar<decltype (nullptr)>::value);

  static_assert (!std::is_scalar<Instantiator>::value);
  static_assert (!std::is_scalar<const Instantiator>::value);
  static_assert (!std::is_scalar<volatile Instantiator>::value);
  static_assert (!std::is_scalar<const volatile Instantiator>::value);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  enum EnumType
  {
    e1
  };
  static_assert (std::is_scalar<int>::value);
  static_assert (std::is_scalar<float>::value);
  static_assert (std::is_scalar<EnumType>::value);
  static_assert (std::is_scalar<int *>::value);
  static_assert (std::is_scalar<int (*) (int)>::value);
  static_assert (std::is_scalar<int (Instantiator::*)>::value);
  static_assert (std::is_scalar<int (Instantiator::*) (int)>::value);
  static_assert (std::is_scalar<decltype (nullptr)>::value);

  static_assert (!std::is_scalar<Instantiator>::value);
  static_assert (!std::is_scalar<const Instantiator>::value);
  static_assert (!std::is_scalar<volatile Instantiator>::value);
  static_assert (!std::is_scalar<const volatile Instantiator>::value);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
