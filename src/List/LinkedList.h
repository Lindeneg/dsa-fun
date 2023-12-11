#ifndef LIST_LINKEDLIST_H_
#define LIST_LINKEDLIST_H_

#include <ostream>

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

    inline friend std::ostream& operator<<(std::ostream& out,
                                           const LinkedList<T>& linkedList) {
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

    inline int GetSize() const { return this->mSize; }

    Node<T>* GetNode(int index) const;
    bool RemoveNode(int index);
    void Append(T data);
    void InsertAt(T data, int index);
    void Reverse();
    void Clear();
};
}  // namespace list

#endif /* LIST_LINKEDLIST_H_ */
