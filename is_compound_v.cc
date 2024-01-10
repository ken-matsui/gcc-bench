#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!std::is_compound_v<void>);
  static_assert (!std::is_compound_v<char>);
  static_assert (!std::is_compound_v<signed char>);
  static_assert (!std::is_compound_v<unsigned char>);
  static_assert (!std::is_compound_v<wchar_t>);
  static_assert (!std::is_compound_v<short>);
  static_assert (!std::is_compound_v<unsigned short>);
  static_assert (!std::is_compound_v<int>);
  static_assert (!std::is_compound_v<unsigned int>);
  static_assert (!std::is_compound_v<long>);
  static_assert (!std::is_compound_v<unsigned long>);
  static_assert (!std::is_compound_v<long long>);
  static_assert (!std::is_compound_v<unsigned long long>);
  static_assert (!std::is_compound_v<float>);
  static_assert (!std::is_compound_v<double>);
  static_assert (!std::is_compound_v<long double>);
  static_assert (!std::is_compound_v<decltype (nullptr)>);

  static_assert (std::is_compound_v<Instantiator>);
  static_assert (std::is_compound_v<const Instantiator>);
  static_assert (std::is_compound_v<volatile Instantiator>);
  static_assert (std::is_compound_v<const volatile Instantiator>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!std::is_compound_v<void>);
  static_assert (!std::is_compound_v<char>);
  static_assert (!std::is_compound_v<signed char>);
  static_assert (!std::is_compound_v<unsigned char>);
  static_assert (!std::is_compound_v<wchar_t>);
  static_assert (!std::is_compound_v<short>);
  static_assert (!std::is_compound_v<unsigned short>);
  static_assert (!std::is_compound_v<int>);
  static_assert (!std::is_compound_v<unsigned int>);
  static_assert (!std::is_compound_v<long>);
  static_assert (!std::is_compound_v<unsigned long>);
  static_assert (!std::is_compound_v<long long>);
  static_assert (!std::is_compound_v<unsigned long long>);
  static_assert (!std::is_compound_v<float>);
  static_assert (!std::is_compound_v<double>);
  static_assert (!std::is_compound_v<long double>);
  static_assert (!std::is_compound_v<decltype (nullptr)>);

  static_assert (std::is_compound_v<Instantiator>);
  static_assert (std::is_compound_v<const Instantiator>);
  static_assert (std::is_compound_v<volatile Instantiator>);
  static_assert (std::is_compound_v<const volatile Instantiator>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
