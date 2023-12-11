#ifndef LIST_DOUBLYLINKEDLIST_H_
#define LIST_DOUBLYLINKEDLIST_H_

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

    void From(const DoublyLinkedList& other);
    void Free(Node2* node);

   public:
    DoublyLinkedList() : mHead(nullptr), mSize(0) {}
    ~DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& other);
    DoublyLinkedList(DoublyLinkedList&& other) noexcept;

    DoublyLinkedList& operator=(const DoublyLinkedList& other);
    DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept;

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

    int GetNode(int index) const;
    void Append(int data);
    void InsertAt(int data, int index);
    void RemoveNode(int index);
    void Reverse();
    void Clear();
};
}  // namespace list

#endif /* LIST_DOUBLYLINKEDLIST_H_ */
