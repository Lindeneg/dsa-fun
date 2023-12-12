#include "Stack.h"

#include <cassert>
#include <iostream>

List::Stack::Stack(const Stack& other) : mTop(nullptr) {
    std::cout << "Copy constructor called!\n";

    this->From(other);
}

List::Stack::Stack(Stack&& other) noexcept : mTop(nullptr) {
    std::cout << "Move constructor called!\n";

    this->From(other);
    other.Clear();
}

List::Stack::~Stack() {
    std::cout << "Destructor called!\n";

    this->Clear();
}

List::Stack& List::Stack::operator=(const Stack& other) {
    std::cout << "Copy Assignment Operator called\n";

    if (this == &other) {
        return *this;
    }

    this->Clear();
    this->From(other);

    return *this;
}

List::Stack& List::Stack::operator=(Stack&& other) noexcept {
    std::cout << "Move Assignment Operator called\n";

    if (this == &other) {
        return *this;
    }

    this->Clear();
    this->From(other);
    other.Clear();

    return *this;
}

List::StackNode* List::Stack::CreateNode(int data) {
    auto newNode = new StackNode();
    newNode->data = data;
    newNode->next = nullptr;

    return newNode;
}

void List::Stack::Prepend(int data) {
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

void List::Stack::From(const Stack& other) {
    if (this->mTop != nullptr) {
        this->Clear();
    }

    auto current = other.mTop;
    while (current != nullptr) {
        this->Prepend(current->data);
        current = current->next;
    }
}

void List::Stack::Reverse() {
    std::cout << "Reversing stack\n";
    if (this->mTop == nullptr || this->mTop->next == nullptr) {
        return;
    }

    auto current = this->mTop;
    StackNode* prev = nullptr;
    while (current->next != nullptr) {
        auto next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    current->next = prev;
    this->mTop = current;
}

void List::Stack::Clear() {
    if (this->mTop == nullptr) {
        return;
    }

    auto current = this->mTop;
    while (current != nullptr) {
        auto tmp = current;
        current = current->next;
        std::cout << "Freeing " << tmp->data << '\n';
        delete tmp;
    }
}

void List::Stack::Push(int data) {
    std::cout << "Pushing " << data << '\n';

    auto newNode = this->CreateNode(data);
    if (this->mTop == nullptr) {
        this->mTop = newNode;
        return;
    }

    auto oldTop = this->mTop;
    newNode->next = oldTop;
    this->mTop = newNode;
}

int List::Stack::Pop() {
    assert(this->mTop != nullptr && "cannot pop from empty stack");

    std::cout << "Popping top\n";

    auto oldTop = this->mTop;
    this->mTop = oldTop->next;

    int data = oldTop->data;

    delete oldTop;

    return data;
}

