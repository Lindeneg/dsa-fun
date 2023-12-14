#include "LinkedList.h"

#include <cassert>
#include <iostream>

template <typename T>
List::LinkedList<T>::LinkedList(const LinkedList& other)
    : mSize(0), mHead(nullptr) {
    std::cout << "LinkedList Copy Constructor Called\n";

    this->From(other);
}

template <typename T>
List::LinkedList<T>::LinkedList(LinkedList&& other) noexcept
    : mSize(0), mHead(nullptr) {
    std::cout << "LinkedList Move Constructor Called" << '\n';

    this->From(other);
    other.Clear();
}

template <typename T>
List::SinglyNode<T>* List::LinkedList<T>::GetNode(int index) const {
    assert(index >= 0 && index < this->mSize && "index is out of bounds");

    auto current = this->mHead;
    for (auto i = 0; i < index; i++) {
        if (current == nullptr) {
            return nullptr;
        }
        current = current->next;
    }

    return current;
}

/* Suppose we have this structure in memory
 * |(INDEX)ADDRESS|
 *
 * |(0)100|->|(1)200|->|(2)50|->|(3)0|
 *
 * and we want to remove node at index n,
 * we'd have to find node at index n-1 to get (n-1)->next reference
 * then we want that reference to be either (n+1) or nullptr
 *
 * Suppoze n=2, then the above structure should result in:
 *
 * |(0)100|->|(1)200|->|(2)0|
 *
 * If index=0, then we'd have to change the head.
 * That means newHead=oldHead->next, or:
 *
 * |(0)200|->|(1)50|->|(2)0| */
template <typename T>
bool List::LinkedList<T>::RemoveNode(int index) {
    assert(index >= 0 && index < this->mSize && "index is out of bounds");

    if (this->mHead == nullptr) {
        return false;
    }

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
    for (auto i = 0; i < index - 1; i++) {
        if (current->next == nullptr) {
            return false;
        }
        current = current->next;
    }

    // get ref to node(n)
    auto target = current->next;
    // set node(n-1)->next to node(n+1)
    current->next = target->next;

    // delete node(n)
    this->Free(target);

    return true;
}

template <typename T>
void List::LinkedList<T>::Clear() {
    auto current = this->mHead;
    while (current != nullptr) {
        auto tmp = current;
        current = current->next;

        this->Free(tmp);
    }

    this->mHead = nullptr;
}

template <typename T>
void List::LinkedList<T>::Append(T data) {
    std::cout << "LinkedList Appending " << data << '\n';

    const auto newSinglyNode = new SinglyNode<T>();
    newSinglyNode->data = data;
    newSinglyNode->next = nullptr;

    // if no head is set, set new node as head
    if (this->mHead == nullptr) {
        newSinglyNode->next = this->mHead;
        this->mHead = newSinglyNode;
        ++this->mSize;
        return;
    }

    // find last node in List
    auto tmp = this->mHead;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    // set newSinglyNode as last node
    tmp->next = newSinglyNode;
    ++this->mSize;
}

/* Suppose we have this structure in memory:
 *
 * |(INDEX)ADDRESS|
 *
 * |(0)100|->|(1)200|->|(2)50|->|(3)0|
 *
 * We want to insert node, with value k, at index n.
 *
 * We'd have to find node at index n-1 to get (n-1)->next reference,
 * then we want that reference to point to new node.
 *
 * New node next reference should either be
 * node that previously occupied n or nullptr.
 *
 * Suppoze n=2, then the above structure should result in:
 *
 * |(0)100|->|(1)200|->|(2)*newSinglyNode|->|(3)50|->|(4)0|
 *
 * If index=0, then we'd have to change the head.
 * That means newSinglyNode->next=oldHead;head=newSinglyNode, or:
 *
 * |(0)*n|->|(1)100|->|(2)200|->|(3)50|->|(4)0| */
template <typename T>
void List::LinkedList<T>::InsertAt(T data, int index) {
    std::cout << "LinkedList Inserting " << data << " at idx " << index << '\n';

    assert(index >= 0 && index < this->mSize && "index is out of bounds");

    const auto newSinglyNode = new SinglyNode<T>();
    newSinglyNode->data = data;
    newSinglyNode->next = nullptr;

    if (index == 0 || this->mHead == nullptr) {
        newSinglyNode->next = this->mHead;
        this->mHead = newSinglyNode;
        ++this->mSize;
        return;
    }

    auto current = this->mHead;
    for (int i = 0; i < index - 1; i++) {
        if (current->next == nullptr) {
            break;
        }
        current = current->next;
    }
    newSinglyNode->next = current->next;
    current->next = newSinglyNode;
    ++this->mSize;
}

/* Suppose we have this structure in memory:
 *
 * |(INDEX)ADDRESS|
 *
 * |(0)100|->|(1)200|->|(2)50|->|(3)0|
 *
 * We want to reverse that structure. In a nutshell,
 * for a given n, we want the next reference to
 * either be the previous node (n-1) or nullptr
 *
 * In the above structure that would mean n0 would
 * point to nullptr. n1 would point to n0 and so on. */
template <typename T>
void List::LinkedList<T>::Reverse() {
    if (this->mHead == nullptr || this->mSize <= 1) {
        return;
    }

    auto current = this->mHead;
    SinglyNode<T>* prev = nullptr;

    while (current != nullptr) {
        // dont loose ref to next
        auto next = current->next;
        // set next to previous (reverse)
        current->next = prev;
        prev = current;
        current = next;
    }

    this->mHead = prev;
}

template <typename T>
void List::LinkedList<T>::From(const LinkedList& other) {
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

template <typename T>
void List::LinkedList<T>::Free(SinglyNode<T>* node) {
    assert(node != nullptr && "cannot free nullptr");
    assert(this->mSize > 0 && "cannot free when size is non-positive");

    std::cout << "LinkedList Freeing " << node->data << '\n';

    delete node;
    --this->mSize;
}

template <typename T>
List::LinkedList<T>& List::LinkedList<T>::operator=(const LinkedList& other) {
    std::cout << "LinkedList Copy Assignment Operator called\n";

    if (this == &other) {
        return *this;
    }

    this->Clear();
    this->From(other);

    return *this;
}

template <typename T>
List::LinkedList<T>& List::LinkedList<T>::operator=(
    LinkedList&& other) noexcept {
    std::cout << "Move Assignment Operator called\n";

    if (this == &other) {
        return *this;
    }

    this->Clear();
    this->From(other);
    other.Clear();

    return *this;
}

template <typename T>
List::LinkedList<T>::~LinkedList<T>() {
    std::cout << "LinkedList Destructor Called size " << this->mSize << '\n';

    if (this->mHead != nullptr) {
        this->Clear();
    }
}

template class List::LinkedList<int>;
template class List::LinkedList<double>;
