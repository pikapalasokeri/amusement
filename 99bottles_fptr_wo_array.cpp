#include <iostream>

void stop(int const)
{
}

void recurse(int const num_bottles)
{
  std::cout << num_bottles << std::endl;

  void (*stop_ptr)(int) = &stop;
  void (*recurse_ptr)(int) = &recurse;
  char const* stop_char_ptr = reinterpret_cast<char const*>(stop_ptr);
  char const* recurse_char_ptr = reinterpret_cast<char const*>(recurse_ptr);

  int const condition{num_bottles == 0};
  char const* call_char_ptr = recurse_char_ptr + (stop_char_ptr - recurse_char_ptr) * condition;

  void (*call_ptr)(int) = reinterpret_cast<void(*)(int)>(call_char_ptr);

  call_ptr(num_bottles - 1);
}

int main()
{
  recurse(99);
  return 0;
}
