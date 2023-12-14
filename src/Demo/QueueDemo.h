#pragma once

#include <iostream>

#include "../List/Queue.h"

namespace Demo {
inline void runQueue() {
    std::cout << "Queue Playground!\n";

    List::Queue<int> q{};

    std::cout << q;

    std::cout << "Appending stuff to q\n";
    q.Enqueue(2);
    q.Enqueue(13);
    q.Enqueue(9);
    q.Enqueue(5);

    List::Queue<int> qq = q;
    std::cout << "New queue qq: " << qq << '\n';
    std::cout << "Front q: " << qq.Front() << '\n';
    std::cout << "Dequeue q: " << qq.Dequeue() << '\n';
    std::cout << q << '\n';
}
}  // namespace Demo
