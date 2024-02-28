#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (std::is_same_v<std::add_pointer_t<int>, int *>);
  static_assert (std::is_same_v<std::add_pointer_t<int *>, int **>);
  static_assert (std::is_same_v<std::add_pointer_t<const int>, const int *>);
  static_assert (std::is_same_v<std::add_pointer_t<int &>, int *>);
  static_assert (
      std::is_same_v<std::add_pointer_t<Instantiator *>, Instantiator **>);
  static_assert (
      std::is_same_v<std::add_pointer_t<Instantiator>, Instantiator *>);
  static_assert (std::is_same_v<std::add_pointer_t<void>, void *>);
  static_assert (std::is_same_v<std::add_pointer_t<const void>, const void *>);
  static_assert (
      std::is_same_v<std::add_pointer_t<volatile void>, volatile void *>);
  static_assert (std::is_same_v<std::add_pointer_t<const volatile void>,
                                const volatile void *>);

  using fn_type = void ();
  using pfn_type = void (*) ();
  static_assert (std::is_same_v<std::add_pointer_t<fn_type>, pfn_type>);

  static_assert (std::is_same_v<std::add_pointer_t<void () &>, void () &>);
  static_assert (std::is_same_v<std::add_pointer_t<void () & noexcept>,
                                void () & noexcept>);
  static_assert (
      std::is_same_v<std::add_pointer_t<void () const>, void () const>);
  static_assert (
      std::is_same_v<std::add_pointer_t<void (...) &>, void (...) &>);
  static_assert (std::is_same_v<std::add_pointer_t<void (...) & noexcept>,
                                void (...) & noexcept>);
  static_assert (
      std::is_same_v<std::add_pointer_t<void (...) const>, void (...) const>);

  static_assert (std::is_same_v<std::add_pointer_t<void () __restrict>,
                                void () __restrict>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (std::is_same_v<std::add_pointer_t<int>, int *>);
  static_assert (std::is_same_v<std::add_pointer_t<int *>, int **>);
  static_assert (std::is_same_v<std::add_pointer_t<const int>, const int *>);
  static_assert (std::is_same_v<std::add_pointer_t<int &>, int *>);
  static_assert (
      std::is_same_v<std::add_pointer_t<Instantiator *>, Instantiator **>);
  static_assert (
      std::is_same_v<std::add_pointer_t<Instantiator>, Instantiator *>);
  static_assert (std::is_same_v<std::add_pointer_t<void>, void *>);
  static_assert (std::is_same_v<std::add_pointer_t<const void>, const void *>);
  static_assert (
      std::is_same_v<std::add_pointer_t<volatile void>, volatile void *>);
  static_assert (std::is_same_v<std::add_pointer_t<const volatile void>,
                                const volatile void *>);

  using fn_type = void ();
  using pfn_type = void (*) ();
  static_assert (std::is_same_v<std::add_pointer_t<fn_type>, pfn_type>);

  static_assert (std::is_same_v<std::add_pointer_t<void () &>, void () &>);
  static_assert (std::is_same_v<std::add_pointer_t<void () & noexcept>,
                                void () & noexcept>);
  static_assert (
      std::is_same_v<std::add_pointer_t<void () const>, void () const>);
  static_assert (
      std::is_same_v<std::add_pointer_t<void (...) &>, void (...) &>);
  static_assert (std::is_same_v<std::add_pointer_t<void (...) & noexcept>,
                                void (...) & noexcept>);
  static_assert (
      std::is_same_v<std::add_pointer_t<void (...) const>, void (...) const>);

  static_assert (std::is_same_v<std::add_pointer_t<void () __restrict>,
                                void () __restrict>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
