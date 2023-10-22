#include <type_traits>

#include "./Common.hpp"

template <typename _Tp>
struct is_fundamental
    : public std::disjunction<std::is_arithmetic<_Tp>, std::is_void<_Tp>,
                              std::is_null_pointer<_Tp> >::type
{
};

#ifdef GSOC23_BENCH_A
template <typename _Tp>
inline constexpr bool is_fundamental_v = is_fundamental<_Tp>::value;
#endif
#ifdef GSOC23_BENCH_B
template <typename _Tp>
inline constexpr bool is_fundamental_v
    = __is_arithmetic (_Tp)
      || std::is_void_v<_Tp> || std::is_null_pointer_v<_Tp>;
#endif

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (is_fundamental_v<int>);
  static_assert (is_fundamental_v<void>);
  static_assert (is_fundamental_v<std::nullptr_t>);
  static_assert (!is_fundamental_v<Instantiator>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (is_fundamental_v<int>);
  static_assert (is_fundamental_v<void>);
  static_assert (is_fundamental_v<std::nullptr_t>);
  static_assert (!is_fundamental_v<Instantiator>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
