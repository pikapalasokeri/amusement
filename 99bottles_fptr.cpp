#include <iostream>

void (*fptrs[2])(int);

void recurse(int const num_bottles)
{
  std::cout << num_bottles << std::endl;

  int const idx{num_bottles == 0};
  fptrs[idx](num_bottles - 1);
}

void stop(int const)
{
}

int main()
{
  fptrs[0] = &recurse;
  fptrs[1] = &stop;
  recurse(99);
  return 0;
}
