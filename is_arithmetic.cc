#include <type_traits>

template<typename _Tp>
struct is_arithmetic
: public std::disjunction<std::is_integral<_Tp>, std::is_floating_point<_Tp>>::type
{ };

#ifdef USE_BUILTIN
template <typename T>
inline constexpr bool is_arithmetic_v = __is_arithmetic(T);
#else
template <typename T>
inline constexpr bool is_arithmetic_v = is_arithmetic<T>::value;
#endif

template <std::size_t N, std::size_t Count = 256>
struct Instantiator : Instantiator<N, Count - 1> {
    static_assert(is_arithmetic_v<int>);
    static_assert(is_arithmetic_v<float>);
    static_assert(!is_arithmetic_v<Instantiator>);
};
template <std::size_t N>
struct Instantiator<N, 0> {
    static_assert(is_arithmetic_v<int>);
    static_assert(is_arithmetic_v<float>);
    static_assert(!is_arithmetic_v<Instantiator>);
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
