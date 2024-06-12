#include <iostream>
#include <vector>

// Found this hack somewhere in a comment chain on reddit I think, don't remember where.

class V : public std::vector<V>
{};

int main()
{
    V v;
    v.emplace_back();

    // Keep the address to the single element for later use.
    auto data = v.data();

    // 'v' gets the memory that 'front' has - nullptr.
    // 'front' gets the memory that 'v' has - a pointer to 'front'.
    // The original 'v' has now leaked.
    v.swap(v.front());

    // We can get a reference to the leaked object.
    auto const& element = *data;
    std::cerr << element.data() << std::endl
              << &element << std::endl;

    // Copying creates infinite recursion -> crash.
    V derp{element};

    return 0;
}
