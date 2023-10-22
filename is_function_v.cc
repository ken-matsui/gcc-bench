#include <type_traits>

#include "./Common.hpp"

#ifdef GSC23_BENCH_A
template <typename _Tp>
inline constexpr bool is_function_v = !std::is_const_v<const _Tp>;
template <typename _Tp> inline constexpr bool is_function_v<_Tp &> = false;
template <typename _Tp> inline constexpr bool is_function_v<_Tp &&> = false;
#endif
#ifdef GSC23_BENCH_B
template <typename _Tp>
inline constexpr bool is_function_v = __is_function (_Tp);
#endif

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (is_function_v<Instantiator (int)>);
  static_assert (is_function_v<Instantiator (int) const>);
  static_assert (!is_function_v<Instantiator (&) (int)>);
  static_assert (!is_function_v<Instantiator (*) (int)>);
  static_assert (!is_function_v<Instantiator>);
  static_assert (!is_function_v<Instantiator &>);
  static_assert (!is_function_v<Instantiator &&>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (is_function_v<Instantiator (int)>);
  static_assert (is_function_v<Instantiator (int) const>);
  static_assert (!is_function_v<Instantiator (&) (int)>);
  static_assert (!is_function_v<Instantiator (*) (int)>);
  static_assert (!is_function_v<Instantiator>);
  static_assert (!is_function_v<Instantiator &>);
  static_assert (!is_function_v<Instantiator &&>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
