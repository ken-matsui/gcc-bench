#include "./Common.hpp"

template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  using test1_type = std::decay_t<bool>;
  static_assert (std::is_same_v<test1_type, bool>);

  using test2_type = std::decay_t<const int>;
  static_assert (std::is_same_v<test2_type, int>);

  using test3_type = std::decay_t<Instantiator[4]>;
  static_assert (
      std::is_same_v<test3_type, std::remove_extent_t<Instantiator[4]> *>);

  using fn_type = Instantiator ();
  using test4_type = std::decay_t<fn_type>;
  static_assert (std::is_same_v<test4_type, std::add_pointer_t<fn_type> >);

  using cfn_type = Instantiator () const;
  using test5_type = std::decay_t<cfn_type>;
  static_assert (std::is_same_v<test5_type, cfn_type>);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  using test1_type = std::decay_t<bool>;
  static_assert (std::is_same_v<test1_type, bool>);

  using test2_type = std::decay_t<const int>;
  static_assert (std::is_same_v<test2_type, int>);

  using test3_type = std::decay_t<Instantiator[4]>;
  static_assert (
      std::is_same_v<test3_type, std::remove_extent_t<Instantiator[4]> *>);

  using fn_type = Instantiator ();
  using test4_type = std::decay_t<fn_type>;
  static_assert (std::is_same_v<test4_type, std::add_pointer_t<fn_type> >);

  using cfn_type = Instantiator () const;
  using test5_type = std::decay_t<cfn_type>;
  static_assert (std::is_same_v<test5_type, cfn_type>);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
