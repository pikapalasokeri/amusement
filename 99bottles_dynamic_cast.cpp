#include <iostream>

constexpr int max_bottles{99};
int bottles{max_bottles};

struct Base
{
    virtual ~Base() = default;
};

struct Continue : public Base
{
};

struct Stop : public Base
{
};

int main()
{
    Base* actions[2U];
    actions[0U] = new Continue();
    actions[1U] = new Stop();

    try
    {
    iterate:
        std::cerr << bottles-- << std::endl;
        int const action_idx{bottles == 0};
        Base const& action{*actions[action_idx]};
        auto const& tmp = dynamic_cast<Continue const&>(action);
        goto iterate;
    }
    catch(...)
    {
    }
    delete actions[0U];
    delete actions[1U];

    return 0;
}
