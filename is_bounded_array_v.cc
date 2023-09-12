#include <cstddef>

#include "./Common.hpp"

#ifdef GSOC23_BENCH_A
template <typename _Tp> inline constexpr bool is_bounded_array_v = false;

template <typename _Tp, size_t _Size>
inline constexpr bool is_bounded_array_v<_Tp[_Size]> = true;
#endif
#ifdef GSOC23_BENCH_B
template <typename _Tp>
inline constexpr bool is_bounded_array_v = __is_bounded_array (_Tp);
#endif

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (is_bounded_array_v<Instantiator[2]>);
  static_assert (is_bounded_array_v<const Instantiator[2]>);
  static_assert (is_bounded_array_v<volatile Instantiator[2]>);
  static_assert (is_bounded_array_v<const volatile Instantiator[2]>);

  static_assert (!is_bounded_array_v<Instantiator[]>);
  static_assert (!is_bounded_array_v<const Instantiator[]>);
  static_assert (!is_bounded_array_v<volatile Instantiator[]>);
  static_assert (!is_bounded_array_v<const volatile Instantiator[]>);

  static_assert (is_bounded_array_v<Instantiator[2][3]>);
  static_assert (is_bounded_array_v<const Instantiator[2][3]>);
  static_assert (is_bounded_array_v<volatile Instantiator[2][3]>);
  static_assert (is_bounded_array_v<const volatile Instantiator[2][3]>);

  static_assert (!is_bounded_array_v<Instantiator[][3]>);
  static_assert (!is_bounded_array_v<const Instantiator[][3]>);
  static_assert (!is_bounded_array_v<volatile Instantiator[][3]>);
  static_assert (!is_bounded_array_v<const volatile Instantiator[][3]>);

  static_assert (is_bounded_array_v<Instantiator *[2]>);
  static_assert (is_bounded_array_v<const Instantiator *[2]>);
  static_assert (is_bounded_array_v<volatile Instantiator *[2]>);
  static_assert (is_bounded_array_v<const volatile Instantiator *[2]>);

  static_assert (!is_bounded_array_v<Instantiator *[]>);
  static_assert (!is_bounded_array_v<const Instantiator *[]>);
  static_assert (!is_bounded_array_v<volatile Instantiator *[]>);
  static_assert (!is_bounded_array_v<const volatile Instantiator *[]>);

  static_assert (is_bounded_array_v<Instantiator *[2][3]>);
  static_assert (is_bounded_array_v<const Instantiator *[2][3]>);
  static_assert (is_bounded_array_v<volatile Instantiator *[2][3]>);
  static_assert (is_bounded_array_v<const volatile Instantiator *[2][3]>);

  static_assert (!is_bounded_array_v<Instantiator *[][3]>);
  static_assert (!is_bounded_array_v<const Instantiator *[][3]>);
  static_assert (!is_bounded_array_v<volatile Instantiator *[][3]>);
  static_assert (!is_bounded_array_v<const volatile Instantiator *[][3]>);

  static_assert (!is_bounded_array_v<Instantiator (*)[2]>);
  static_assert (!is_bounded_array_v<const Instantiator (*)[2]>);
  static_assert (!is_bounded_array_v<volatile Instantiator (*)[2]>);
  static_assert (!is_bounded_array_v<const volatile Instantiator (*)[2]>);

  static_assert (!is_bounded_array_v<Instantiator (*)[]>);
  static_assert (!is_bounded_array_v<const Instantiator (*)[]>);
  static_assert (!is_bounded_array_v<volatile Instantiator (*)[]>);
  static_assert (!is_bounded_array_v<const volatile Instantiator (*)[]>);

  static_assert (!is_bounded_array_v<Instantiator (&)[2]>);
  static_assert (!is_bounded_array_v<const Instantiator (&)[2]>);
  static_assert (!is_bounded_array_v<volatile Instantiator (&)[2]>);
  static_assert (!is_bounded_array_v<const volatile Instantiator (&)[2]>);

  static_assert (!is_bounded_array_v<Instantiator (&)[]>);
  static_assert (!is_bounded_array_v<const Instantiator (&)[]>);
  static_assert (!is_bounded_array_v<volatile Instantiator (&)[]>);
  static_assert (!is_bounded_array_v<const volatile Instantiator (&)[]>);

  static_assert (!is_bounded_array_v<Instantiator>);
  static_assert (!is_bounded_array_v<const Instantiator>);
  static_assert (!is_bounded_array_v<volatile Instantiator>);
  static_assert (!is_bounded_array_v<const volatile Instantiator>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (is_bounded_array_v<Instantiator[2]>);
  static_assert (is_bounded_array_v<const Instantiator[2]>);
  static_assert (is_bounded_array_v<volatile Instantiator[2]>);
  static_assert (is_bounded_array_v<const volatile Instantiator[2]>);

  static_assert (!is_bounded_array_v<Instantiator[]>);
  static_assert (!is_bounded_array_v<const Instantiator[]>);
  static_assert (!is_bounded_array_v<volatile Instantiator[]>);
  static_assert (!is_bounded_array_v<const volatile Instantiator[]>);

  static_assert (is_bounded_array_v<Instantiator[2][3]>);
  static_assert (is_bounded_array_v<const Instantiator[2][3]>);
  static_assert (is_bounded_array_v<volatile Instantiator[2][3]>);
  static_assert (is_bounded_array_v<const volatile Instantiator[2][3]>);

  static_assert (!is_bounded_array_v<Instantiator[][3]>);
  static_assert (!is_bounded_array_v<const Instantiator[][3]>);
  static_assert (!is_bounded_array_v<volatile Instantiator[][3]>);
  static_assert (!is_bounded_array_v<const volatile Instantiator[][3]>);

  static_assert (is_bounded_array_v<Instantiator *[2]>);
  static_assert (is_bounded_array_v<const Instantiator *[2]>);
  static_assert (is_bounded_array_v<volatile Instantiator *[2]>);
  static_assert (is_bounded_array_v<const volatile Instantiator *[2]>);

  static_assert (!is_bounded_array_v<Instantiator *[]>);
  static_assert (!is_bounded_array_v<const Instantiator *[]>);
  static_assert (!is_bounded_array_v<volatile Instantiator *[]>);
  static_assert (!is_bounded_array_v<const volatile Instantiator *[]>);

  static_assert (is_bounded_array_v<Instantiator *[2][3]>);
  static_assert (is_bounded_array_v<const Instantiator *[2][3]>);
  static_assert (is_bounded_array_v<volatile Instantiator *[2][3]>);
  static_assert (is_bounded_array_v<const volatile Instantiator *[2][3]>);

  static_assert (!is_bounded_array_v<Instantiator *[][3]>);
  static_assert (!is_bounded_array_v<const Instantiator *[][3]>);
  static_assert (!is_bounded_array_v<volatile Instantiator *[][3]>);
  static_assert (!is_bounded_array_v<const volatile Instantiator *[][3]>);

  static_assert (!is_bounded_array_v<Instantiator (*)[2]>);
  static_assert (!is_bounded_array_v<const Instantiator (*)[2]>);
  static_assert (!is_bounded_array_v<volatile Instantiator (*)[2]>);
  static_assert (!is_bounded_array_v<const volatile Instantiator (*)[2]>);

  static_assert (!is_bounded_array_v<Instantiator (*)[]>);
  static_assert (!is_bounded_array_v<const Instantiator (*)[]>);
  static_assert (!is_bounded_array_v<volatile Instantiator (*)[]>);
  static_assert (!is_bounded_array_v<const volatile Instantiator (*)[]>);

  static_assert (!is_bounded_array_v<Instantiator (&)[2]>);
  static_assert (!is_bounded_array_v<const Instantiator (&)[2]>);
  static_assert (!is_bounded_array_v<volatile Instantiator (&)[2]>);
  static_assert (!is_bounded_array_v<const volatile Instantiator (&)[2]>);

  static_assert (!is_bounded_array_v<Instantiator (&)[]>);
  static_assert (!is_bounded_array_v<const Instantiator (&)[]>);
  static_assert (!is_bounded_array_v<volatile Instantiator (&)[]>);
  static_assert (!is_bounded_array_v<const volatile Instantiator (&)[]>);

  static_assert (!is_bounded_array_v<Instantiator>);
  static_assert (!is_bounded_array_v<const Instantiator>);
  static_assert (!is_bounded_array_v<volatile Instantiator>);
  static_assert (!is_bounded_array_v<const volatile Instantiator>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
