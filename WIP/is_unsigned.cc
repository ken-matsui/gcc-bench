#include <type_traits>

#include "./Common.hpp"

template <typename _Tp>
struct is_unsigned
    : public std::conjunction<std::is_arithmetic<_Tp>,
                              std::negation<std::is_signed<_Tp> > >::type
{
};

#ifdef GSOC23_BENCH_A
template <typename T>
inline constexpr bool is_unsigned_v = is_unsigned<T>::value;
#endif
#ifdef GSOC23_BENCH_B
template <typename T> inline constexpr bool is_unsigned_v = __is_unsigned (T);
#endif

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!is_unsigned_v<void>);

  static_assert (is_unsigned_v<bool> == (bool (-1) > bool (0)));
  static_assert (is_unsigned_v<char> == (char (-1) > char (0)));
  static_assert (!is_unsigned_v<signed char>);
  static_assert (is_unsigned_v<unsigned char>);
  static_assert (is_unsigned_v<wchar_t> == (wchar_t (-1) > wchar_t (0)));
  static_assert (!is_unsigned_v<short>);
  static_assert (is_unsigned_v<unsigned short>);
  static_assert (!is_unsigned_v<int>);
  static_assert (is_unsigned_v<unsigned int>);
  static_assert (!is_unsigned_v<long>);
  static_assert (is_unsigned_v<unsigned long>);
  static_assert (!is_unsigned_v<long long>);
  static_assert (is_unsigned_v<unsigned long long>);

  static_assert (!is_unsigned_v<float>);
  static_assert (!is_unsigned_v<double>);
  static_assert (!is_unsigned_v<long double>);

  static_assert (!is_unsigned_v<Instantiator>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!is_unsigned_v<void>);

  static_assert (is_unsigned_v<bool> == (bool (-1) > bool (0)));
  static_assert (is_unsigned_v<char> == (char (-1) > char (0)));
  static_assert (!is_unsigned_v<signed char>);
  static_assert (is_unsigned_v<unsigned char>);
  static_assert (is_unsigned_v<wchar_t> == (wchar_t (-1) > wchar_t (0)));
  static_assert (!is_unsigned_v<short>);
  static_assert (is_unsigned_v<unsigned short>);
  static_assert (!is_unsigned_v<int>);
  static_assert (is_unsigned_v<unsigned int>);
  static_assert (!is_unsigned_v<long>);
  static_assert (is_unsigned_v<unsigned long>);
  static_assert (!is_unsigned_v<long long>);
  static_assert (is_unsigned_v<unsigned long long>);

  static_assert (!is_unsigned_v<float>);
  static_assert (!is_unsigned_v<double>);
  static_assert (!is_unsigned_v<long double>);

  static_assert (!is_unsigned_v<Instantiator>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
