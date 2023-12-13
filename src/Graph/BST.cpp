#include "BST.h"

#include <algorithm>
#include <cassert>
#include <iostream>

Graph::BST::~BST() {
    std::cout << "Destructor called!\n";

    this->Clear(this->mRoot);
    this->mRoot = nullptr;
}

void Graph::BST::Print(BSTNode* root, int offset) const {
    if (root == nullptr) {
        return;
    }

    offset += printInrement;

    this->Print(root->right, offset);

    for (int i = printInrement; i < offset; i++) {
        std::cout << ' ';
    }

    bool isRoot = offset == printInrement;
    if (isRoot) {
        std::cout << "(r) ";
    }

    std::cout << root->data << '\n';

    this->Print(root->left, offset);
}

int Graph::BST::GetHeight(BSTNode* root) const {
    if (root == nullptr) {
        return -1;
    }

    auto leftHeight = this->GetHeight(root->left);
    auto rightHeight = this->GetHeight(root->right);

    return std::max(leftHeight, rightHeight) + 1;
}

int Graph::BST::FindMin() const {
    assert(this->mRoot != nullptr && "cannot find min of empty tree");

    auto current = this->mRoot;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->data;
}

int Graph::BST::FindMax() const {
    assert(this->mRoot != nullptr && "cannot find max of empty tree");

    auto current = this->mRoot;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->data;
}

void Graph::BST::Clear(Graph::BSTNode* root) {
    if (root == nullptr) {
        return;
    }

    if (root->left != nullptr) {
        this->Clear(root->left);
    }

    if (root->right != nullptr) {
        this->Clear(root->right);
    }

    std::cout << "Freeing " << root->data << '\n';
    delete root;
}

Graph::BSTNode* Graph::BST::CreateNode(int data) {
    auto newNode = new BSTNode();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Graph::BSTNode* Graph::BST::Insert(BSTNode* root, int data) {
    if (root == nullptr) {
        auto newNode = this->CreateNode(data);
        return newNode;
    } else if (data < root->data) {
        root->left = this->Insert(root->left, data);
    } else {
        root->right = this->Insert(root->right, data);
    }
    return root;
}

bool Graph::BST::Search(BSTNode* root, int data) const {
    if (root == nullptr) {
        return false;
    } else if (root->data == data) {
        return true;
    } else if (data <= root->data) {
        return this->Search(root->left, data);
    }
    return this->Search(root->right, data);
}
