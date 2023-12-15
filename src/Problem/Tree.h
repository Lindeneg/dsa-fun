#pragma once

#include <climits>
#include <iostream>

#include "../Graph/BST.h"

static inline Graph::BSTNode* CreateNode(int data) {
    auto node = new Graph::BSTNode();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

static inline Graph::BSTNode* CreateNonBST() {
    const auto root = CreateNode(10);
    const auto n1 = CreateNode(2);
    const auto n2 = CreateNode(6);

    n1->left = n2;
    root->right = n1;

    return root;
}

static inline void DeleteNonBST(Graph::BSTNode* root) {
    delete root->right->left;
    delete root->right;
    delete root;
}
static inline bool IsBSTUtil(Graph::BSTNode* root, int min, int max) {
    if (root == nullptr) {
        return true;
    } else if (root->data < min || root->data > max) {
        return false;
    }
    return IsBSTUtil(root->left, min, root->data) &&
           IsBSTUtil(root->right, root->data, max);
};
namespace Problem {

inline void IsBST() {
    Graph::BST bst{};
    bst.Insert(10);
    bst.Insert(2);
    bst.Insert(6);
    auto nonBSTRoot{CreateNonBST()};

    std::cout << "BST Tree is BST? "
              << IsBSTUtil(bst.GetRoot(), INT_MIN, INT_MAX) << '\n';

    std::cout << "Non-BST Tree is BST? "
              << IsBSTUtil(nonBSTRoot, INT_MIN, INT_MAX) << '\n';

    DeleteNonBST(nonBSTRoot);
}
}  // namespace Problem

