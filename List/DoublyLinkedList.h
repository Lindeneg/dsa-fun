#pragma once

#include <ostream>

namespace list {
struct Node2 {
    int data;
    Node2* next;
    Node2* prev;
};

class DoublyLinkedList {
   private:
    Node2* mHead;
    int mSize;

    void Free(Node2* node);

   public:
    DoublyLinkedList() : mHead(nullptr), mSize(0) {}
    ~DoublyLinkedList();

    inline friend std::ostream& operator<<(std::ostream& out,
                                           const DoublyLinkedList& linkedList) {
        out << "(size " << linkedList.mSize << ") [";

        if (linkedList.mHead != nullptr) {
            auto current = linkedList.mHead;
            while (current->next != nullptr) {
                out << current->data << ',';
                current = current->next;
            }
            out << current->data;
        }

        out << "]\n";

        return out;
    }

    // Node2* GetNode(int index) const;
    void Append(int data);
    // void InsertAt(int data, int index);
    // void RemoveNode(int index);
    // void Reverse();
    void Clear();
};
}  // namespace list
