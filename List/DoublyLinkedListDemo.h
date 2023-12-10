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
}
}  // namespace list
