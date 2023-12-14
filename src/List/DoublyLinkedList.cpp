#include "DoublyLinkedList.h"

#include <cassert>
#include <iostream>

List::DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other)
    : mHead(nullptr), mSize(0) {
    std::cout << "DoublyLinkedList Copy constructor called!\n";

    this->From(other);
}

List::DoublyLinkedList::DoublyLinkedList(DoublyLinkedList&& other) noexcept
    : mHead(nullptr), mSize(0) {
    std::cout << "DoublyLinkedList Move Constructor called!\n";

    this->From(other);
    other.Clear();
}

List::DoublyLinkedList::~DoublyLinkedList() {
    std::cout << "DoublyLinkedList Destructor called size " << this->mSize
              << '\n';

    if (this->mHead == nullptr) {
        return;
    }

    this->Clear();
}

List::DoublyLinkedList& List::DoublyLinkedList::operator=(
    const DoublyLinkedList& other) {
    std::cout << "DoublyLinkedList Copy Assignment Operator called\n";

    if (this == &other) {
        return *this;
    }

    this->Clear();
    this->From(other);

    return *this;
}

List::DoublyLinkedList& List::DoublyLinkedList::operator=(
    DoublyLinkedList&& other) noexcept {
    std::cout << "DoublyLinkedList Move Assignment Operator called\n";

    if (this == &other) {
        return *this;
    }

    this->Clear();
    this->From(other);
    other.Clear();

    return *this;
}

void List::DoublyLinkedList::From(const DoublyLinkedList& other) {
    // if source is empty, return
    if (other.mHead == nullptr) {
        return;
    }

    // if we already have data, delete it
    if (this->mSize > 0) {
        this->Clear();
    }

    // traverse the source List
    auto current = other.mHead;
    while (current->next != nullptr) {
        // append to dest List
        this->Append(current->data);
        current = current->next;
    }
    // dont forget the last element
    this->Append(current->data);
}

void List::DoublyLinkedList::Append(int data) {
    std::cout << "DoublyLinkedList Appending " << data << '\n';

    auto newNode = new DoublyNode();
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

void List::DoublyLinkedList::InsertAt(int data, int index) {
    std::cout << "DoublyLinkedList Inserting " << data << " at index " << index
              << '\n';
    assert(index >= 0 && index < this->mSize && "index out of bounds");

    auto newNode = new DoublyNode();
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

void List::DoublyLinkedList::RemoveNode(int index) {
    std::cout << "DoublyLinkedList Removing node at index " << index << '\n';
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

int List::DoublyLinkedList::GetNode(int index) const {
    std::cout << "DoublyLinkedList Get node at index " << index;
    assert(index >= 0 && index < this->mSize && "index out of bounds");

    auto current = this->mHead;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    assert(current != nullptr);

    std::cout << " value " << current->data << '\n';

    return current->data;
}

void List::DoublyLinkedList::Reverse() {
    if (this->mHead == nullptr || this->mSize <= 1) {
        return;
    }

    std::cout << "DoublyLinkedList Reversing List\n";

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

void List::DoublyLinkedList::Clear() {
    auto current = this->mHead;
    while (current != nullptr) {
        auto tmp = current;
        current = current->next;
        this->Free(tmp);
    }
    this->mHead = nullptr;
}

void List::DoublyLinkedList::Free(DoublyNode* node) {
    assert(node != nullptr && "trying to free nullptr");
    assert(this->mSize > 0 && "cannot free when size is non-positive");

    std::cout << "DoublyLinkedList Freeing " << node->data << '\n';

    delete node;
    --this->mSize;
}
