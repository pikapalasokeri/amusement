#include <iostream>

int main()
{
  int beers{99};
  try
  {
  iterate:
    std::cout << beers << std::endl;

    int* maybe_throw{new int[-(beers == 0)]};
    delete[] maybe_throw;

    --beers;
    goto iterate;
  }
  catch(...)
  {
    // Let's just catch everything and be done with it.
  }

  return 0;
}
