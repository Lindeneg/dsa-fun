#pragma once

#include <iostream>

#include "../List/Stack.h"

namespace Demo {
inline void runStack() {
    std::cout << "Stack Playground!\n";

    List::Stack<int> s{};

    std::cout << s;

    std::cout << "Pushing data\n";
    s.Push(2);
    s.Push(5);
    s.Push(1);
    s.Push(9);
    s.Push(14);
    s.Push(8);

    std::cout << s;

    std::cout << "Reversing stack\n";
    List::Stack<int> ss = s;
    ss.Reverse();

    std::cout << s;
    std::cout << ss;

    std::cout << "Popping top\n";
    std::cout << ss.Pop() << ss << '\n';
    std::cout << "Popping top\n";
    std::cout << ss.Pop() << ss << '\n';
    std::cout << "Popping top\n";
    std::cout << ss.Pop() << ss << '\n';

    std::cout << '\n';
}
}  // namespace Demo

