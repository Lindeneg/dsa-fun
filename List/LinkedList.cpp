#include "LinkedList.h"

#include <iostream>

template <typename T>
list::LinkedList<T>::LinkedList() : mSize(0), mHead(nullptr) {}

template <typename T>
list::LinkedList<T>::LinkedList(const LinkedList& other) {
    std::cout << "Copy Constructor Called\n";

    this->mHead = nullptr;
    this->mSize = 0;

    this->From(other);
}

template <typename T>
list::LinkedList<T>::~LinkedList<T>() {
    std::cout << "Destructor Called!\n";

    if (this->mHead == nullptr) return;

    this->Clear();
}

template <typename T>
void list::LinkedList<T>::Print() const {
    std::cout << "(size " << this->mSize << ") [";

    if (this->mHead != nullptr) {
        auto current = this->mHead;
        while (current->next != nullptr) {
            std::cout << current->data << ',';
            current = current->next;
        }
        std::cout << current->data;
    }

    std::cout << "]\n";
}

template <typename T>
T list::LinkedList<T>::GetNode(int index) const {
    if (this->mHead == nullptr || index > this->mSize - 1) return NULL;

    auto current = this->mHead;
    for (int i = 0; i < index; i++) {
        if (current->next == nullptr) return NULL;
        current = current->next;
    }
    if (current == nullptr) return NULL;

    return current->data;
}

template <typename T>
bool list::LinkedList<T>::RemoveNode(int index) {
    if (this->mHead == nullptr || index > this->mSize - 1) return false;

    // handle case where head is removed
    if (index == 0) {
        // keep ref to old head
        auto oldHead = this->mHead;
        // set head to next ref
        this->mHead = this->mHead->next;
        // remove old head
        this->Free(oldHead);

        return true;
    }

    auto current = this->mHead;
    for (int i = 0; i < index - 1; i++) {
        if (current->next == nullptr) return false;
        current = current->next;
    }

    // take ref to delete target
    auto target = current->next;
    // set current next to the entry after our delete target
    current->next = target->next;

    // delete target
    this->Free(target);

    return true;
}

template <typename T>
void list::LinkedList<T>::Clear() {
    // traverse the list freeing entries
    auto current = this->mHead;
    while (current != nullptr) {
        auto tmp = current;
        current = current->next;

        this->Free(tmp);
    }

    this->mHead = nullptr;
}

template <typename T>
void list::LinkedList<T>::Append(T data) {
    std::cout << "Appending " << data << '\n';

    const auto newNode = new Node<T>();
    newNode->data = data;
    newNode->next = nullptr;

    // if no head is set, set new node as head
    if (this->mHead == nullptr) {
        newNode->next = this->mHead;
        this->mHead = newNode;
        ++this->mSize;
        return;
    }

    // find last node in list
    auto tmp = this->mHead;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    // set newNode as last node
    tmp->next = newNode;
    ++this->mSize;
}

template <typename T>
void list::LinkedList<T>::InsertAt(T data, int index) {
    std::cout << "Inserting " << data << " at idx " << index << '\n';

    const auto newNode = new Node<T>();
    newNode->data = data;
    newNode->next = nullptr;

    // set data as new head if applicable
    if (index == 0 || this->mHead == nullptr) {
        newNode->next = this->mHead;
        this->mHead = newNode;
        ++this->mSize;
        return;
    }

    // else find the desired position
    // if index >= mSize, data is new tail
    auto current = this->mHead;
    for (int i = 0; i < index - 1; i++) {
        if (current->next == nullptr) break;
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    ++this->mSize;
}

template <typename T>
void list::LinkedList<T>::Reverse() {
    if (this->mHead == nullptr || this->mSize <= 1) return;

    auto current = this->mHead;
    Node<T>* prev = nullptr;

    while (current != nullptr) {
        auto next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    this->mHead = prev;
}

template <typename T>
void list::LinkedList<T>::From(const LinkedList& other) {
    // if source is empty, return
    if (other.mHead == nullptr) return;

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

template <typename T>
void list::LinkedList<T>::Free(Node<T>* node) {
    std::cout << "Freeing " << node->data << '\n';

    delete node;
    --this->mSize;
}

template class list::LinkedList<int>;
