#pragma once

#include <iostream>

#include "../List/Stack.h"

namespace Demo {
inline void runStack() {
    List::Stack s;

    std::cout << s;

    s.Push(2);
    s.Push(5);
    s.Push(1);
    s.Push(9);
    s.Push(14);
    s.Push(8);

    std::cout << s;

    List::Stack ss = s;
    ss.Reverse();

    std::cout << s;
    std::cout << ss;

    std::cout << ss.Pop() << ss << '\n';
    std::cout << ss.Pop() << ss << '\n';
    std::cout << ss.Pop() << ss << '\n';

    std::cout << '\n';
}
}  // namespace Demo

