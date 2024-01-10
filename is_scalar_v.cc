#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  enum EnumType
  {
    e1
  };
  static_assert (std::is_scalar_v<int>);
  static_assert (std::is_scalar_v<float>);
  static_assert (std::is_scalar_v<EnumType>);
  static_assert (std::is_scalar_v<int *>);
  static_assert (std::is_scalar_v<int (*) (int)>);
  static_assert (std::is_scalar_v<int (Instantiator::*)>);
  static_assert (std::is_scalar_v<int (Instantiator::*) (int)>);
  static_assert (std::is_scalar_v<decltype (nullptr)>);

  static_assert (!std::is_scalar_v<Instantiator>);
  static_assert (!std::is_scalar_v<const Instantiator>);
  static_assert (!std::is_scalar_v<volatile Instantiator>);
  static_assert (!std::is_scalar_v<const volatile Instantiator>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  enum EnumType
  {
    e1
  };
  static_assert (std::is_scalar_v<int>);
  static_assert (std::is_scalar_v<float>);
  static_assert (std::is_scalar_v<EnumType>);
  static_assert (std::is_scalar_v<int *>);
  static_assert (std::is_scalar_v<int (*) (int)>);
  static_assert (std::is_scalar_v<int (Instantiator::*)>);
  static_assert (std::is_scalar_v<int (Instantiator::*) (int)>);
  static_assert (std::is_scalar_v<decltype (nullptr)>);

  static_assert (!std::is_scalar_v<Instantiator>);
  static_assert (!std::is_scalar_v<const Instantiator>);
  static_assert (!std::is_scalar_v<volatile Instantiator>);
  static_assert (!std::is_scalar_v<const volatile Instantiator>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
