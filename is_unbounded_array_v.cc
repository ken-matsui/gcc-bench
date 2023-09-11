#include <cstddef>

#include "./Common.hpp"

#ifdef GSOC23_BENCH_A
template <typename _Tp> inline constexpr bool is_unbounded_array_v = false;

template <typename _Tp>
inline constexpr bool is_unbounded_array_v<_Tp[]> = true;
#endif
#ifdef GSOC23_BENCH_B
template <typename _Tp>
inline constexpr bool is_unbounded_array_v = __is_unbounded_array (_Tp);
#endif

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!is_unbounded_array_v<Instantiator[2]>);
  static_assert (is_unbounded_array_v<Instantiator[]>);
  static_assert (!is_unbounded_array_v<Instantiator[2][3]>);
  static_assert (is_unbounded_array_v<Instantiator[][3]>);
  static_assert (!is_unbounded_array_v<Instantiator *[2]>);
  static_assert (is_unbounded_array_v<Instantiator *[]>);
  static_assert (!is_unbounded_array_v<Instantiator *[2][3]>);
  static_assert (is_unbounded_array_v<Instantiator *[][3]>);
  static_assert (!is_unbounded_array_v<Instantiator (*)[2]>);
  static_assert (!is_unbounded_array_v<Instantiator (*)[]>);
  static_assert (!is_unbounded_array_v<Instantiator (*)[2][3]>);
  static_assert (!is_unbounded_array_v<Instantiator (*)[][3]>);
  static_assert (!is_unbounded_array_v<Instantiator>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!is_unbounded_array_v<Instantiator[2]>);
  static_assert (is_unbounded_array_v<Instantiator[]>);
  static_assert (!is_unbounded_array_v<Instantiator[2][3]>);
  static_assert (is_unbounded_array_v<Instantiator[][3]>);
  static_assert (!is_unbounded_array_v<Instantiator *[2]>);
  static_assert (is_unbounded_array_v<Instantiator *[]>);
  static_assert (!is_unbounded_array_v<Instantiator *[2][3]>);
  static_assert (is_unbounded_array_v<Instantiator *[][3]>);
  static_assert (!is_unbounded_array_v<Instantiator (*)[2]>);
  static_assert (!is_unbounded_array_v<Instantiator (*)[]>);
  static_assert (!is_unbounded_array_v<Instantiator (*)[2][3]>);
  static_assert (!is_unbounded_array_v<Instantiator (*)[][3]>);
  static_assert (!is_unbounded_array_v<Instantiator>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
