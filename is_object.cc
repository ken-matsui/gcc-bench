#include <cstddef>
#include <type_traits>

#include "./Common.hpp"

template <typename T>
struct is_object
    : public std::negation<std::disjunction<
          std::is_function<T>, std::is_reference<T>, std::is_void<T> > >::type
{
};

#ifdef GSOC23_BENCH_A
template <typename T> inline constexpr bool is_object_v = is_object<T>::value;
#endif
#ifdef GSOC23_BENCH_B
template <typename T>
inline constexpr bool is_object_v
    = !(__is_function (T) || __is_reference (T) || __is_void (T));
#endif

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (is_object_v<Instantiator>);
  static_assert (!is_object_v<Instantiator &>);
  static_assert (!is_object_v<Instantiator (int)>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (is_object_v<Instantiator>);
  static_assert (!is_object_v<Instantiator &>);
  static_assert (!is_object_v<Instantiator (int)>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
