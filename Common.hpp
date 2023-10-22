#pragma once

#include <type_traits>

namespace gsoc23
{

// Forward Declaration of Instantiator
template <std::size_t N, std::size_t Count = 256> struct Instantiator;

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

} // namespace gsoc23
