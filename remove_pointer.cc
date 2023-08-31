#include <stddef.h>
#include <type_traits>

#ifdef USE_BUILTIN
template <typename T> struct remove_pointer
{
  using type = __remove_pointer (T);
};
#else
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

template <typename T>
using remove_pointer_t = typename remove_pointer<T>::type;

template <std::size_t N, std::size_t Count = 256>
struct Instantiator : Instantiator<N, Count - 1>
{
  static_assert (!std::is_pointer_v<remove_pointer_t<Instantiator> >);
  static_assert (!std::is_pointer_v<remove_pointer_t<Instantiator *> >);
  static_assert (!std::is_pointer_v<remove_pointer_t<const Instantiator> >);
  static_assert (!std::is_pointer_v<remove_pointer_t<Instantiator *const> >);
};
template <std::size_t N> struct Instantiator<N, 0>
{
  static_assert (!std::is_pointer_v<remove_pointer_t<Instantiator> >);
  static_assert (!std::is_pointer_v<remove_pointer_t<Instantiator *> >);
  static_assert (!std::is_pointer_v<remove_pointer_t<const Instantiator> >);
  static_assert (!std::is_pointer_v<remove_pointer_t<Instantiator *const> >);
};

template <std::size_t base>
void
instantiate10x256 ()
{
  Instantiator<base + 0> ();
  Instantiator<base + 1> ();
  Instantiator<base + 2> ();
  Instantiator<base + 3> ();
  Instantiator<base + 4> ();
  Instantiator<base + 5> ();
  Instantiator<base + 6> ();
  Instantiator<base + 7> ();
  Instantiator<base + 8> ();
  Instantiator<base + 9> ();
}

template <std::size_t base>
void
instantiate100x256 ()
{
  instantiate10x256<base + 0> ();
  instantiate10x256<base + 10> ();
  instantiate10x256<base + 20> ();
  instantiate10x256<base + 30> ();
  instantiate10x256<base + 40> ();
  instantiate10x256<base + 50> ();
  instantiate10x256<base + 60> ();
  instantiate10x256<base + 70> ();
  instantiate10x256<base + 80> ();
  instantiate10x256<base + 90> ();
}

void
instantiate1000x256 ()
{
  instantiate100x256<0> ();
  instantiate100x256<1> ();
  instantiate100x256<2> ();
  instantiate100x256<3> ();
  instantiate100x256<4> ();
  instantiate100x256<5> ();
  instantiate100x256<6> ();
  instantiate100x256<7> ();
  instantiate100x256<8> ();
  instantiate100x256<9> ();
}

int
main ()
{
  instantiate1000x256 ();
}
