#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!std::is_unsigned<void>::value);

  static_assert (std::is_unsigned<bool>::value == (bool (-1) > bool (0)));
  static_assert (std::is_unsigned<char>::value == (char (-1) > char (0)));
  static_assert (!std::is_unsigned<signed char>::value);
  static_assert (std::is_unsigned<unsigned char>::value);
  static_assert (std::is_unsigned<wchar_t>::value
                 == (wchar_t (-1) > wchar_t (0)));
  static_assert (!std::is_unsigned<short>::value);
  static_assert (std::is_unsigned<unsigned short>::value);
  static_assert (!std::is_unsigned<int>::value);
  static_assert (std::is_unsigned<unsigned int>::value);
  static_assert (!std::is_unsigned<long>::value);
  static_assert (std::is_unsigned<unsigned long>::value);
  static_assert (!std::is_unsigned<long long>::value);
  static_assert (std::is_unsigned<unsigned long long>::value);

  static_assert (!std::is_unsigned<float>::value);
  static_assert (!std::is_unsigned<double>::value);
  static_assert (!std::is_unsigned<long double>::value);

#ifndef __STRICT_ANSI__
// GNU Extensions.
#ifdef __SIZEOF_INT128__
  static_assert (std::is_unsigned<unsigned __int128>::value);
  static_assert (!std::is_unsigned<__int128>::value);
#endif

#ifdef _GLIBCXX_USE_FLOAT128
  static_assert (!std::is_unsigned<__float128>::value);
#endif
#endif

  static_assert (!std::is_unsigned<Instantiator>::value);
  static_assert (!std::is_unsigned<const Instantiator>::value);
  static_assert (!std::is_unsigned<volatile Instantiator>::value);
  static_assert (!std::is_unsigned<const volatile Instantiator>::value);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!std::is_unsigned<void>::value);

  static_assert (std::is_unsigned<bool>::value == (bool (-1) > bool (0)));
  static_assert (std::is_unsigned<char>::value == (char (-1) > char (0)));
  static_assert (!std::is_unsigned<signed char>::value);
  static_assert (std::is_unsigned<unsigned char>::value);
  static_assert (std::is_unsigned<wchar_t>::value
                 == (wchar_t (-1) > wchar_t (0)));
  static_assert (!std::is_unsigned<short>::value);
  static_assert (std::is_unsigned<unsigned short>::value);
  static_assert (!std::is_unsigned<int>::value);
  static_assert (std::is_unsigned<unsigned int>::value);
  static_assert (!std::is_unsigned<long>::value);
  static_assert (std::is_unsigned<unsigned long>::value);
  static_assert (!std::is_unsigned<long long>::value);
  static_assert (std::is_unsigned<unsigned long long>::value);

  static_assert (!std::is_unsigned<float>::value);
  static_assert (!std::is_unsigned<double>::value);
  static_assert (!std::is_unsigned<long double>::value);

#ifndef __STRICT_ANSI__
// GNU Extensions.
#ifdef __SIZEOF_INT128__
  static_assert (std::is_unsigned<unsigned __int128>::value);
  static_assert (!std::is_unsigned<__int128>::value);
#endif

#ifdef _GLIBCXX_USE_FLOAT128
  static_assert (!std::is_unsigned<__float128>::value);
#endif
#endif

  static_assert (!std::is_unsigned<Instantiator>::value);
  static_assert (!std::is_unsigned<const Instantiator>::value);
  static_assert (!std::is_unsigned<volatile Instantiator>::value);
  static_assert (!std::is_unsigned<const volatile Instantiator>::value);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
