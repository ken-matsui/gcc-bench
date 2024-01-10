#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!std::is_integral<void>::value);

  static_assert (std::is_integral<char>::value);
  static_assert (std::is_integral<signed char>::value);
  static_assert (std::is_integral<unsigned char>::value);
  static_assert (std::is_integral<wchar_t>::value);
#ifdef _GLIBCXX_USE_CHAR8_T
  static_assert (std::is_integral<char8_t>::value);
#endif
  static_assert (std::is_integral<char16_t>::value);
  static_assert (std::is_integral<char32_t>::value);
  static_assert (std::is_integral<short>::value);
  static_assert (std::is_integral<unsigned short>::value);
  static_assert (std::is_integral<int>::value);
  static_assert (std::is_integral<unsigned int>::value);
  static_assert (std::is_integral<long>::value);
  static_assert (std::is_integral<unsigned long>::value);
  static_assert (std::is_integral<long long>::value);
  static_assert (std::is_integral<unsigned long long>::value);

  static_assert (!std::is_integral<float>::value);
  static_assert (!std::is_integral<double>::value);
  static_assert (!std::is_integral<long double>::value);

#ifndef __STRICT_ANSI__
  // GNU Extensions.
#ifdef __SIZEOF_INT128__
  static_assert (std::is_integral<__int128>::value);
  static_assert (std::is_integral<unsigned __int128>::value);
#endif

#ifdef _GLIBCXX_USE_FLOAT128
  static_assert (!std::is_integral<__float128>::value);
#endif
#endif

  static_assert (!std::is_integral<Instantiator>::value);
  static_assert (!std::is_integral<const Instantiator>::value);
  static_assert (!std::is_integral<volatile Instantiator>::value);
  static_assert (!std::is_integral<const volatile Instantiator>::value);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!std::is_integral<void>::value);

  static_assert (std::is_integral<char>::value);
  static_assert (std::is_integral<signed char>::value);
  static_assert (std::is_integral<unsigned char>::value);
  static_assert (std::is_integral<wchar_t>::value);
#ifdef _GLIBCXX_USE_CHAR8_T
  static_assert (std::is_integral<char8_t>::value);
#endif
  static_assert (std::is_integral<char16_t>::value);
  static_assert (std::is_integral<char32_t>::value);
  static_assert (std::is_integral<short>::value);
  static_assert (std::is_integral<unsigned short>::value);
  static_assert (std::is_integral<int>::value);
  static_assert (std::is_integral<unsigned int>::value);
  static_assert (std::is_integral<long>::value);
  static_assert (std::is_integral<unsigned long>::value);
  static_assert (std::is_integral<long long>::value);
  static_assert (std::is_integral<unsigned long long>::value);

  static_assert (!std::is_integral<float>::value);
  static_assert (!std::is_integral<double>::value);
  static_assert (!std::is_integral<long double>::value);

#ifndef __STRICT_ANSI__
  // GNU Extensions.
#ifdef __SIZEOF_INT128__
  static_assert (std::is_integral<__int128>::value);
  static_assert (std::is_integral<unsigned __int128>::value);
#endif

#ifdef _GLIBCXX_USE_FLOAT128
  static_assert (!std::is_integral<__float128>::value);
#endif
#endif

  static_assert (!std::is_integral<Instantiator>::value);
  static_assert (!std::is_integral<const Instantiator>::value);
  static_assert (!std::is_integral<volatile Instantiator>::value);
  static_assert (!std::is_integral<const volatile Instantiator>::value);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
