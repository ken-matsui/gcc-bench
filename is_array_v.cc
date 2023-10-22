#include <cstddef>

#include "./Common.hpp"

#ifdef GSON23_BENCH_A
template <typename _Tp> inline constexpr bool is_array_v = false;
template <typename _Tp> inline constexpr bool is_array_v<_Tp[]> = true;
template <typename _Tp, size_t _Num>
inline constexpr bool is_array_v<_Tp[_Num]> = true;
#endif
#ifdef GSON23_BENCH_B
template <typename _Tp> inline constexpr bool is_array_v = __is_array (_Tp);
#endif

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!is_array_v<Instantiator>);
  static_assert (is_array_v<Instantiator[]>);
  static_assert (is_array_v<Instantiator[Count]>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!is_array_v<Instantiator>);
  static_assert (is_array_v<Instantiator[]>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
