#pragma once

#include <ostream>

namespace List {
struct QueueNode {
    int data;
    QueueNode* next;
};

class Queue {
   private:
    QueueNode* mHead;
    QueueNode* mTail;

   public:
    Queue() : mHead(nullptr), mTail(nullptr) {}
    ~Queue();

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

    void Enqueue(int data);
    int Dequeue();
    int Front() const;

    inline bool IsEmpty() const { return this->mHead == nullptr; }
};
}  // namespace List
