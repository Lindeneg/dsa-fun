#include "BST.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <ostream>

#include "../List/Queue.h"

Graph::BST::BST(const BST& other) : mRoot(nullptr) {
    std::cout << "BST Copy Constructor called!\n";

    this->Clear(this->mRoot);
    this->From(other.mRoot);
}

Graph::BST::BST(BST&& other) noexcept : mRoot(nullptr) {
    std::cout << "BST Move Constructor called!\n";
    this->From(other.mRoot);
    other.Clear();
}

Graph::BST::~BST() {
    std::cout << "BST Destructor called!\n";

    this->Clear(this->mRoot);
    this->mRoot = nullptr;
}

Graph::BST& Graph::BST::operator=(const BST& other) {
    std::cout << "BST Copy Assignment Operator called\n";

    if (this == &other) {
        return *this;
    }

    this->Clear();
    this->From(other.mRoot);

    return *this;
}

Graph::BST& Graph::BST::operator=(BST&& other) noexcept {
    std::cout << "BST Move Assignment Operator called\n";

    if (this == &other) {
        return *this;
    }

    this->Clear();
    this->From(other.mRoot);
    other.Clear();

    return *this;
}

void Graph::BST::From(const BSTNode* other) {
    if (other == nullptr) {
        return;
    }

    this->Insert(other->data);
    this->From(other->left);
    this->From(other->right);
}

void Graph::BST::Print(std::ostream& os, BSTNode* parent, BSTNode* root,
                       int depth, Direction d) const {
    if (root == nullptr) {
        return;
    }

    os << "data: " << root->data << static_cast<char>(d);
    if (parent != nullptr) {
        os << " parent: " << parent->data;
    }
    os << " depth: " << depth << '\n';

    ++depth;
    this->Print(os, root, root->left, depth, Left);
    this->Print(os, root, root->right, depth, Right);
}

int Graph::BST::GetHeight(BSTNode* root) const {
    if (root == nullptr) {
        return -1;
    }

    auto leftHeight = this->GetHeight(root->left);
    auto rightHeight = this->GetHeight(root->right);

    // +1 to account for root node
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

/* This BFS implementation uses a Queue to keep track
 * of parent nodes while traversing their children */
void Graph::BST::BreadthFirstSearch(BSTNode* root) const {
    if (root == nullptr) {
        return;
    }

    List::Queue<BSTNode*> q{};
    q.Enqueue(root);

    while (!q.IsEmpty()) {
        auto current = q.Front();

        if (current->left != nullptr) {
            q.Enqueue(current->left);
        }

        if (current->right != nullptr) {
            q.Enqueue(current->right);
        }
        std::cout << "->" << q.Dequeue()->data;
    }

    std::cout << '\n';
}
