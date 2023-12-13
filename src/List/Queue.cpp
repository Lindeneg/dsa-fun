#include "Queue.h"

#include <cassert>
#include <iostream>

List::Queue::~Queue() {
    std::cout << "Destructor called!\n";
    if (this->mHead != nullptr) {
        auto current = this->mHead;
        while (current != nullptr) {
            auto tmp = current;
            current = current->next;
            std::cout << "Freeing " << tmp->data << '\n';
            delete tmp;
        }
    }
}

void List::Queue::Enqueue(int data) {
    std::cout << "Enqueing " << data << '\n';
    auto newNode = new QueueNode();
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

int List::Queue::Dequeue() {
    auto oldHead = this->mHead;
    this->mHead = oldHead->next;

    int data = oldHead->data;
    delete oldHead;
    return data;
}

int List::Queue::Front() const {
    assert(this->mHead != nullptr && "cannot get front from empty queue");

    return this->mHead->data;
}

