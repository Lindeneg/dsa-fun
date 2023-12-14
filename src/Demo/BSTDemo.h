#pragma once

#include <iostream>

#include "../Graph/BST.h"

namespace Demo {
inline void runBST() {
    std::cout << "BST Playground!\n";

    Graph::BST bst{};

    std::cout << "Inserting elements\n";
    bst.Insert(3);
    bst.Insert(19);
    bst.Insert(27);
    bst.Insert(1);
    bst.Insert(6);
    bst.Insert(12);
    bst.Insert(2);
    bst.Insert(17);
    bst.Insert(4);
    bst.Insert(5);
    bst.Insert(13);
    bst.Insert(11);
    // bst.Print();

    std::cout << "Level Order Traversel" << '\n';
    bst.LevelOrderTraversel();

    std::cout << "Min: " << bst.FindMin() << '\n';
    std::cout << "Max: " << bst.FindMax() << '\n';
    std::cout << "Height: " << bst.GetHeight() << '\n';
    std::cout << "Searching 19: " << bst.Search(19) << '\n';
    std::cout << "Searching 42: " << bst.Search(42) << '\n';

    std::cout << '\n';
}
}  // namespace Demo
