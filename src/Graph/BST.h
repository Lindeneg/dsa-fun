#pragma once

#include <ostream>
#include <string>

namespace Graph {

enum Direction { Root = ' ', Left = 'l', Right = 'r' };

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};
/* Binary Search Tree (BST)
 *
 * Key of each internal node is greater than keys
 * in that node's left sub-stree and less than
 * the ones in the right sub-tree.
 *
 * Depth at node n: Number of edges from root node to n
 * Height of tree : Max depth where n is leaf node. */
class BST {
   private:
    BSTNode* mRoot;

    BSTNode* CreateNode(int data);
    BSTNode* Insert(BSTNode* root, int data);
    bool Search(BSTNode* root, int data) const;
    int GetHeight(BSTNode* root) const;
    void BreadthFirstSearch(const BSTNode* root) const;
    void DepthFirstSearch(const BSTNode* root) const;
    void From(const BSTNode* root);
    void Clear(BSTNode* root);
    void Print(std::ostream& os, BSTNode* parent, BSTNode* root, int depth,
               Direction d) const;

   public:
    BST() : mRoot(nullptr) {}
    BST(const BST& other);
    BST(BST&& other) noexcept;
    ~BST();

    BST& operator=(const BST& other);
    BST& operator=(BST&& other) noexcept;

    inline friend std::ostream& operator<<(std::ostream& os, const BST& other) {
        other.Print(os, nullptr, other.mRoot, 0, Root);
        return os;
    }
    inline void Insert(int data) {
        auto node = this->Insert(this->mRoot, data);
        if (this->mRoot == nullptr) {
            this->mRoot = node;
        }
    }
    inline bool Search(int data) const {
        return this->Search(this->mRoot, data);
    }
    inline void Clear() {
        this->Clear(this->mRoot);
        if (this->mRoot != nullptr) {
            delete this->mRoot;
        }
        this->mRoot = nullptr;
    }
    inline int GetHeight() const { return this->GetHeight(this->mRoot); }
    /* Min value will always reside as a leaf node in left-subtree. */
    int FindMin() const;
    /* Max value will always reside as a leaf node in right-subtree. */
    int FindMax() const;
    /* Visits all nodes at a given depth before going on to next depth */
    void BreadthFirstSearch() const { this->BreadthFirstSearch(this->mRoot); }
    /* Vists all nodes to maximum depth before moving on to next node */
    void DepthFirstSearch() const { this->DepthFirstSearch(this->mRoot); }
};
}  // namespace Graph
