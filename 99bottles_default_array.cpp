#include <iostream>

int num_beers = 99;

struct Beer
{
  Beer()
  {
    std::cout << num_beers-- << std::endl;
  }
};

int main()
{
  Beer beers[100];

  return 0;
}
