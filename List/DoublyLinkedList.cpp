#include "DoublyLinkedList.h"

#include <cassert>
#include <iostream>

list::DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other)
    : mHead(nullptr), mSize(0) {
    std::cout << "Copy constructor called!\n";

    this->From(other);
}

list::DoublyLinkedList::DoublyLinkedList(DoublyLinkedList&& other) noexcept
    : mHead(nullptr), mSize(0) {
    std::cout << "Move Constructor called!\n";

    this->From(other);
    other.Clear();
}

list::DoublyLinkedList::~DoublyLinkedList() {
    std::cout << "Destructor called size " << this->mSize << '\n';

    if (this->mHead == nullptr) {
        return;
    }

    this->Clear();
}

list::DoublyLinkedList& list::DoublyLinkedList::operator=(
    const DoublyLinkedList& other) {
    std::cout << "Copy Assignment Operator called\n";

    if (this == &other) {
        return *this;
    }

    this->Clear();
    this->From(other);

    return *this;
}

list::DoublyLinkedList& list::DoublyLinkedList::operator=(
    DoublyLinkedList&& other) noexcept {
    std::cout << "Move Assignment Operator called\n";

    if (this == &other) {
        return *this;
    }

    this->Clear();
    this->From(other);
    other.Clear();

    return *this;
}

void list::DoublyLinkedList::From(const DoublyLinkedList& other) {
    // if source is empty, return
    if (other.mHead == nullptr) {
        return;
    }

    // if we already have data, delete it
    if (this->mSize > 0) {
        this->Clear();
    }

    // traverse the source list
    auto current = other.mHead;
    while (current->next != nullptr) {
        // append to dest list
        this->Append(current->data);
        current = current->next;
    }
    // dont forget the last element
    this->Append(current->data);
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

void list::DoublyLinkedList::InsertAt(int data, int index) {
    std::cout << "Inserting " << data << " at index " << index << '\n';
    assert(index >= 0 && index < this->mSize && "index out of bounds");

    auto newNode = new Node2();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (index == 0) {
        auto oldHead = this->mHead;
        this->mHead = newNode;
        newNode->next = oldHead;
        oldHead->prev = newNode;
        ++this->mSize;
        return;
    }

    auto current = this->mHead;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    newNode->next = current;
    current->prev->next = newNode;
    newNode->prev = current->prev;
    current->prev = newNode;

    ++this->mSize;
}

void list::DoublyLinkedList::RemoveNode(int index) {
    std::cout << "Removing node at index " << index << '\n';
    assert(index >= 0 && index < this->mSize && "index out of bounds");

    if (index == 0) {
        auto oldHead = this->mHead;
        this->mHead = oldHead->next;
        this->mHead->prev = nullptr;

        this->Free(oldHead);
        return;
    }

    auto current = this->mHead;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    current->prev->next = current->next;

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    this->Free(current);
}

int list::DoublyLinkedList::GetNode(int index) const {
    std::cout << "Get node at index " << index;
    assert(index >= 0 && index < this->mSize && "index out of bounds");

    auto current = this->mHead;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    assert(current != nullptr);

    std::cout << " value " << current->data << '\n';

    return current->data;
}

void list::DoublyLinkedList::Reverse() {
    if (this->mHead == nullptr || this->mSize <= 1) {
        return;
    }

    std::cout << "Reversing list\n";

    auto current = this->mHead;
    while (current->next != nullptr) {
        auto next = current->next;
        current->next = current->prev;
        current->prev = next;
        current = next;
    }
    this->mHead = current;
    current->next = current->prev;
    current->prev = nullptr;
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
