#ifndef LIST_STACKDEMO_H_
#define LIST_STACKDEMO_H_

#include <iostream>

#include "Stack.h"

namespace list {
inline void RunStack() {
    Stack s;

    std::cout << s;

    s.Push(2);
    s.Push(5);
    s.Push(1);
    s.Push(9);
    s.Push(14);
    s.Push(8);

    Stack ss = s;

    std::cout << s;
    std::cout << ss;

    std::cout << s.Pop() << s << '\n';
    std::cout << s.Pop() << s << '\n';
    std::cout << s.Pop() << s << '\n';

    std::cout << '\n';
}
}  // namespace list

#endif /* LIST_STACKDEMO_H_ */
