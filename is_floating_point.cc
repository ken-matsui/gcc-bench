#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!std::is_floating_point<void>::value);
  static_assert (!std::is_floating_point<char>::value);
  static_assert (!std::is_floating_point<signed char>::value);
  static_assert (!std::is_floating_point<unsigned char>::value);
  static_assert (!std::is_floating_point<wchar_t>::value);
  static_assert (!std::is_floating_point<short>::value);
  static_assert (!std::is_floating_point<unsigned short>::value);
  static_assert (!std::is_floating_point<int>::value);
  static_assert (!std::is_floating_point<unsigned int>::value);
  static_assert (!std::is_floating_point<long>::value);
  static_assert (!std::is_floating_point<unsigned long>::value);
  static_assert (!std::is_floating_point<long long>::value);
  static_assert (!std::is_floating_point<unsigned long long>::value);

  static_assert (std::is_floating_point<float>::value);
  static_assert (std::is_floating_point<double>::value);
  static_assert (std::is_floating_point<long double>::value);

#ifndef __STRICT_ANSI__
// GNU Extensions.
#ifdef _GLIBCXX_USE_FLOAT128
  static_assert (std::is_floating_point<__float128>::value);
#endif

#ifdef __SIZEOF_INT128__
  static_assert (!std::is_floating_point<__int128>::value);
  static_assert (!std::is_floating_point<unsigned __int128>::value);
#endif
#endif

  static_assert (!std::is_floating_point<Instantiator>::value);
  static_assert (!std::is_floating_point<const Instantiator>::value);
  static_assert (!std::is_floating_point<volatile Instantiator>::value);
  static_assert (!std::is_floating_point<const volatile Instantiator>::value);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!std::is_floating_point<void>::value);
  static_assert (!std::is_floating_point<char>::value);
  static_assert (!std::is_floating_point<signed char>::value);
  static_assert (!std::is_floating_point<unsigned char>::value);
  static_assert (!std::is_floating_point<wchar_t>::value);
  static_assert (!std::is_floating_point<short>::value);
  static_assert (!std::is_floating_point<unsigned short>::value);
  static_assert (!std::is_floating_point<int>::value);
  static_assert (!std::is_floating_point<unsigned int>::value);
  static_assert (!std::is_floating_point<long>::value);
  static_assert (!std::is_floating_point<unsigned long>::value);
  static_assert (!std::is_floating_point<long long>::value);
  static_assert (!std::is_floating_point<unsigned long long>::value);

  static_assert (std::is_floating_point<float>::value);
  static_assert (std::is_floating_point<double>::value);
  static_assert (std::is_floating_point<long double>::value);

#ifndef __STRICT_ANSI__
// GNU Extensions.
#ifdef _GLIBCXX_USE_FLOAT128
  static_assert (std::is_floating_point<__float128>::value);
#endif

#ifdef __SIZEOF_INT128__
  static_assert (!std::is_floating_point<__int128>::value);
  static_assert (!std::is_floating_point<unsigned __int128>::value);
#endif
#endif

  static_assert (!std::is_floating_point<Instantiator>::value);
  static_assert (!std::is_floating_point<const Instantiator>::value);
  static_assert (!std::is_floating_point<volatile Instantiator>::value);
  static_assert (!std::is_floating_point<const volatile Instantiator>::value);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
