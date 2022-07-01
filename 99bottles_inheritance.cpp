#include <array>
#include <iostream>

int bottles{0};
constexpr int max_bottles{99};

struct Base
{
  virtual void next() const = 0;
};

std::array<Base*, 2> actions;

struct Continue : public Base
{
  virtual void next() const
  {
    std::cerr << (max_bottles - bottles) << std::endl;
    auto const action_ix = bottles++ / max_bottles;
    actions[action_ix]->next();
  }
};

struct Stop : public Base
{
  virtual void next() const {}
};

int main()
{
  actions[0U] = new Continue();
  actions[1U] = new Stop();
  actions[0U]->next();

  return 0;
}
