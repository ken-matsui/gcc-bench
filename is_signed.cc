#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!std::is_signed<void>::value);

  static_assert (std::is_signed<bool>::value == (bool (-1) < bool (0)));
  static_assert (std::is_signed<char>::value == (char (-1) < char (0)));
  static_assert (std::is_signed<signed char>::value);
  static_assert (!std::is_signed<unsigned char>::value);
  static_assert (std::is_signed<wchar_t>::value
                 == (wchar_t (-1) < wchar_t (0)));
  static_assert (std::is_signed<short>::value);
  static_assert (!std::is_signed<unsigned short>::value);
  static_assert (std::is_signed<int>::value);
  static_assert (!std::is_signed<unsigned int>::value);
  static_assert (std::is_signed<long>::value);
  static_assert (!std::is_signed<unsigned long>::value);
  static_assert (std::is_signed<long long>::value);
  static_assert (!std::is_signed<unsigned long long>::value);

  static_assert (std::is_signed<float>::value);
  static_assert (std::is_signed<double>::value);
  static_assert (std::is_signed<long double>::value);

#ifndef __STRICT_ANSI__
// GNU Extensions.
#ifdef __SIZEOF_INT128__
  static_assert (std::is_signed<__int128>::value);
  static_assert (!std::is_signed<unsigned __int128>::value);
#endif

#ifdef _GLIBCXX_USE_FLOAT128
  static_assert (std::is_signed<__float128>::value);
#endif
#endif

  static_assert (!std::is_signed<Instantiator>::value);
  static_assert (!std::is_signed<const Instantiator>::value);
  static_assert (!std::is_signed<volatile Instantiator>::value);
  static_assert (!std::is_signed<const volatile Instantiator>::value);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!std::is_signed<void>::value);

  static_assert (std::is_signed<bool>::value == (bool (-1) < bool (0)));
  static_assert (std::is_signed<char>::value == (char (-1) < char (0)));
  static_assert (std::is_signed<signed char>::value);
  static_assert (!std::is_signed<unsigned char>::value);
  static_assert (std::is_signed<wchar_t>::value
                 == (wchar_t (-1) < wchar_t (0)));
  static_assert (std::is_signed<short>::value);
  static_assert (!std::is_signed<unsigned short>::value);
  static_assert (std::is_signed<int>::value);
  static_assert (!std::is_signed<unsigned int>::value);
  static_assert (std::is_signed<long>::value);
  static_assert (!std::is_signed<unsigned long>::value);
  static_assert (std::is_signed<long long>::value);
  static_assert (!std::is_signed<unsigned long long>::value);

  static_assert (std::is_signed<float>::value);
  static_assert (std::is_signed<double>::value);
  static_assert (std::is_signed<long double>::value);

#ifndef __STRICT_ANSI__
// GNU Extensions.
#ifdef __SIZEOF_INT128__
  static_assert (std::is_signed<__int128>::value);
  static_assert (!std::is_signed<unsigned __int128>::value);
#endif

#ifdef _GLIBCXX_USE_FLOAT128
  static_assert (std::is_signed<__float128>::value);
#endif
#endif

  static_assert (!std::is_signed<Instantiator>::value);
  static_assert (!std::is_signed<const Instantiator>::value);
  static_assert (!std::is_signed<volatile Instantiator>::value);
  static_assert (!std::is_signed<const volatile Instantiator>::value);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
