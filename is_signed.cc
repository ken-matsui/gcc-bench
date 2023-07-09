#include <type_traits>

template<typename _Tp, bool = std::is_arithmetic<_Tp>::value>
struct is_signed_helper
: public std::false_type
{ };
template<typename _Tp>
struct is_signed_helper<_Tp, true>
: public std::bool_constant<_Tp(-1) < _Tp(0)>
{ };

template<typename _Tp>
struct is_signed
: public is_signed_helper<_Tp>::type
{ };

#ifdef USE_BUILTIN
template <typename T>
inline constexpr bool is_signed_v = __is_signed(T);
#else
template <typename T>
inline constexpr bool is_signed_v = is_signed<T>::value;
#endif

template <std::size_t N, std::size_t Count = 256>
struct Instantiator : Instantiator<N, Count - 1> {
    static_assert(!is_signed_v<void>);

    static_assert(is_signed_v<bool> == (bool(-1) < bool(0)));
    static_assert(is_signed_v<char> == (char(-1) < char(0)));
    static_assert(is_signed_v<signed char>);
    static_assert(!is_signed_v<unsigned char>);
    static_assert(is_signed_v<wchar_t> == (wchar_t(-1) < wchar_t(0)));
    static_assert(is_signed_v<short>);
    static_assert(!is_signed_v<unsigned short>);
    static_assert(is_signed_v<int>);
    static_assert(!is_signed_v<unsigned int>);
    static_assert(is_signed_v<long>);
    static_assert(!is_signed_v<unsigned long>);
    static_assert(is_signed_v<long long>);
    static_assert(!is_signed_v<unsigned long long>);

    static_assert(is_signed_v<float>);
    static_assert(is_signed_v<double>);
    static_assert(is_signed_v<long double>);

    static_assert(!is_signed_v<Instantiator>);
};
template <std::size_t N>
struct Instantiator<N, 0> {
    static_assert(!is_signed_v<void>);

    static_assert(is_signed_v<bool> == (bool(-1) < bool(0)));
    static_assert(is_signed_v<char> == (char(-1) < char(0)));
    static_assert(is_signed_v<signed char>);
    static_assert(!is_signed_v<unsigned char>);
    static_assert(is_signed_v<wchar_t> == (wchar_t(-1) < wchar_t(0)));
    static_assert(is_signed_v<short>);
    static_assert(!is_signed_v<unsigned short>);
    static_assert(is_signed_v<int>);
    static_assert(!is_signed_v<unsigned int>);
    static_assert(is_signed_v<long>);
    static_assert(!is_signed_v<unsigned long>);
    static_assert(is_signed_v<long long>);
    static_assert(!is_signed_v<unsigned long long>);

    static_assert(is_signed_v<float>);
    static_assert(is_signed_v<double>);
    static_assert(is_signed_v<long double>);

    static_assert(!is_signed_v<Instantiator>);
};

template <std::size_t base>
void instantiate10x256() {
    Instantiator<base + 0>();
    Instantiator<base + 1>();
    Instantiator<base + 2>();
    Instantiator<base + 3>();
    Instantiator<base + 4>();
    Instantiator<base + 5>();
    Instantiator<base + 6>();
    Instantiator<base + 7>();
    Instantiator<base + 8>();
    Instantiator<base + 9>();
}

template <std::size_t base>
void instantiate100x256() {
    instantiate10x256<base + 0>();
    instantiate10x256<base + 10>();
    instantiate10x256<base + 20>();
    instantiate10x256<base + 30>();
    instantiate10x256<base + 40>();
    instantiate10x256<base + 50>();
    instantiate10x256<base + 60>();
    instantiate10x256<base + 70>();
    instantiate10x256<base + 80>();
    instantiate10x256<base + 90>();
}

void instantiate1000x256() {
    instantiate100x256<0>();
    instantiate100x256<1>();
    instantiate100x256<2>();
    instantiate100x256<3>();
    instantiate100x256<4>();
    instantiate100x256<5>();
    instantiate100x256<6>();
    instantiate100x256<7>();
    instantiate100x256<8>();
    instantiate100x256<9>();
}

int main() {
    instantiate1000x256();
}
