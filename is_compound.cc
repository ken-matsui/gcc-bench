#include "./Common.hpp"
template <std::size_t N, std::size_t Count>
struct gsoc23::Instantiator : gsoc23::Instantiator<N, Count - 1>
{
  static_assert (!std::is_compound<void>::value);
  static_assert (!std::is_compound<char>::value);
  static_assert (!std::is_compound<signed char>::value);
  static_assert (!std::is_compound<unsigned char>::value);
  static_assert (!std::is_compound<wchar_t>::value);
  static_assert (!std::is_compound<short>::value);
  static_assert (!std::is_compound<unsigned short>::value);
  static_assert (!std::is_compound<int>::value);
  static_assert (!std::is_compound<unsigned int>::value);
  static_assert (!std::is_compound<long>::value);
  static_assert (!std::is_compound<unsigned long>::value);
  static_assert (!std::is_compound<long long>::value);
  static_assert (!std::is_compound<unsigned long long>::value);
  static_assert (!std::is_compound<float>::value);
  static_assert (!std::is_compound<double>::value);
  static_assert (!std::is_compound<long double>::value);
  static_assert (!std::is_compound<decltype (nullptr)>::value);

  static_assert (std::is_compound<Instantiator>::value);
  static_assert (std::is_compound<const Instantiator>::value);
  static_assert (std::is_compound<volatile Instantiator>::value);
  static_assert (std::is_compound<const volatile Instantiator>::value);
};
template <std::size_t N> struct gsoc23::Instantiator<N, 0>
{
  static_assert (!std::is_compound<void>::value);
  static_assert (!std::is_compound<char>::value);
  static_assert (!std::is_compound<signed char>::value);
  static_assert (!std::is_compound<unsigned char>::value);
  static_assert (!std::is_compound<wchar_t>::value);
  static_assert (!std::is_compound<short>::value);
  static_assert (!std::is_compound<unsigned short>::value);
  static_assert (!std::is_compound<int>::value);
  static_assert (!std::is_compound<unsigned int>::value);
  static_assert (!std::is_compound<long>::value);
  static_assert (!std::is_compound<unsigned long>::value);
  static_assert (!std::is_compound<long long>::value);
  static_assert (!std::is_compound<unsigned long long>::value);
  static_assert (!std::is_compound<float>::value);
  static_assert (!std::is_compound<double>::value);
  static_assert (!std::is_compound<long double>::value);
  static_assert (!std::is_compound<decltype (nullptr)>::value);

  static_assert (std::is_compound<Instantiator>::value);
  static_assert (std::is_compound<const Instantiator>::value);
  static_assert (std::is_compound<volatile Instantiator>::value);
  static_assert (std::is_compound<const volatile Instantiator>::value);
};

int
main ()
{
  gsoc23::instantiate1000x256 ();
}
