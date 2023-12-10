#include "DoublyLinkedList.h"

#include <cassert>
#include <iostream>

list::DoublyLinkedList::~DoublyLinkedList() {
    std::cout << "Destructor called size " << this->mSize << '\n';

    if (this->mHead == nullptr) return;

    this->Clear();
}

void list::DoublyLinkedList::Append(int data) {
    std::cout << "Appending " << data << '\n';

    auto newNode = new Node2();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (this->mHead == nullptr) {
        this->mHead = newNode;
        ++this->mSize;
        return;
    }

    auto current = this->mHead;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    ++this->mSize;
}

void list::DoublyLinkedList::Clear() {
    auto current = this->mHead;
    while (current != nullptr) {
        auto tmp = current;
        current = current->next;
        this->Free(tmp);
    }
    this->mHead = nullptr;
}

void list::DoublyLinkedList::Free(Node2* node) {
    assert(node != nullptr && "trying to free nullptr");
    assert(this->mSize > 0 && "cannot free when size is non-positive");

    std::cout << "Freeing " << node->data << '\n';

    delete node;
    --this->mSize;
}
