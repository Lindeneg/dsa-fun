#pragma once

#include <iostream>

namespace List {

template <typename T>
struct StackNode {
    T data;
    StackNode* next;
};

template <typename T>
class Stack {
   private:
    StackNode<T>* mTop;

    // seems useful when copying
    void Prepend(T data);
    StackNode<T>* CreateNode(T data);
    void From(const Stack& other);

   public:
    Stack() : mTop(nullptr) {}
    Stack(const Stack& other);
    Stack(Stack&& other) noexcept;
    ~Stack();

    Stack& operator=(const Stack& other);
    Stack& operator=(Stack&& other) noexcept;

    inline friend std::ostream& operator<<(std::ostream& os, const Stack& s) {
        if (s.mTop == nullptr) {
            os << "[]\n";
            return os;
        }

        os << "[\n";

        auto current = s.mTop;
        while (current != nullptr) {
            os << '\t' << current->data << ",\n";
            current = current->next;
        }

        os << "]\n";

        return os;
    }

    inline bool IsEmpty() const { return this->mTop == nullptr; }

    void Reverse();
    void Push(T data);
    void Clear();
    T Top() const;
    T Pop();
};
}  // namespace List

