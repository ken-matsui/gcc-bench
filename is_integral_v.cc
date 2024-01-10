#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!std::is_integral_v<void>);

  static_assert (std::is_integral_v<char>);
  static_assert (std::is_integral_v<signed char>);
  static_assert (std::is_integral_v<unsigned char>);
  static_assert (std::is_integral_v<wchar_t>);
#ifdef _GLIBCXX_USE_CHAR8_T
  static_assert (std::is_integral_v<char8_t>);
#endif
  static_assert (std::is_integral_v<char16_t>);
  static_assert (std::is_integral_v<char32_t>);
  static_assert (std::is_integral_v<short>);
  static_assert (std::is_integral_v<unsigned short>);
  static_assert (std::is_integral_v<int>);
  static_assert (std::is_integral_v<unsigned int>);
  static_assert (std::is_integral_v<long>);
  static_assert (std::is_integral_v<unsigned long>);
  static_assert (std::is_integral_v<long long>);
  static_assert (std::is_integral_v<unsigned long long>);

  static_assert (!std::is_integral_v<float>);
  static_assert (!std::is_integral_v<double>);
  static_assert (!std::is_integral_v<long double>);

#ifndef __STRICT_ANSI__
  // GNU Extensions.
#ifdef __SIZEOF_INT128__
  static_assert (std::is_integral_v<__int128>);
  static_assert (std::is_integral_v<unsigned __int128>);
#endif

#ifdef _GLIBCXX_USE_FLOAT128
  static_assert (!std::is_integral_v<__float128>);
#endif
#endif

  static_assert (!std::is_integral_v<Instantiator>);
  static_assert (!std::is_integral_v<const Instantiator>);
  static_assert (!std::is_integral_v<volatile Instantiator>);
  static_assert (!std::is_integral_v<const volatile Instantiator>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!std::is_integral_v<void>);

  static_assert (std::is_integral_v<char>);
  static_assert (std::is_integral_v<signed char>);
  static_assert (std::is_integral_v<unsigned char>);
  static_assert (std::is_integral_v<wchar_t>);
#ifdef _GLIBCXX_USE_CHAR8_T
  static_assert (std::is_integral_v<char8_t>);
#endif
  static_assert (std::is_integral_v<char16_t>);
  static_assert (std::is_integral_v<char32_t>);
  static_assert (std::is_integral_v<short>);
  static_assert (std::is_integral_v<unsigned short>);
  static_assert (std::is_integral_v<int>);
  static_assert (std::is_integral_v<unsigned int>);
  static_assert (std::is_integral_v<long>);
  static_assert (std::is_integral_v<unsigned long>);
  static_assert (std::is_integral_v<long long>);
  static_assert (std::is_integral_v<unsigned long long>);

  static_assert (!std::is_integral_v<float>);
  static_assert (!std::is_integral_v<double>);
  static_assert (!std::is_integral_v<long double>);

#ifndef __STRICT_ANSI__
  // GNU Extensions.
#ifdef __SIZEOF_INT128__
  static_assert (std::is_integral_v<__int128>);
  static_assert (std::is_integral_v<unsigned __int128>);
#endif

#ifdef _GLIBCXX_USE_FLOAT128
  static_assert (!std::is_integral_v<__float128>);
#endif
#endif

  static_assert (!std::is_integral_v<Instantiator>);
  static_assert (!std::is_integral_v<const Instantiator>);
  static_assert (!std::is_integral_v<volatile Instantiator>);
  static_assert (!std::is_integral_v<const volatile Instantiator>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
