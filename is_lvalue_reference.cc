#include <type_traits>

#include "./Common.hpp"

#ifdef GSOC23_BENCH_A
template <typename> struct is_lvalue_reference : public std::false_type
{
};

template <typename _Tp>
struct is_lvalue_reference<_Tp &> : public std::true_type
{
};
#endif
#ifdef GSOC23_BENCH_B
template <typename _Tp>
struct is_lvalue_reference
    : public std::bool_constant<__is_lvalue_reference (_Tp)>
{
};
#endif

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!is_lvalue_reference<Instantiator>::value);
  static_assert (is_lvalue_reference<Instantiator &>::value);
  static_assert (!is_lvalue_reference<Instantiator &&>::value);
  static_assert (!is_lvalue_reference<Instantiator *>::value);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!is_lvalue_reference<Instantiator>::value);
  static_assert (is_lvalue_reference<Instantiator &>::value);
  static_assert (!is_lvalue_reference<Instantiator &&>::value);
  static_assert (!is_lvalue_reference<Instantiator *>::value);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
