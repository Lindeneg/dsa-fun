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

    std::cout << bst << '\n';

    Graph::BST bst2{bst};

    std::cout << bst2 << '\n';

    std::cout << "Min: " << bst.FindMin() << '\n';
    std::cout << "Max: " << bst.FindMax() << '\n';
    std::cout << "Height: " << bst.GetHeight() << '\n';
    std::cout << "Searching 19: " << bst.Search(19) << '\n';
    std::cout << "Searching 42: " << bst.Search(42) << '\n';

    std::cout << "Breadth First Search\n";
    bst.BreadthFirstSearch();

    std::cout << "DFS Pre Order\n";
    bst.DFSPreOrder();
    std::cout << "\nDFS In Order\n";
    bst.DFSInOrder();
    std::cout << "\nDFS Post Order\n";
    bst.DFSPostOrder();

    std::cout << "\nDeleting 12 " << '\n' << bst;
    bst.RemoveNode(12);
    std::cout << "After: " << '\n' << bst;

    std::cout << '\n';
}
}  // namespace Demo
