#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!std::is_unsigned_v<void>);

  static_assert (std::is_unsigned_v<bool> == (bool (-1) > bool (0)));
  static_assert (std::is_unsigned_v<char> == (char (-1) > char (0)));
  static_assert (!std::is_unsigned_v<signed char>);
  static_assert (std::is_unsigned_v<unsigned char>);
  static_assert (std::is_unsigned_v<wchar_t> == (wchar_t (-1) > wchar_t (0)));
  static_assert (!std::is_unsigned_v<short>);
  static_assert (std::is_unsigned_v<unsigned short>);
  static_assert (!std::is_unsigned_v<int>);
  static_assert (std::is_unsigned_v<unsigned int>);
  static_assert (!std::is_unsigned_v<long>);
  static_assert (std::is_unsigned_v<unsigned long>);
  static_assert (!std::is_unsigned_v<long long>);
  static_assert (std::is_unsigned_v<unsigned long long>);

  static_assert (!std::is_unsigned_v<float>);
  static_assert (!std::is_unsigned_v<double>);
  static_assert (!std::is_unsigned_v<long double>);

#ifndef __STRICT_ANSI__
// GNU Extensions.
#ifdef __SIZEOF_INT128__
  static_assert (std::is_unsigned_v<unsigned __int128>);
  static_assert (!std::is_unsigned_v<__int128>);
#endif

#ifdef _GLIBCXX_USE_FLOAT128
  static_assert (!std::is_unsigned_v<__float128>);
#endif
#endif

  static_assert (!std::is_unsigned_v<Instantiator>);
  static_assert (!std::is_unsigned_v<const Instantiator>);
  static_assert (!std::is_unsigned_v<volatile Instantiator>);
  static_assert (!std::is_unsigned_v<const volatile Instantiator>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!std::is_unsigned_v<void>);

  static_assert (std::is_unsigned_v<bool> == (bool (-1) > bool (0)));
  static_assert (std::is_unsigned_v<char> == (char (-1) > char (0)));
  static_assert (!std::is_unsigned_v<signed char>);
  static_assert (std::is_unsigned_v<unsigned char>);
  static_assert (std::is_unsigned_v<wchar_t> == (wchar_t (-1) > wchar_t (0)));
  static_assert (!std::is_unsigned_v<short>);
  static_assert (std::is_unsigned_v<unsigned short>);
  static_assert (!std::is_unsigned_v<int>);
  static_assert (std::is_unsigned_v<unsigned int>);
  static_assert (!std::is_unsigned_v<long>);
  static_assert (std::is_unsigned_v<unsigned long>);
  static_assert (!std::is_unsigned_v<long long>);
  static_assert (std::is_unsigned_v<unsigned long long>);

  static_assert (!std::is_unsigned_v<float>);
  static_assert (!std::is_unsigned_v<double>);
  static_assert (!std::is_unsigned_v<long double>);

#ifndef __STRICT_ANSI__
// GNU Extensions.
#ifdef __SIZEOF_INT128__
  static_assert (std::is_unsigned_v<unsigned __int128>);
  static_assert (!std::is_unsigned_v<__int128>);
#endif

#ifdef _GLIBCXX_USE_FLOAT128
  static_assert (!std::is_unsigned_v<__float128>);
#endif
#endif

  static_assert (!std::is_unsigned_v<Instantiator>);
  static_assert (!std::is_unsigned_v<const Instantiator>);
  static_assert (!std::is_unsigned_v<volatile Instantiator>);
  static_assert (!std::is_unsigned_v<const volatile Instantiator>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
