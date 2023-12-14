#pragma once

#include <ostream>

namespace List {

template <typename T>
struct QueueNode {
    T data;
    QueueNode* next;
};

template <typename T>
class Queue {
   private:
    QueueNode<T>* mHead;
    QueueNode<T>* mTail;

    void From(const Queue& other);

   public:
    Queue() : mHead(nullptr), mTail(nullptr) {}
    Queue(const Queue& other);
    Queue(Queue&& other) noexcept;
    ~Queue();

    Queue& operator=(const Queue& other);
    Queue& operator=(Queue&& other) noexcept;

    inline friend std::ostream& operator<<(std::ostream& out, const Queue& q) {
        out << "[";

        if (q.mHead != nullptr) {
            auto current = q.mHead;
            while (current->next != nullptr) {
                out << current->data << ',';
                current = current->next;
            }
            out << current->data;
        }

        out << "]\n";

        return out;
    }
    inline bool IsEmpty() const { return this->mHead == nullptr; }

    void Clear();
    void Enqueue(T data);
    T Dequeue();
    T Front() const;
};
}  // namespace List
