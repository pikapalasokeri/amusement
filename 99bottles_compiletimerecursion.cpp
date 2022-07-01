#include <iostream>

template <int bottles>
void foo()
{
  std::cout << bottles << std::endl;
  foo<bottles-1>();
}

template <>
void foo<0>()
{
  std::cout << 0 << std::endl;
}

int main()
{
  constexpr int max_bottles{99};
  foo<max_bottles>();
  return 0;
}
