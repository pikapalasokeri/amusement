#include <iostream>

// Uses compiler extension "Labels as Values" a.k.a computed goto.
// See https://gcc.gnu.org/onlinedocs/gcc/Labels-as-Values.html#Labels-as-Values
// Also builds with clang 11.
int main()
{
  int bottles{99};

  constexpr void* labels[] =
    {
     &&next_bottle,
     &&done
    };

next_bottle:
  std::cout << bottles << std::endl;
  int const label_index{bottles == 0};
  --bottles;
  goto* labels[label_index];
done:
  return 0;
}
