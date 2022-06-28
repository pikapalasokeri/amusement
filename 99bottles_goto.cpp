#include <iostream>

// Uses compiler extension "Labels as Values" a.k.a computed goto.
// See https://gcc.gnu.org/onlinedocs/gcc/Labels-as-Values.html#Labels-as-Values
// Also builds with clang 11.
int main()
{
  constexpr int total_bottles{99};
  int bottle_count{0};

  constexpr void* labels[] =
    {
     &&next_bottle,
     &&done
    };

next_bottle:
  std::cout << (total_bottles - bottle_count) << std::endl;
  int label_index = bottle_count / total_bottles;
  ++bottle_count;
  goto* labels[label_index];
done:
  return 0;
}
