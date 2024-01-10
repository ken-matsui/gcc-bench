#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (std::is_fundamental<void>::value);
  static_assert (std::is_fundamental<char>::value);
  static_assert (std::is_fundamental<signed char>::value);
  static_assert (std::is_fundamental<unsigned char>::value);
  static_assert (std::is_fundamental<wchar_t>::value);
  static_assert (std::is_fundamental<short>::value);
  static_assert (std::is_fundamental<unsigned short>::value);
  static_assert (std::is_fundamental<int>::value);
  static_assert (std::is_fundamental<unsigned int>::value);
  static_assert (std::is_fundamental<long>::value);
  static_assert (std::is_fundamental<unsigned long>::value);
  static_assert (std::is_fundamental<long long>::value);
  static_assert (std::is_fundamental<unsigned long long>::value);
  static_assert (std::is_fundamental<float>::value);
  static_assert (std::is_fundamental<double>::value);
  static_assert (std::is_fundamental<long double>::value);
  static_assert (std::is_fundamental<decltype (nullptr)>::value);

  static_assert (!std::is_fundamental<Instantiator>::value);
  static_assert (!std::is_fundamental<const Instantiator>::value);
  static_assert (!std::is_fundamental<volatile Instantiator>::value);
  static_assert (!std::is_fundamental<const volatile Instantiator>::value);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (std::is_fundamental<void>::value);
  static_assert (std::is_fundamental<char>::value);
  static_assert (std::is_fundamental<signed char>::value);
  static_assert (std::is_fundamental<unsigned char>::value);
  static_assert (std::is_fundamental<wchar_t>::value);
  static_assert (std::is_fundamental<short>::value);
  static_assert (std::is_fundamental<unsigned short>::value);
  static_assert (std::is_fundamental<int>::value);
  static_assert (std::is_fundamental<unsigned int>::value);
  static_assert (std::is_fundamental<long>::value);
  static_assert (std::is_fundamental<unsigned long>::value);
  static_assert (std::is_fundamental<long long>::value);
  static_assert (std::is_fundamental<unsigned long long>::value);
  static_assert (std::is_fundamental<float>::value);
  static_assert (std::is_fundamental<double>::value);
  static_assert (std::is_fundamental<long double>::value);
  static_assert (std::is_fundamental<decltype (nullptr)>::value);

  static_assert (!std::is_fundamental<Instantiator>::value);
  static_assert (!std::is_fundamental<const Instantiator>::value);
  static_assert (!std::is_fundamental<volatile Instantiator>::value);
  static_assert (!std::is_fundamental<const volatile Instantiator>::value);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
