#include <type_traits>

#include "./Common.hpp"

template <typename _Tp>
struct is_arithmetic
    : public std::disjunction<std::is_integral<_Tp>,
                              std::is_floating_point<_Tp> >::type
{
};

#ifdef GSOC23_BENCH_A
template <typename T>
inline constexpr bool is_arithmetic_v = is_arithmetic<T>::value;
#endif
#ifdef GSOC23_BENCH_B
template <typename T>
inline constexpr bool is_arithmetic_v = __is_arithmetic (T);
#endif

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (is_arithmetic_v<int>);
  static_assert (is_arithmetic_v<float>);
  static_assert (!is_arithmetic_v<Instantiator>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (is_arithmetic_v<int>);
  static_assert (is_arithmetic_v<float>);
  static_assert (!is_arithmetic_v<Instantiator>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
