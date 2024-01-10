#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!std::is_floating_point_v<void>);
  static_assert (!std::is_floating_point_v<char>);
  static_assert (!std::is_floating_point_v<signed char>);
  static_assert (!std::is_floating_point_v<unsigned char>);
  static_assert (!std::is_floating_point_v<wchar_t>);
  static_assert (!std::is_floating_point_v<short>);
  static_assert (!std::is_floating_point_v<unsigned short>);
  static_assert (!std::is_floating_point_v<int>);
  static_assert (!std::is_floating_point_v<unsigned int>);
  static_assert (!std::is_floating_point_v<long>);
  static_assert (!std::is_floating_point_v<unsigned long>);
  static_assert (!std::is_floating_point_v<long long>);
  static_assert (!std::is_floating_point_v<unsigned long long>);

  static_assert (std::is_floating_point_v<float>);
  static_assert (std::is_floating_point_v<double>);
  static_assert (std::is_floating_point_v<long double>);

#ifndef __STRICT_ANSI__
// GNU Extensions.
#ifdef _GLIBCXX_USE_FLOAT128
  static_assert (std::is_floating_point_v<__float128>);
#endif

#ifdef __SIZEOF_INT128__
  static_assert (!std::is_floating_point_v<__int128>);
  static_assert (!std::is_floating_point_v<unsigned __int128>);
#endif
#endif

  static_assert (!std::is_floating_point_v<Instantiator>);
  static_assert (!std::is_floating_point_v<const Instantiator>);
  static_assert (!std::is_floating_point_v<volatile Instantiator>);
  static_assert (!std::is_floating_point_v<const volatile Instantiator>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!std::is_floating_point_v<void>);
  static_assert (!std::is_floating_point_v<char>);
  static_assert (!std::is_floating_point_v<signed char>);
  static_assert (!std::is_floating_point_v<unsigned char>);
  static_assert (!std::is_floating_point_v<wchar_t>);
  static_assert (!std::is_floating_point_v<short>);
  static_assert (!std::is_floating_point_v<unsigned short>);
  static_assert (!std::is_floating_point_v<int>);
  static_assert (!std::is_floating_point_v<unsigned int>);
  static_assert (!std::is_floating_point_v<long>);
  static_assert (!std::is_floating_point_v<unsigned long>);
  static_assert (!std::is_floating_point_v<long long>);
  static_assert (!std::is_floating_point_v<unsigned long long>);

  static_assert (std::is_floating_point_v<float>);
  static_assert (std::is_floating_point_v<double>);
  static_assert (std::is_floating_point_v<long double>);

#ifndef __STRICT_ANSI__
// GNU Extensions.
#ifdef _GLIBCXX_USE_FLOAT128
  static_assert (std::is_floating_point_v<__float128>);
#endif

#ifdef __SIZEOF_INT128__
  static_assert (!std::is_floating_point_v<__int128>);
  static_assert (!std::is_floating_point_v<unsigned __int128>);
#endif
#endif

  static_assert (!std::is_floating_point_v<Instantiator>);
  static_assert (!std::is_floating_point_v<const Instantiator>);
  static_assert (!std::is_floating_point_v<volatile Instantiator>);
  static_assert (!std::is_floating_point_v<const volatile Instantiator>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
