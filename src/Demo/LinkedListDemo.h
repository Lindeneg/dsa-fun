#pragma once

#include <iostream>
#include <vector>

#include "../List/LinkedList.h"
#define STACK_STACK_H_

namespace Demo {
inline void runLinkedList() {
    List::LinkedList<int> list1{};

    list1.Append(2);
    list1.Append(4);
    list1.Append(5);
    list1.Append(3);
    list1.Append(7);

    std::cout << "List1: " << list1;

    std::cout << "\nCoping List1 into List2\n";
    List::LinkedList<int> list2{list1};

    std::cout << "List2: " << list2;

    std::cout << "\nAdding more to List2\n";
    list2.InsertAt(42, 2);
    std::cout << "List2: " << list2;
    list2.InsertAt(8, 4);

    std::cout << "List2: " << list2;

    std::cout << "\nCreate empty List3:\n";
    List::LinkedList<int> list3{};

    std::cout << "List3: " << list3;

    std::cout << "\nCopy-assigning List1 to List3\n";
    list3 = list1;

    std::cout << "List1: " << list1 << "List3: " << list3;

    std::cout << "\nRemove value at index 1 from List3\n";
    list3.RemoveNode(1);
    std::cout << "List3: " << list3;
    std::cout << "Remove value at index 3 from List3\n";
    list3.RemoveNode(3);
    std::cout << "List3: " << list3;

    std::cout << "\nGetNode List1 " << list1;
    std::cout << "n2: " << list1.GetNode(2)->data
              << ", n0: " << list1.GetNode(0)->data
              << ", n4: " << list1.GetNode(4)->data << '\n';

    std::cout << "\nReverse List2\nBefore: " << list2;
    list2.Reverse();
    std::cout << "After:  " << list2;

    std::cout << "\nTesting move constructor\n";
    std::vector<List::LinkedList<double>> vec;
    vec.push_back(List::LinkedList<double>{});

    std::cout << "\nTesting move assignment operator\n";
    List::LinkedList<int> test{};
    test = std::move(list3);

    std::cout << '\n';
}
}  // namespace Demo

