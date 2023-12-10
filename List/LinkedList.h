#pragma once

#include <iostream>

namespace list {
template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class LinkedList {
   private:
    int mSize;
    Node<T>* mHead;

    void From(const LinkedList& linkedList);
    void Free(Node<T>* node);

   public:
    LinkedList() : mSize(0), mHead(nullptr) {}
    ~LinkedList();
    // copy constructor
    LinkedList(const LinkedList& other);
    // move constructor
    LinkedList(LinkedList&& other) noexcept;

    // copy assignment operator
    LinkedList& operator=(const LinkedList& other);
    // move assignment operator
    LinkedList& operator=(LinkedList&& other) noexcept;

    inline int GetSize() const { return this->mSize; }

    T GetNode(int index) const;
    bool RemoveNode(int index);
    void Append(T data);
    void InsertAt(T data, int index);
    void Reverse();
    void Clear();
    void Print() const;
};
}  // namespace list

