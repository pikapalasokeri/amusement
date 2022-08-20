#include <array>
#include <iostream>

struct Base
{
  virtual void next(int const) const = 0;
};

std::array<Base*, 2> actions;

struct Continue : public Base
{
  virtual void next(int const bottles) const
  {
    std::cout << bottles << std::endl;
    int idx{bottles == 0};
    actions[idx]->next(bottles - 1);
  }
};

struct Stop : public Base
{
  virtual void next(int const) const {}
};

int main()
{
  actions[0U] = new Continue();
  actions[1U] = new Stop();
  actions[0U]->next(99);

  return 0;
}
