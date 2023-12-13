#pragma once

#include <string>

namespace Graph {

constexpr int printInrement{10};
struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

class BST {
   private:
    BSTNode* mRoot;

    BSTNode* CreateNode(int data);

    BSTNode* Insert(BSTNode* root, int data);
    bool Search(BSTNode* root, int data) const;
    void Print(BSTNode* root, int offset) const;
    int GetHeight(BSTNode* root) const;

   public:
    BST() : mRoot(nullptr) {}
    ~BST();

    inline void Insert(int data) {
        auto node = this->Insert(this->mRoot, data);
        if (this->mRoot == nullptr) {
            this->mRoot = node;
        }
    }

    inline bool Search(int data) const {
        return this->Search(this->mRoot, data);
    }

    inline void Print() const { this->Print(this->mRoot, 0); }
    inline int GetHeight() const { return this->GetHeight(this->mRoot); }

    int FindMin() const;
    int FindMax() const;
    void Clear(BSTNode* root);
};
}  // namespace Graph
