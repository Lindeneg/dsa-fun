#ifndef STACK_STACK_H_
#define STACK_STACK_H_

#include <iostream>

namespace list {

struct StackNode {
    int data;
    StackNode* next;
};

class Stack {
   private:
    StackNode* mTop;

    // seems useful when copying
    void Prepend(int data);
    StackNode* CreateNode(int data);
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
    void Push(int data);
    void Clear();
    int Pop();
};
}  // namespace list

#endif /* STACK_STACK_H_ */
