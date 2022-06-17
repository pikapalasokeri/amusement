#include <array>
#include <functional>
#include <iostream>

using FuncsT = std::array<std::function<void(int, int)>, 2>;

int main()
{
  FuncsT functions;

  functions[0] = [&functions](int const max_bottles, int const num_bottles)
                 {
                   std::cout << num_bottles << std::endl;
                   int const function_idx = (max_bottles - num_bottles) / max_bottles;
                   functions[function_idx](max_bottles, num_bottles - 1);
                 };
  functions[1] = [](int const, int const){};

  functions[0](99, 99);

  return 0;
}
