#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!std::is_arithmetic<void>::value);

  static_assert (std::is_arithmetic<char>::value);
  static_assert (std::is_arithmetic<signed char>::value);
  static_assert (std::is_arithmetic<unsigned char>::value);
  static_assert (std::is_arithmetic<wchar_t>::value);
  static_assert (std::is_arithmetic<short>::value);
  static_assert (std::is_arithmetic<unsigned short>::value);
  static_assert (std::is_arithmetic<int>::value);
  static_assert (std::is_arithmetic<unsigned int>::value);
  static_assert (std::is_arithmetic<long>::value);
  static_assert (std::is_arithmetic<unsigned long>::value);
  static_assert (std::is_arithmetic<long long>::value);
  static_assert (std::is_arithmetic<unsigned long long>::value);
  static_assert (std::is_arithmetic<float>::value);
  static_assert (std::is_arithmetic<double>::value);
  static_assert (std::is_arithmetic<long double>::value);

  static_assert (!std::is_arithmetic<Instantiator>::value);
  static_assert (!std::is_arithmetic<const Instantiator>::value);
  static_assert (!std::is_arithmetic<volatile Instantiator>::value);
  static_assert (!std::is_arithmetic<const volatile Instantiator>::value);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!std::is_arithmetic<void>::value);

  static_assert (std::is_arithmetic<char>::value);
  static_assert (std::is_arithmetic<signed char>::value);
  static_assert (std::is_arithmetic<unsigned char>::value);
  static_assert (std::is_arithmetic<wchar_t>::value);
  static_assert (std::is_arithmetic<short>::value);
  static_assert (std::is_arithmetic<unsigned short>::value);
  static_assert (std::is_arithmetic<int>::value);
  static_assert (std::is_arithmetic<unsigned int>::value);
  static_assert (std::is_arithmetic<long>::value);
  static_assert (std::is_arithmetic<unsigned long>::value);
  static_assert (std::is_arithmetic<long long>::value);
  static_assert (std::is_arithmetic<unsigned long long>::value);
  static_assert (std::is_arithmetic<float>::value);
  static_assert (std::is_arithmetic<double>::value);
  static_assert (std::is_arithmetic<long double>::value);

  static_assert (!std::is_arithmetic<Instantiator>::value);
  static_assert (!std::is_arithmetic<const Instantiator>::value);
  static_assert (!std::is_arithmetic<volatile Instantiator>::value);
  static_assert (!std::is_arithmetic<const volatile Instantiator>::value);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
