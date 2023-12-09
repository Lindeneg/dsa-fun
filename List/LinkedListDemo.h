#include <iostream>

#include "LinkedList.h"

namespace list {
inline void RunLinkedList() {
    const auto linkedList{new LinkedList<int>()};

    linkedList->Append(2);
    linkedList->Append(4);
    linkedList->Append(5);
    linkedList->Append(3);
    linkedList->Append(7);

    std::cout << "List1\n";
    linkedList->Print();

    std::cout << "\nCall Copy Constructor\n";
    const auto linkedList2{new LinkedList<int>(*linkedList)};

    std::cout << "List1\n";
    linkedList->Print();
    std::cout << "List2\n";
    linkedList2->Print();

    std::cout << "\nCall List1 Destructor\n";
    delete linkedList;
    linkedList->Print();

    std::cout << "\nInsertAt List2\n";
    linkedList2->InsertAt(10, 2);
    linkedList2->Print();

    std::cout << "\nInsertAt List2\n";
    linkedList2->InsertAt(42, 0);
    linkedList2->Print();

    std::cout << "\nGetNode List2 index 4\n";
    std::cout << linkedList2->GetNode(4) << '\n';

    std::cout << "\nRemoveNode List2 index 1\n";
    linkedList2->RemoveNode(1);
    linkedList2->Print();

    std::cout << "\nRemoveNode List2 index 0\n";
    linkedList2->RemoveNode(0);
    linkedList2->Print();

    std::cout << "\nReverse List2\n";
    linkedList2->Reverse();
    linkedList2->Print();

    std::cout << "\nCall List2 Destructor\n";
    delete linkedList2;
    linkedList2->Print();
}
}  // namespace list
