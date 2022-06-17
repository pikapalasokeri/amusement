#include <iostream>

void bottom(int const, int const)
{
}

void print(int const max_num_bottles, int const num_bottles)
{
  std::cout << num_bottles << std::endl;

  void (*bottom_ptr)(int, int) = &bottom;
  void (*print_ptr)(int, int) = &print;
  char const* bottom_char_ptr = reinterpret_cast<char const*>(bottom_ptr);
  char const* print_char_ptr = reinterpret_cast<char const*>(print_ptr);

  int const condition = (max_num_bottles - num_bottles) / max_num_bottles;
  char const* call_char_ptr = print_char_ptr + (bottom_char_ptr - print_char_ptr) * condition;

  void (*call_ptr)(int, int) = reinterpret_cast<void(*)(int, int)>(call_char_ptr);

  call_ptr(max_num_bottles, num_bottles - 1);
}

int main()
{
  print(99, 99);
  return 0;
}
