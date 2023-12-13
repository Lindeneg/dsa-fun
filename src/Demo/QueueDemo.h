#pragma once

#include <iostream>

#include "../List/Queue.h"

namespace Demo {
inline void runQueue() {
    List::Queue q;

    std::cout << q;

    q.Enqueue(2);
    q.Enqueue(5);

    std::cout << q;
    std::cout << "Front: " << q.Front() << '\n';
    std::cout << "Dequeue: " << q.Dequeue() << '\n';
    std::cout << q << '\n';
}
}  // namespace Demo
