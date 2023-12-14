#include "Queue.h"

#include <cassert>
#include <iostream>

#include "../Graph/BST.h"

template <typename T>
List::Queue<T>::Queue(const Queue& other) : mHead(nullptr), mTail(nullptr) {
    std::cout << "Queue Copy Constructor called!\n";

    this->From(other);
}

template <typename T>
List::Queue<T>::Queue(Queue&& other) noexcept : mHead(nullptr), mTail(nullptr) {
    std::cout << "Queue Move Constructor called!\n";

    this->From(other);
    other.Clear();
}

template <typename T>
List::Queue<T>::~Queue<T>() {
    std::cout << "Queue Destructor called!\n";
    this->Clear();
}

template <typename T>
List::Queue<T>& List::Queue<T>::operator=(const Queue& other) {
    std::cout << "Queue Copy assignment operator called!\n";

    if (this == &other) {
        return *this;
    }

    this->From(other);

    return *this;
}

template <typename T>
List::Queue<T>& List::Queue<T>::operator=(Queue&& other) noexcept {
    std::cout << "Queue Move assignment operator called!\n";

    if (this == &other) {
        return *this;
    }

    this->From(other);
    other.Clear();

    return *this;
}

template <typename T>
void List::Queue<T>::Clear() {
    if (this->mHead != nullptr) {
        auto current = this->mHead;
        while (current != nullptr) {
            auto tmp = current;
            current = current->next;
            std::cout << "Queue Freeing " << tmp->data << '\n';
            delete tmp;
        }
    }
    this->mHead = nullptr;
    this->mTail = nullptr;
}

template <typename T>
void List::Queue<T>::From(const Queue& other) {
    this->Clear();

    auto current = other.mHead;
    while (current != nullptr) {
        this->Enqueue(current->data);
        current = current->next;
    }
}

template <typename T>
void List::Queue<T>::Enqueue(T data) {
    auto newNode = new QueueNode<T>();
    newNode->data = data;
    newNode->next = nullptr;

    if (this->mHead == nullptr) {
        this->mHead = newNode;
        return;
    }

    if (this->mTail == nullptr) {
        this->mHead->next = newNode;
        this->mTail = newNode;
        return;
    }

    auto oldTail = this->mTail;
    this->mTail = newNode;
    oldTail->next = newNode;
}

template <typename T>
T List::Queue<T>::Dequeue() {
    auto oldHead = this->mHead;
    this->mHead = oldHead->next;

    T data = oldHead->data;
    delete oldHead;
    return data;
}

template <typename T>
T List::Queue<T>::Front() const {
    assert(this->mHead != nullptr && "cannot get front from empty queue");

    return this->mHead->data;
}

template class List::Queue<int>;
template class List::Queue<const Graph::BSTNode*>;
