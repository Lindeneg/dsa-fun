#include <iostream>
#include <vector>

#include "LinkedList.h"

namespace list {
inline void RunLinkedList() {
    LinkedList<int> list1{};

    list1.Append(2);
    list1.Append(4);
    list1.Append(5);
    list1.Append(3);
    list1.Append(7);

    std::cout << "List1: ";
    list1.Print();

    std::cout << "\nCoping List1 into List2\n";
    LinkedList<int> list2{list1};

    std::cout << "\nAdding more to List2\n";
    list2.InsertAt(42, 2);
    list2.InsertAt(8, 4);

    std::cout << "List1: ";
    list1.Print();
    std::cout << "List2: ";
    list2.Print();

    std::cout << "\nCreate empty List3:\n";
    LinkedList<int> list3{};

    std::cout << "List3: ";
    list3.Print();

    std::cout << "\nCopy-assigning List1 to List3\n";
    list3 = list1;

    std::cout << "List1: ";
    list1.Print();
    std::cout << "List3: ";
    list3.Print();

    std::cout << "\nRemove index 1 and 3 from List3\n";
    list3.RemoveNode(1);
    list3.RemoveNode(3);

    std::cout << "List3: ";
    list3.Print();

    std::cout << "\nGetNode List1 ";
    list1.Print();
    std::cout << "n2: " << list1.GetNode(2) << ", n0: " << list1.GetNode(0)
              << ", n4: " << list1.GetNode(4) << '\n';

    std::cout << "\nReverse List2\nBefore: ";
    list2.Print();
    list2.Reverse();
    std::cout << "After:  ";
    list2.Print();

    std::cout << "\nTesting move constructor\n";
    std::vector<LinkedList<double>> vec;
    vec.push_back(LinkedList<double>{});

    std::cout << "\nTesting move assignment operator\n";
    LinkedList<int> test{};
    test = std::move(list3);

    std::cout << '\n';
}
}  // namespace list
