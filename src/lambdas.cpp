#include <iostream>
#include <string>

int main()

{
    int x = 4;
    const int y = 7;

    // auto lamb1 = [x]() { x++; }; doesnt change the value as not referenced
    auto lamb2 = [&x]() { x++; };
    auto lamb5 = [=]() mutable { x++; };
    // auto lamb3 = [&y]() { y++; }; y is const so doesnt change
    auto lamb4 = [y]() {};

    auto gen_lam = [](auto T1, auto T2) { return T1 + T2; };

    auto ans1 = gen_lam(3, 4);
    auto ans2 = gen_lam('c', 'd');
    // auto ans3 = gen_lam("Hello", "World");

    using namespace std::string_literals;
    // auto ans3 = gen_lam("Hello"s, "World"s);
}