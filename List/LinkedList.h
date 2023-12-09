#pragma once

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
    LinkedList();
    LinkedList(const LinkedList& linkedList);
    ~LinkedList();

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

