#include <array>
#include <functional>
#include <iostream>

using FuncsT = std::array<std::function<void(int)>, 2>;

int main()
{
  FuncsT functions;

  functions[0] = [&functions](int const num_bottles)
                 {
                   std::cout << num_bottles << std::endl;
                   int const function_idx{num_bottles == 0};
                   functions[function_idx](num_bottles - 1);
                 };
  functions[1] = [](int const){};

  functions[0](99);

  return 0;
}
