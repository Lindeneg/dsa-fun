#include "Stack.h"

#include <cassert>
#include <iostream>

template <typename T>
List::Stack<T>::Stack(const Stack& other) : mTop(nullptr) {
    std::cout << "Stack Copy constructor called!\n";

    this->From(other);
}

template <typename T>
List::Stack<T>::Stack(Stack&& other) noexcept : mTop(nullptr) {
    std::cout << "Stack Move constructor called!\n";

    this->From(other);
    other.Clear();
}

template <typename T>
List::Stack<T>::~Stack<T>() {
    std::cout << "Stack Destructor called!\n";

    this->Clear();
}

template <typename T>
List::Stack<T>& List::Stack<T>::operator=(const Stack& other) {
    std::cout << "Stack Copy Assignment Operator called\n";

    if (this == &other) {
        return *this;
    }

    this->Clear();
    this->From(other);

    return *this;
}

template <typename T>
List::Stack<T>& List::Stack<T>::operator=(Stack&& other) noexcept {
    std::cout << "Stack Move Assignment Operator called\n";

    if (this == &other) {
        return *this;
    }

    this->Clear();
    this->From(other);
    other.Clear();

    return *this;
}

template <typename T>
List::StackNode<T>* List::Stack<T>::CreateNode(T data) {
    auto newNode = new StackNode<T>();
    newNode->data = data;
    newNode->next = nullptr;

    return newNode;
}

template <typename T>
void List::Stack<T>::Prepend(T data) {
    auto newNode = this->CreateNode(data);

    if (this->mTop == nullptr) {
        this->mTop = newNode;
        return;
    }

    auto current = this->mTop;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

template <typename T>
void List::Stack<T>::From(const Stack& other) {
    if (this->mTop != nullptr) {
        this->Clear();
    }

    auto current = other.mTop;
    while (current != nullptr) {
        this->Prepend(current->data);
        current = current->next;
    }
}

template <typename T>
void List::Stack<T>::Reverse() {
    if (this->mTop == nullptr || this->mTop->next == nullptr) {
        return;
    }

    auto current = this->mTop;
    StackNode<T>* prev = nullptr;
    while (current->next != nullptr) {
        auto next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    current->next = prev;
    this->mTop = current;
}

template <typename T>
void List::Stack<T>::Clear() {
    if (this->mTop == nullptr) {
        return;
    }

    auto current = this->mTop;
    while (current != nullptr) {
        auto tmp = current;
        current = current->next;
        delete tmp;
    }
}

template <typename T>
void List::Stack<T>::Push(T data) {
    auto newNode = this->CreateNode(data);
    if (this->mTop == nullptr) {
        this->mTop = newNode;
        return;
    }

    auto oldTop = this->mTop;
    newNode->next = oldTop;
    this->mTop = newNode;
}

template <typename T>
T List::Stack<T>::Pop() {
    assert(this->mTop != nullptr && "cannot pop from empty stack");

    auto oldTop = this->mTop;
    this->mTop = oldTop->next;

    T data = oldTop->data;

    delete oldTop;

    return data;
}

template <typename T>
T List::Stack<T>::Top() const {
    assert(this->mTop != nullptr && "cannot top from empty stack");
    return this->mTop->data;
}

template class List::Stack<int>;
template class List::Stack<char>;
