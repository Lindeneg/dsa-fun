#pragma once

#include <iostream>

#include "../Graph/BST.h"

namespace Demo {
inline void runBST() {
    Graph::BST bst;

    bst.Insert(3);
    bst.Insert(19);
    bst.Insert(27);
    bst.Insert(2);
    bst.Insert(17);
    bst.Insert(11);

    bst.Print();

    std::cout << "Min: " << bst.FindMin() << '\n';
    std::cout << "Max: " << bst.FindMax() << '\n';
    std::cout << "Height: " << bst.GetHeight() << '\n';
    std::cout << "Searching 19: " << bst.Search(19) << '\n';
    std::cout << "Searching 4: " << bst.Search(4) << '\n';
}
}  // namespace Demo
