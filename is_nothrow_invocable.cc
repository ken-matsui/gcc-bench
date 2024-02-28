#include <type_traits>

template <std::size_t C1, std::size_t C2>
struct Instantiator : Instantiator<C1, C2 - 1>
{
  using func_type = void (*) ();
  static_assert (!std::is_nothrow_invocable<func_type>::value);

  using func_type_nt = void (*) () noexcept;
  static_assert (std::is_nothrow_invocable<func_type_nt>::value);

  struct X
  {
  };
  using mem_type = int X::*;
  static_assert (!std::is_nothrow_invocable<mem_type>::value);
  static_assert (!std::is_nothrow_invocable<mem_type, int>::value);
  static_assert (!std::is_nothrow_invocable<mem_type, int &>::value);
  static_assert (std::is_nothrow_invocable<mem_type, X &>::value);

  using memfun_type = int (X::*) ();
  static_assert (!std::is_nothrow_invocable<memfun_type>::value);
  static_assert (!std::is_nothrow_invocable<memfun_type, int>::value);
  static_assert (!std::is_nothrow_invocable<memfun_type, int &>::value);
  static_assert (!std::is_nothrow_invocable<memfun_type, X &>::value);
  static_assert (!std::is_nothrow_invocable<memfun_type, X *>::value);

  using memfun_type_nt = int (X::*) () noexcept;
  static_assert (!std::is_nothrow_invocable<memfun_type_nt>::value);
  static_assert (!std::is_nothrow_invocable<memfun_type_nt, int>::value);
  static_assert (!std::is_nothrow_invocable<memfun_type_nt, int &>::value);
  static_assert (std::is_nothrow_invocable<memfun_type_nt, X &>::value);
  static_assert (std::is_nothrow_invocable<memfun_type_nt, X *>::value);

  struct F
  {
    int &operator() ();
    long &operator() () const noexcept;
    short &operator() (int) &&;
    char &operator() (int) const &noexcept;

  private:
    void operator() (int, int) noexcept;
  };
  using CF = const F;
  static_assert (!std::is_nothrow_invocable<F>::value);
  static_assert (std::is_nothrow_invocable<CF>::value);

  static_assert (!std::is_nothrow_invocable<F, int>::value);
  static_assert (std::is_nothrow_invocable<F &, int>::value);

  static_assert (std::is_nothrow_invocable<CF, int>::value);
  static_assert (std::is_nothrow_invocable<CF &, int>::value);
  static_assert (!std::is_nothrow_invocable<F, int, int>::value);

  struct FX
  {
    X
    operator() () const noexcept
    {
      return {};
    }
  };
  static_assert (std::is_nothrow_invocable<FX>::value);
};

template <std::size_t C1> struct Instantiator<C1, 0>
{
  using func_type = void (*) ();
  static_assert (!std::is_nothrow_invocable<func_type>::value);

  using func_type_nt = void (*) () noexcept;
  static_assert (std::is_nothrow_invocable<func_type_nt>::value);

  struct X
  {
  };
  using mem_type = int X::*;
  static_assert (!std::is_nothrow_invocable<mem_type>::value);
  static_assert (!std::is_nothrow_invocable<mem_type, int>::value);
  static_assert (!std::is_nothrow_invocable<mem_type, int &>::value);
  static_assert (std::is_nothrow_invocable<mem_type, X &>::value);

  using memfun_type = int (X::*) ();
  static_assert (!std::is_nothrow_invocable<memfun_type>::value);
  static_assert (!std::is_nothrow_invocable<memfun_type, int>::value);
  static_assert (!std::is_nothrow_invocable<memfun_type, int &>::value);
  static_assert (!std::is_nothrow_invocable<memfun_type, X &>::value);
  static_assert (!std::is_nothrow_invocable<memfun_type, X *>::value);

  using memfun_type_nt = int (X::*) () noexcept;
  static_assert (!std::is_nothrow_invocable<memfun_type_nt>::value);
  static_assert (!std::is_nothrow_invocable<memfun_type_nt, int>::value);
  static_assert (!std::is_nothrow_invocable<memfun_type_nt, int &>::value);
  static_assert (std::is_nothrow_invocable<memfun_type_nt, X &>::value);
  static_assert (std::is_nothrow_invocable<memfun_type_nt, X *>::value);

  struct F
  {
    int &operator() ();
    long &operator() () const noexcept;
    short &operator() (int) &&;
    char &operator() (int) const &noexcept;

  private:
    void operator() (int, int) noexcept;
  };
  using CF = const F;
  static_assert (!std::is_nothrow_invocable<F>::value);
  static_assert (std::is_nothrow_invocable<CF>::value);

  static_assert (!std::is_nothrow_invocable<F, int>::value);
  static_assert (std::is_nothrow_invocable<F &, int>::value);

  static_assert (std::is_nothrow_invocable<CF, int>::value);
  static_assert (std::is_nothrow_invocable<CF &, int>::value);
  static_assert (!std::is_nothrow_invocable<F, int, int>::value);

  struct FX
  {
    X
    operator() () const noexcept
    {
      return {};
    }
  };
  static_assert (std::is_nothrow_invocable<FX>::value);
};

int
main ()
{
  // 512 x 1 instantiations
  Instantiator<0, 512> ();
}
