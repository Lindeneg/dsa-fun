#pragma once

#include <iostream>

#include "DoublyLinkedList.h"

namespace list {
inline void RunDoublyLinkedList() {
    DoublyLinkedList ll;
    std::cout << "List1: " << ll;

    ll.Append(9);
    ll.Append(4);
    ll.Append(6);
    ll.Append(3);
    ll.Append(2);

    std::cout << "List1: " << ll;

    ll.InsertAt(42, 0);
    std::cout << ll;

    ll.InsertAt(99, 5);
    std::cout << ll;

    ll.InsertAt(50, 3);
    std::cout << ll;

    ll.Reverse();
    std::cout << ll;

    ll.RemoveNode(0);
    std::cout << ll;

    ll.RemoveNode(6);
    std::cout << ll;

    ll.RemoveNode(3);
    std::cout << ll;

    ll.GetNode(4);
    ll.GetNode(2);
    ll.GetNode(0);

    std::cout << '\n';
}
}  // namespace list
