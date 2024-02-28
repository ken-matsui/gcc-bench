#include <type_traits>

template <std::size_t C1, std::size_t C2>
struct Instantiator : Instantiator<C1, C2 - 1>
{
  using func_type_v0 = void (*) ();

  static_assert (std::is_invocable<func_type_v0>::value);
  static_assert (!std::is_invocable<func_type_v0, int>::value);

  using func_type_i0 = int (*) ();

  static_assert (std::is_invocable<func_type_i0>::value);
  static_assert (!std::is_invocable<func_type_i0, int>::value);

  using func_type_l0 = int &(*)();

  static_assert (std::is_invocable<func_type_l0>::value);
  static_assert (!std::is_invocable<func_type_l0, int>::value);

  using func_type_ii = int (*) (int);

  static_assert (!std::is_invocable<func_type_ii>::value);
  static_assert (std::is_invocable<func_type_ii, int>::value);

  using func_type_il = int (*) (int &);

  static_assert (!std::is_invocable<func_type_il>::value);
  static_assert (!std::is_invocable<func_type_il, int>::value);
  static_assert (std::is_invocable<func_type_il, int &>::value);

  using func_type_ir = int (*) (int &&);

  static_assert (!std::is_invocable<func_type_ir>::value);
  static_assert (!std::is_invocable<func_type_ir, int &>::value);
  static_assert (std::is_invocable<func_type_ir, int>::value);
  static_assert (std::is_invocable<func_type_ir, int &&>::value);

  struct A
  {
  };

  using mem_type_i = int A::*;

  static_assert (!std::is_invocable<mem_type_i>::value);
  static_assert (!std::is_invocable<mem_type_i, int>::value);
  static_assert (!std::is_invocable<mem_type_i, int *>::value);
  static_assert (!std::is_invocable<mem_type_i, int &>::value);
  static_assert (!std::is_invocable<mem_type_i, int &&>::value);
  static_assert (std::is_invocable<mem_type_i, A>::value);
  static_assert (std::is_invocable<mem_type_i, A *>::value);
  static_assert (std::is_invocable<mem_type_i, A &>::value);
  static_assert (std::is_invocable<mem_type_i, A &&>::value);
  static_assert (std::is_invocable<mem_type_i, const A &>::value);
  static_assert (!std::is_invocable<mem_type_i, A &, int>::value);

  using memfun_type_i = int (A::*) ();

  static_assert (!std::is_invocable<memfun_type_i>::value);
  static_assert (!std::is_invocable<memfun_type_i, int>::value);
  static_assert (!std::is_invocable<memfun_type_i, int *>::value);
  static_assert (!std::is_invocable<memfun_type_i, int &>::value);
  static_assert (!std::is_invocable<memfun_type_i, int &&>::value);
  static_assert (std::is_invocable<memfun_type_i, A>::value);
  static_assert (std::is_invocable<memfun_type_i, A *>::value);
  static_assert (std::is_invocable<memfun_type_i, A &>::value);
  static_assert (std::is_invocable<memfun_type_i, A &&>::value);
  static_assert (!std::is_invocable<memfun_type_i, const A &>::value);
  static_assert (!std::is_invocable<memfun_type_i, A &, int>::value);

  using memfun_type_ic = int (A::*) () const;

  static_assert (!std::is_invocable<memfun_type_ic>::value);
  static_assert (!std::is_invocable<memfun_type_ic, int>::value);
  static_assert (!std::is_invocable<memfun_type_ic, int &>::value);
  static_assert (std::is_invocable<memfun_type_ic, A &>::value);
  static_assert (std::is_invocable<memfun_type_ic, A *>::value);
  static_assert (!std::is_invocable<memfun_type_ic, A &, int>::value);
  static_assert (!std::is_invocable<memfun_type_ic, A *, int &>::value);
  static_assert (std::is_invocable<memfun_type_ic, const A &>::value);
  static_assert (std::is_invocable<memfun_type_ic, const A *>::value);
  static_assert (!std::is_invocable<memfun_type_ic, const A &, int &>::value);
  static_assert (!std::is_invocable<memfun_type_ic, const A *, int>::value);

  using memfun_type_iic = int &(A::*)(int &) const;

  static_assert (!std::is_invocable<memfun_type_iic>::value);
  static_assert (!std::is_invocable<memfun_type_iic, int>::value);
  static_assert (!std::is_invocable<memfun_type_iic, int &>::value);
  static_assert (!std::is_invocable<memfun_type_iic, A &, int>::value);
  static_assert (std::is_invocable<memfun_type_iic, A &, int &>::value);
  static_assert (!std::is_invocable<memfun_type_iic, A *, int>::value);
  static_assert (std::is_invocable<memfun_type_iic, A *, int &>::value);
  static_assert (!std::is_invocable<memfun_type_iic, const A &, int>::value);
  static_assert (
      !std::is_invocable<memfun_type_iic, const A &, int &, int>::value);
  static_assert (std::is_invocable<memfun_type_iic, const A &, int &>::value);
  static_assert (std::is_invocable<memfun_type_iic, const A *, int &>::value);

  struct B
  {
    int &operator() ();
    long &operator() () const;
    bool &operator() (int);

  private:
    void operator() (int, int);
  };
  using CB = const B;

  static_assert (std::is_invocable<B>::value);
  static_assert (std::is_invocable<B &>::value);
  static_assert (std::is_invocable<B &&>::value);
  static_assert (!std::is_invocable<B *>::value);
  static_assert (std::is_invocable<CB>::value);
  static_assert (std::is_invocable<CB &>::value);
  static_assert (!std::is_invocable<CB *>::value);

  static_assert (std::is_invocable<B, int>::value);
  static_assert (std::is_invocable<B &, int>::value);
  static_assert (std::is_invocable<B &&, int>::value);
  static_assert (!std::is_invocable<B *, int>::value);
  static_assert (!std::is_invocable<CB, int>::value);
  static_assert (!std::is_invocable<CB &, int>::value);
  static_assert (!std::is_invocable<CB *, int>::value);

  static_assert (!std::is_invocable<B, int, int>::value);
  static_assert (!std::is_invocable<B &, int, int>::value);
  static_assert (!std::is_invocable<B &&, int, int>::value);
  static_assert (!std::is_invocable<B *, int, int>::value);
  static_assert (!std::is_invocable<CB, int, int>::value);
  static_assert (!std::is_invocable<CB &, int, int>::value);
  static_assert (!std::is_invocable<CB *, int, int>::value);

  struct C : B
  {
    int &operator() () = delete;
  };
  using CC = const C;

  static_assert (!std::is_invocable<C>::value);
  static_assert (!std::is_invocable<C &>::value);
  static_assert (!std::is_invocable<C &&>::value);
  static_assert (!std::is_invocable<C *>::value);
  static_assert (!std::is_invocable<CC>::value);
  static_assert (!std::is_invocable<CC &>::value);
  static_assert (!std::is_invocable<CC *>::value);

  struct D
  {
    B operator* ();
  };
  using CD = const D;

  static_assert (!std::is_invocable<D>::value);

  struct E
  {
    void v ();
  };
  using CE = const E;

  static_assert (!std::is_invocable<E>::value);
  static_assert (!std::is_invocable<void (E::*) ()>::value);
  static_assert (std::is_invocable<void (E::*) (), E>::value);
  static_assert (std::is_invocable<void (E::*) (), E *>::value);
  static_assert (!std::is_invocable<void (E::*) (), CE>::value);

  struct F : E
  {
  };
  using CF = const F;

  static_assert (!std::is_invocable<F>::value);
  static_assert (std::is_invocable<void (E::*) (), F>::value);
  static_assert (std::is_invocable<void (E::*) (), F *>::value);
  static_assert (!std::is_invocable<void (E::*) (), CF>::value);

  struct G
  {
    E operator* ();
  };
  using CG = const G;

  static_assert (!std::is_invocable<G>::value);
  static_assert (std::is_invocable<void (E::*) (), G>::value);
  static_assert (!std::is_invocable<void (E::*) (), G *>::value);
  static_assert (!std::is_invocable<void (E::*) (), CG>::value);

  struct H
  {
    E &operator* ();
  };
  using CH = const H;

  static_assert (!std::is_invocable<H>::value);
  static_assert (std::is_invocable<void (E::*) (), H>::value);
  static_assert (!std::is_invocable<void (E::*) (), H *>::value);
  static_assert (!std::is_invocable<void (E::*) (), CH>::value);

  struct I
  {
    E &&operator* ();
  };
  using CI = const I;

  static_assert (!std::is_invocable<I>::value);
  static_assert (std::is_invocable<void (E::*) (), I>::value);
  static_assert (!std::is_invocable<void (E::*) (), I *>::value);
  static_assert (!std::is_invocable<void (E::*) (), CI>::value);

  struct K
  {
    E *operator* ();
  };
  using CK = const K;

  static_assert (!std::is_invocable<K>::value);
  static_assert (!std::is_invocable<void (E::*) (), K>::value);
  static_assert (!std::is_invocable<void (E::*) (), K *>::value);
  static_assert (!std::is_invocable<void (E::*) (), CK>::value);

  struct L
  {
    CE operator* ();
  };
  using CL = const L;

  static_assert (!std::is_invocable<L>::value);
  static_assert (!std::is_invocable<void (E::*) (), L>::value);
  static_assert (!std::is_invocable<void (E::*) (), L *>::value);
  static_assert (!std::is_invocable<void (E::*) (), CL>::value);

  struct M
  {
    int i;

  private:
    long l;
  };
  using CM = const M;

  static_assert (!std::is_invocable<M>::value);
  static_assert (!std::is_invocable<M &>::value);
  static_assert (!std::is_invocable<M &&>::value);
  static_assert (!std::is_invocable<M *>::value);
  static_assert (!std::is_invocable<CM>::value);
  static_assert (!std::is_invocable<CM &>::value);
  static_assert (!std::is_invocable<CM *>::value);

  static_assert (!std::is_invocable<int M::*>::value);
  static_assert (std::is_invocable<int M::*, M>::value);
  static_assert (std::is_invocable<int M::*, M &>::value);
  static_assert (std::is_invocable<int M::*, M &&>::value);
  static_assert (std::is_invocable<int M::*, M *>::value);
  static_assert (std::is_invocable<int M::*, CM>::value);
  static_assert (std::is_invocable<int M::*, CM &>::value);
  static_assert (std::is_invocable<int M::*, CM *>::value);
  static_assert (!std::is_invocable<int M::*, int>::value);

  static_assert (!std::is_invocable<int CM::*>::value);
  static_assert (std::is_invocable<int CM::*, M>::value);
  static_assert (std::is_invocable<int CM::*, M &>::value);
  static_assert (std::is_invocable<int CM::*, M &&>::value);
  static_assert (std::is_invocable<int CM::*, M *>::value);
  static_assert (std::is_invocable<int CM::*, CM>::value);
  static_assert (std::is_invocable<int CM::*, CM &>::value);
  static_assert (std::is_invocable<int CM::*, CM *>::value);
  static_assert (!std::is_invocable<int CM::*, int>::value);

  static_assert (!std::is_invocable<long M::*>::value);
  static_assert (std::is_invocable<long M::*, M>::value);
  static_assert (std::is_invocable<long M::*, M &>::value);
  static_assert (std::is_invocable<long M::*, M &&>::value);
  static_assert (std::is_invocable<long M::*, M *>::value);
  static_assert (std::is_invocable<long M::*, CM>::value);
  static_assert (std::is_invocable<long M::*, CM &>::value);
  static_assert (std::is_invocable<long M::*, CM *>::value);
  static_assert (!std::is_invocable<long M::*, long>::value);

  static_assert (!std::is_invocable<long CM::*>::value);
  static_assert (std::is_invocable<long CM::*, M>::value);
  static_assert (std::is_invocable<long CM::*, M &>::value);
  static_assert (std::is_invocable<long CM::*, M &&>::value);
  static_assert (std::is_invocable<long CM::*, M *>::value);
  static_assert (std::is_invocable<long CM::*, CM>::value);
  static_assert (std::is_invocable<long CM::*, CM &>::value);
  static_assert (std::is_invocable<long CM::*, CM *>::value);
  static_assert (!std::is_invocable<long CM::*, long>::value);

  static_assert (!std::is_invocable<short M::*>::value);
  static_assert (std::is_invocable<short M::*, M>::value);
  static_assert (std::is_invocable<short M::*, M &>::value);
  static_assert (std::is_invocable<short M::*, M &&>::value);
  static_assert (std::is_invocable<short M::*, M *>::value);
  static_assert (std::is_invocable<short M::*, CM>::value);
  static_assert (std::is_invocable<short M::*, CM &>::value);
  static_assert (std::is_invocable<short M::*, CM *>::value);
  static_assert (!std::is_invocable<short M::*, short>::value);

  static_assert (!std::is_invocable<short CM::*>::value);
  static_assert (std::is_invocable<short CM::*, M>::value);
  static_assert (std::is_invocable<short CM::*, M &>::value);
  static_assert (std::is_invocable<short CM::*, M &&>::value);
  static_assert (std::is_invocable<short CM::*, M *>::value);
  static_assert (std::is_invocable<short CM::*, CM>::value);
  static_assert (std::is_invocable<short CM::*, CM &>::value);
  static_assert (std::is_invocable<short CM::*, CM *>::value);
  static_assert (!std::is_invocable<short CM::*, short>::value);

  struct N
  {
    M operator* ();
  };
  static_assert (std::is_invocable<int M::*, N>::value);
  static_assert (!std::is_invocable<int M::*, N *>::value);

  struct O
  {
    M &operator* ();
  };
  static_assert (std::is_invocable<int M::*, O>::value);
  static_assert (!std::is_invocable<int M::*, O *>::value);

  struct P
  {
    M &&operator* ();
  };
  static_assert (std::is_invocable<int M::*, P>::value);
  static_assert (!std::is_invocable<int M::*, P *>::value);

  struct Q
  {
    M *operator* ();
  };
  static_assert (!std::is_invocable<int M::*, Q>::value);
  static_assert (!std::is_invocable<int M::*, Q *>::value);

  struct S
  {
    void operator() (int, ...);
  };

  static_assert (!std::is_invocable<S>::value);
  static_assert (std::is_invocable<S, int>::value);
  static_assert (std::is_invocable<S, int, int>::value);
  static_assert (std::is_invocable<S, int, int, int>::value);

  static constexpr auto lambda = [] () {};

  static_assert (std::is_invocable<decltype (lambda)>::value);

  template <typename Func, typename... Args> struct can_invoke
  {
    static constexpr bool value = __is_invocable (Func, Args...);
  };

  static_assert (std::is_invocable<decltype (lambda)>::value);

  struct T
  {
    void
    func () const
    {
    }
    int data;
  };

  static_assert (std::is_invocable<decltype (&T::func) &, T &>::value);
  static_assert (std::is_invocable<decltype (&T::data) &, T &>::value);

  struct U
  {
  };
  struct V : U
  {
    U &operator* () = delete;
  };
  static_assert (std::is_invocable<int U::*, V>::value);

  struct W : private U
  {
    U &operator* ();
  };
  static_assert (!std::is_invocable<int U::*, W>::value);

  struct X
  {
    int m;
  };
  struct Y
  {
    X &operator* ();
  };
  struct Z : Y
  {
  };
  static_assert (std::is_invocable<int X::*, Z>::value);
};

template <std::size_t C1> struct Instantiator<C1, 0>
{
  using func_type_v0 = void (*) ();

  static_assert (std::is_invocable<func_type_v0>::value);
  static_assert (!std::is_invocable<func_type_v0, int>::value);

  using func_type_i0 = int (*) ();

  static_assert (std::is_invocable<func_type_i0>::value);
  static_assert (!std::is_invocable<func_type_i0, int>::value);

  using func_type_l0 = int &(*)();

  static_assert (std::is_invocable<func_type_l0>::value);
  static_assert (!std::is_invocable<func_type_l0, int>::value);

  using func_type_ii = int (*) (int);

  static_assert (!std::is_invocable<func_type_ii>::value);
  static_assert (std::is_invocable<func_type_ii, int>::value);

  using func_type_il = int (*) (int &);

  static_assert (!std::is_invocable<func_type_il>::value);
  static_assert (!std::is_invocable<func_type_il, int>::value);
  static_assert (std::is_invocable<func_type_il, int &>::value);

  using func_type_ir = int (*) (int &&);

  static_assert (!std::is_invocable<func_type_ir>::value);
  static_assert (!std::is_invocable<func_type_ir, int &>::value);
  static_assert (std::is_invocable<func_type_ir, int>::value);
  static_assert (std::is_invocable<func_type_ir, int &&>::value);

  struct A
  {
  };

  using mem_type_i = int A::*;

  static_assert (!std::is_invocable<mem_type_i>::value);
  static_assert (!std::is_invocable<mem_type_i, int>::value);
  static_assert (!std::is_invocable<mem_type_i, int *>::value);
  static_assert (!std::is_invocable<mem_type_i, int &>::value);
  static_assert (!std::is_invocable<mem_type_i, int &&>::value);
  static_assert (std::is_invocable<mem_type_i, A>::value);
  static_assert (std::is_invocable<mem_type_i, A *>::value);
  static_assert (std::is_invocable<mem_type_i, A &>::value);
  static_assert (std::is_invocable<mem_type_i, A &&>::value);
  static_assert (std::is_invocable<mem_type_i, const A &>::value);
  static_assert (!std::is_invocable<mem_type_i, A &, int>::value);

  using memfun_type_i = int (A::*) ();

  static_assert (!std::is_invocable<memfun_type_i>::value);
  static_assert (!std::is_invocable<memfun_type_i, int>::value);
  static_assert (!std::is_invocable<memfun_type_i, int *>::value);
  static_assert (!std::is_invocable<memfun_type_i, int &>::value);
  static_assert (!std::is_invocable<memfun_type_i, int &&>::value);
  static_assert (std::is_invocable<memfun_type_i, A>::value);
  static_assert (std::is_invocable<memfun_type_i, A *>::value);
  static_assert (std::is_invocable<memfun_type_i, A &>::value);
  static_assert (std::is_invocable<memfun_type_i, A &&>::value);
  static_assert (!std::is_invocable<memfun_type_i, const A &>::value);
  static_assert (!std::is_invocable<memfun_type_i, A &, int>::value);

  using memfun_type_ic = int (A::*) () const;

  static_assert (!std::is_invocable<memfun_type_ic>::value);
  static_assert (!std::is_invocable<memfun_type_ic, int>::value);
  static_assert (!std::is_invocable<memfun_type_ic, int &>::value);
  static_assert (std::is_invocable<memfun_type_ic, A &>::value);
  static_assert (std::is_invocable<memfun_type_ic, A *>::value);
  static_assert (!std::is_invocable<memfun_type_ic, A &, int>::value);
  static_assert (!std::is_invocable<memfun_type_ic, A *, int &>::value);
  static_assert (std::is_invocable<memfun_type_ic, const A &>::value);
  static_assert (std::is_invocable<memfun_type_ic, const A *>::value);
  static_assert (!std::is_invocable<memfun_type_ic, const A &, int &>::value);
  static_assert (!std::is_invocable<memfun_type_ic, const A *, int>::value);

  using memfun_type_iic = int &(A::*)(int &) const;

  static_assert (!std::is_invocable<memfun_type_iic>::value);
  static_assert (!std::is_invocable<memfun_type_iic, int>::value);
  static_assert (!std::is_invocable<memfun_type_iic, int &>::value);
  static_assert (!std::is_invocable<memfun_type_iic, A &, int>::value);
  static_assert (std::is_invocable<memfun_type_iic, A &, int &>::value);
  static_assert (!std::is_invocable<memfun_type_iic, A *, int>::value);
  static_assert (std::is_invocable<memfun_type_iic, A *, int &>::value);
  static_assert (!std::is_invocable<memfun_type_iic, const A &, int>::value);
  static_assert (
      !std::is_invocable<memfun_type_iic, const A &, int &, int>::value);
  static_assert (std::is_invocable<memfun_type_iic, const A &, int &>::value);
  static_assert (std::is_invocable<memfun_type_iic, const A *, int &>::value);

  struct B
  {
    int &operator() ();
    long &operator() () const;
    bool &operator() (int);

  private:
    void operator() (int, int);
  };
  using CB = const B;

  static_assert (std::is_invocable<B>::value);
  static_assert (std::is_invocable<B &>::value);
  static_assert (std::is_invocable<B &&>::value);
  static_assert (!std::is_invocable<B *>::value);
  static_assert (std::is_invocable<CB>::value);
  static_assert (std::is_invocable<CB &>::value);
  static_assert (!std::is_invocable<CB *>::value);

  static_assert (std::is_invocable<B, int>::value);
  static_assert (std::is_invocable<B &, int>::value);
  static_assert (std::is_invocable<B &&, int>::value);
  static_assert (!std::is_invocable<B *, int>::value);
  static_assert (!std::is_invocable<CB, int>::value);
  static_assert (!std::is_invocable<CB &, int>::value);
  static_assert (!std::is_invocable<CB *, int>::value);

  static_assert (!std::is_invocable<B, int, int>::value);
  static_assert (!std::is_invocable<B &, int, int>::value);
  static_assert (!std::is_invocable<B &&, int, int>::value);
  static_assert (!std::is_invocable<B *, int, int>::value);
  static_assert (!std::is_invocable<CB, int, int>::value);
  static_assert (!std::is_invocable<CB &, int, int>::value);
  static_assert (!std::is_invocable<CB *, int, int>::value);

  struct C : B
  {
    int &operator() () = delete;
  };
  using CC = const C;

  static_assert (!std::is_invocable<C>::value);
  static_assert (!std::is_invocable<C &>::value);
  static_assert (!std::is_invocable<C &&>::value);
  static_assert (!std::is_invocable<C *>::value);
  static_assert (!std::is_invocable<CC>::value);
  static_assert (!std::is_invocable<CC &>::value);
  static_assert (!std::is_invocable<CC *>::value);

  struct D
  {
    B operator* ();
  };
  using CD = const D;

  static_assert (!std::is_invocable<D>::value);

  struct E
  {
    void v ();
  };
  using CE = const E;

  static_assert (!std::is_invocable<E>::value);
  static_assert (!std::is_invocable<void (E::*) ()>::value);
  static_assert (std::is_invocable<void (E::*) (), E>::value);
  static_assert (std::is_invocable<void (E::*) (), E *>::value);
  static_assert (!std::is_invocable<void (E::*) (), CE>::value);

  struct F : E
  {
  };
  using CF = const F;

  static_assert (!std::is_invocable<F>::value);
  static_assert (std::is_invocable<void (E::*) (), F>::value);
  static_assert (std::is_invocable<void (E::*) (), F *>::value);
  static_assert (!std::is_invocable<void (E::*) (), CF>::value);

  struct G
  {
    E operator* ();
  };
  using CG = const G;

  static_assert (!std::is_invocable<G>::value);
  static_assert (std::is_invocable<void (E::*) (), G>::value);
  static_assert (!std::is_invocable<void (E::*) (), G *>::value);
  static_assert (!std::is_invocable<void (E::*) (), CG>::value);

  struct H
  {
    E &operator* ();
  };
  using CH = const H;

  static_assert (!std::is_invocable<H>::value);
  static_assert (std::is_invocable<void (E::*) (), H>::value);
  static_assert (!std::is_invocable<void (E::*) (), H *>::value);
  static_assert (!std::is_invocable<void (E::*) (), CH>::value);

  struct I
  {
    E &&operator* ();
  };
  using CI = const I;

  static_assert (!std::is_invocable<I>::value);
  static_assert (std::is_invocable<void (E::*) (), I>::value);
  static_assert (!std::is_invocable<void (E::*) (), I *>::value);
  static_assert (!std::is_invocable<void (E::*) (), CI>::value);

  struct K
  {
    E *operator* ();
  };
  using CK = const K;

  static_assert (!std::is_invocable<K>::value);
  static_assert (!std::is_invocable<void (E::*) (), K>::value);
  static_assert (!std::is_invocable<void (E::*) (), K *>::value);
  static_assert (!std::is_invocable<void (E::*) (), CK>::value);

  struct L
  {
    CE operator* ();
  };
  using CL = const L;

  static_assert (!std::is_invocable<L>::value);
  static_assert (!std::is_invocable<void (E::*) (), L>::value);
  static_assert (!std::is_invocable<void (E::*) (), L *>::value);
  static_assert (!std::is_invocable<void (E::*) (), CL>::value);

  struct M
  {
    int i;

  private:
    long l;
  };
  using CM = const M;

  static_assert (!std::is_invocable<M>::value);
  static_assert (!std::is_invocable<M &>::value);
  static_assert (!std::is_invocable<M &&>::value);
  static_assert (!std::is_invocable<M *>::value);
  static_assert (!std::is_invocable<CM>::value);
  static_assert (!std::is_invocable<CM &>::value);
  static_assert (!std::is_invocable<CM *>::value);

  static_assert (!std::is_invocable<int M::*>::value);
  static_assert (std::is_invocable<int M::*, M>::value);
  static_assert (std::is_invocable<int M::*, M &>::value);
  static_assert (std::is_invocable<int M::*, M &&>::value);
  static_assert (std::is_invocable<int M::*, M *>::value);
  static_assert (std::is_invocable<int M::*, CM>::value);
  static_assert (std::is_invocable<int M::*, CM &>::value);
  static_assert (std::is_invocable<int M::*, CM *>::value);
  static_assert (!std::is_invocable<int M::*, int>::value);

  static_assert (!std::is_invocable<int CM::*>::value);
  static_assert (std::is_invocable<int CM::*, M>::value);
  static_assert (std::is_invocable<int CM::*, M &>::value);
  static_assert (std::is_invocable<int CM::*, M &&>::value);
  static_assert (std::is_invocable<int CM::*, M *>::value);
  static_assert (std::is_invocable<int CM::*, CM>::value);
  static_assert (std::is_invocable<int CM::*, CM &>::value);
  static_assert (std::is_invocable<int CM::*, CM *>::value);
  static_assert (!std::is_invocable<int CM::*, int>::value);

  static_assert (!std::is_invocable<long M::*>::value);
  static_assert (std::is_invocable<long M::*, M>::value);
  static_assert (std::is_invocable<long M::*, M &>::value);
  static_assert (std::is_invocable<long M::*, M &&>::value);
  static_assert (std::is_invocable<long M::*, M *>::value);
  static_assert (std::is_invocable<long M::*, CM>::value);
  static_assert (std::is_invocable<long M::*, CM &>::value);
  static_assert (std::is_invocable<long M::*, CM *>::value);
  static_assert (!std::is_invocable<long M::*, long>::value);

  static_assert (!std::is_invocable<long CM::*>::value);
  static_assert (std::is_invocable<long CM::*, M>::value);
  static_assert (std::is_invocable<long CM::*, M &>::value);
  static_assert (std::is_invocable<long CM::*, M &&>::value);
  static_assert (std::is_invocable<long CM::*, M *>::value);
  static_assert (std::is_invocable<long CM::*, CM>::value);
  static_assert (std::is_invocable<long CM::*, CM &>::value);
  static_assert (std::is_invocable<long CM::*, CM *>::value);
  static_assert (!std::is_invocable<long CM::*, long>::value);

  static_assert (!std::is_invocable<short M::*>::value);
  static_assert (std::is_invocable<short M::*, M>::value);
  static_assert (std::is_invocable<short M::*, M &>::value);
  static_assert (std::is_invocable<short M::*, M &&>::value);
  static_assert (std::is_invocable<short M::*, M *>::value);
  static_assert (std::is_invocable<short M::*, CM>::value);
  static_assert (std::is_invocable<short M::*, CM &>::value);
  static_assert (std::is_invocable<short M::*, CM *>::value);
  static_assert (!std::is_invocable<short M::*, short>::value);

  static_assert (!std::is_invocable<short CM::*>::value);
  static_assert (std::is_invocable<short CM::*, M>::value);
  static_assert (std::is_invocable<short CM::*, M &>::value);
  static_assert (std::is_invocable<short CM::*, M &&>::value);
  static_assert (std::is_invocable<short CM::*, M *>::value);
  static_assert (std::is_invocable<short CM::*, CM>::value);
  static_assert (std::is_invocable<short CM::*, CM &>::value);
  static_assert (std::is_invocable<short CM::*, CM *>::value);
  static_assert (!std::is_invocable<short CM::*, short>::value);

  struct N
  {
    M operator* ();
  };
  static_assert (std::is_invocable<int M::*, N>::value);
  static_assert (!std::is_invocable<int M::*, N *>::value);

  struct O
  {
    M &operator* ();
  };
  static_assert (std::is_invocable<int M::*, O>::value);
  static_assert (!std::is_invocable<int M::*, O *>::value);

  struct P
  {
    M &&operator* ();
  };
  static_assert (std::is_invocable<int M::*, P>::value);
  static_assert (!std::is_invocable<int M::*, P *>::value);

  struct Q
  {
    M *operator* ();
  };
  static_assert (!std::is_invocable<int M::*, Q>::value);
  static_assert (!std::is_invocable<int M::*, Q *>::value);

  struct S
  {
    void operator() (int, ...);
  };

  static_assert (!std::is_invocable<S>::value);
  static_assert (std::is_invocable<S, int>::value);
  static_assert (std::is_invocable<S, int, int>::value);
  static_assert (std::is_invocable<S, int, int, int>::value);

  static constexpr auto lambda = [] () {};

  static_assert (std::is_invocable<decltype (lambda)>::value);

  template <typename Func, typename... Args> struct can_invoke
  {
    static constexpr bool value = __is_invocable (Func, Args...);
  };

  static_assert (std::is_invocable<decltype (lambda)>::value);

  struct T
  {
    void
    func () const
    {
    }
    int data;
  };

  static_assert (std::is_invocable<decltype (&T::func) &, T &>::value);
  static_assert (std::is_invocable<decltype (&T::data) &, T &>::value);

  struct U
  {
  };
  struct V : U
  {
    U &operator* () = delete;
  };
  static_assert (std::is_invocable<int U::*, V>::value);

  struct W : private U
  {
    U &operator* ();
  };
  static_assert (!std::is_invocable<int U::*, W>::value);

  struct X
  {
    int m;
  };
  struct Y
  {
    X &operator* ();
  };
  struct Z : Y
  {
  };
  static_assert (std::is_invocable<int X::*, Z>::value);
};

int
main ()
{
  // 512 x 1 instantiations
  Instantiator<0, 512> ();
}
