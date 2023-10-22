#include <type_traits>

#include "./Common.hpp"

template <typename _Tp, bool = std::is_arithmetic<_Tp>::value>
struct is_signed_helper : public std::false_type
{
};
template <typename _Tp>
struct is_signed_helper<_Tp, true>
    : public std::bool_constant<_Tp (-1) < _Tp (0)>
{
};

template <typename _Tp> struct is_signed : public is_signed_helper<_Tp>::type
{
};

#ifdef GSON23_BENCH_A
template <typename T> inline constexpr bool is_signed_v = is_signed<T>::value;
#endif
#ifdef GSON23_BENCH_B
template <typename T> inline constexpr bool is_signed_v = __is_signed (T);
#endif

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!is_signed_v<void>);

  static_assert (is_signed_v<bool> == (bool (-1) < bool (0)));
  static_assert (is_signed_v<char> == (char (-1) < char (0)));
  static_assert (is_signed_v<signed char>);
  static_assert (!is_signed_v<unsigned char>);
  static_assert (is_signed_v<wchar_t> == (wchar_t (-1) < wchar_t (0)));
  static_assert (is_signed_v<short>);
  static_assert (!is_signed_v<unsigned short>);
  static_assert (is_signed_v<int>);
  static_assert (!is_signed_v<unsigned int>);
  static_assert (is_signed_v<long>);
  static_assert (!is_signed_v<unsigned long>);
  static_assert (is_signed_v<long long>);
  static_assert (!is_signed_v<unsigned long long>);

  static_assert (is_signed_v<float>);
  static_assert (is_signed_v<double>);
  static_assert (is_signed_v<long double>);

  static_assert (!is_signed_v<Instantiator>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!is_signed_v<void>);

  static_assert (is_signed_v<bool> == (bool (-1) < bool (0)));
  static_assert (is_signed_v<char> == (char (-1) < char (0)));
  static_assert (is_signed_v<signed char>);
  static_assert (!is_signed_v<unsigned char>);
  static_assert (is_signed_v<wchar_t> == (wchar_t (-1) < wchar_t (0)));
  static_assert (is_signed_v<short>);
  static_assert (!is_signed_v<unsigned short>);
  static_assert (is_signed_v<int>);
  static_assert (!is_signed_v<unsigned int>);
  static_assert (is_signed_v<long>);
  static_assert (!is_signed_v<unsigned long>);
  static_assert (is_signed_v<long long>);
  static_assert (!is_signed_v<unsigned long long>);

  static_assert (is_signed_v<float>);
  static_assert (is_signed_v<double>);
  static_assert (is_signed_v<long double>);

  static_assert (!is_signed_v<Instantiator>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
