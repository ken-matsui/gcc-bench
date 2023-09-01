#include <stddef.h>
#include <type_traits>

#include "./Common.hpp"

#ifdef GSOC23_BENCH_A
template <typename T, typename> struct remove_pointer_helper
{
  using type = T;
};

template <typename T, typename U> struct remove_pointer_helper<T, U *>
{
  using type = U;
};

template <typename T>
struct remove_pointer : public remove_pointer_helper<T, std::remove_cv_t<T> >
{
};
#endif
#ifdef GSOC23_BENCH_B
template <typename T> struct remove_pointer
{
  using type = __remove_pointer (T);
};
#endif

template <typename T>
using remove_pointer_t = typename remove_pointer<T>::type;

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!std::is_pointer_v<remove_pointer_t<Instantiator> >);
  static_assert (!std::is_pointer_v<remove_pointer_t<Instantiator *> >);
  static_assert (!std::is_pointer_v<remove_pointer_t<const Instantiator> >);
  static_assert (!std::is_pointer_v<remove_pointer_t<Instantiator *const> >);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!std::is_pointer_v<remove_pointer_t<Instantiator> >);
  static_assert (!std::is_pointer_v<remove_pointer_t<Instantiator *> >);
  static_assert (!std::is_pointer_v<remove_pointer_t<const Instantiator> >);
  static_assert (!std::is_pointer_v<remove_pointer_t<Instantiator *const> >);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
