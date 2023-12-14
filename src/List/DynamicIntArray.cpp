#include "DynamicIntArray.h"

#include <algorithm>
#include <cassert>
#include <iostream>

List::DynamicIntArray::DynamicIntArray()
    : mData(new int[INITIAL_CAPACITY]), mSize(0), mCapacity(INITIAL_CAPACITY) {
    if (this->mData != nullptr) {
        this->InitUninitializedData();
    }
}

List::DynamicIntArray::DynamicIntArray(const DynamicIntArray& other)
    : mData(nullptr), mSize(0), mCapacity(0) {
    std::cout << "DynamicIntArray Copy Constructor Called!\n";

    this->From(other);
}

List::DynamicIntArray::DynamicIntArray(DynamicIntArray&& other) noexcept
    : mData(nullptr), mSize(0), mCapacity(0) {
    std::cout << "DynamicIntArray Move Constructor Called!\n";

    this->From(other);

    delete[] other.mData;
    other.mData = nullptr;
    other.mCapacity = 0;
    other.mSize = 0;
}

List::DynamicIntArray::~DynamicIntArray() {
    std::cout << "DynamicIntArray Deconstructor called!\n";
    if (this->mData != nullptr) {
        delete[] this->mData;
        this->mSize = 0;
        this->mCapacity = 0;
    }
}

List::DynamicIntArray& List::DynamicIntArray::operator=(
    const DynamicIntArray& other) {
    std::cout << "DynamicIntArray Copy Assignment Operator called!\n";

    if (this == &other) {
        return *this;
    }

    this->From(other);

    return *this;
}

List::DynamicIntArray& List::DynamicIntArray::operator=(
    DynamicIntArray&& other) noexcept {
    std::cout << "DynamicIntArray Move Assignment Operator called!\n";

    if (this == &other) {
        return *this;
    }

    this->From(other);

    delete[] other.mData;
    other.mData = nullptr;
    other.mCapacity = 0;
    other.mSize = 0;

    return *this;
}

const int& List::DynamicIntArray::operator[](int index) const {
    assert(this->mData != nullptr && index < this->mCapacity);
    return this->mData[index];
}

int& List::DynamicIntArray::operator[](int index) {
    assert(this->mData != nullptr && index < this->mCapacity);
    return this->mData[index];
}

void List::DynamicIntArray::From(const DynamicIntArray& other) {
    assert(other.mCapacity > 0 && "cannot copy empty array");

    // remove old data, if any
    if (this->mData != nullptr) {
        delete[] this->mData;
        this->mSize = 0;
        this->mCapacity = 0;
    }

    this->mData = new int[static_cast<std::size_t>(other.mCapacity)];
    this->mSize = other.mSize;
    this->mCapacity = other.mCapacity;

    for (int i = 0; i < this->mSize; i++) {
        this->mData[i] = other[i];
    }

    this->InitUninitializedData();
}

bool List::DynamicIntArray::Resize(int newCapacity) {
    assert(newCapacity > 0 && "cannot honor non-positive capacity");

    std::cout << "DynamicIntArray Resizing from " << this->mCapacity << " to "
              << newCapacity << '\n';

    int* oldData = this->mData;
    // we inform of result via return bool, so std::nothrow used here
    this->mData = new (std::nothrow) int[(unsigned long long)newCapacity];
    if (!this->mData) {
        std::cout << "DynamicIntArray Failed to aquire new memory\n";

        this->mData = oldData;
        return false;
    }

    this->mCapacity = newCapacity;
    // ensure size is not over new capacity
    if (this->mSize > newCapacity) {
        this->mSize = newCapacity;
    }

    // copy old data within capacity to new array
    for (int i = 0; i < this->mSize; i++) {
        this->mData[i] = oldData[i];
    }

    delete[] oldData;

    this->InitUninitializedData();

    return true;
}

void List::DynamicIntArray::InitUninitializedData() {
    if (this->mData != nullptr && this->mCapacity > this->mSize) {
        // initialize any uninitialized data within the capacity
        for (int i = this->mSize; i < this->mCapacity; i++) {
            this->mData[i] = 0;
        }
    }
}

bool List::DynamicIntArray::Append(int data) {
    std::cout << "DynamicIntArray Appending " << data << '\n';

    if (this->mSize + 1 > this->mCapacity) {
        bool didResize = this->Resize(this->mCapacity * RESIZE_MULTIPLIER);
        if (!didResize) {
            return false;
        }
    }

    this->mData[this->mSize++] = data;

    return true;
}

void List::DynamicIntArray::Clear() {
    std::cout << "DynamicIntArray Clearing Array\n";

    if (this->mSize <= 0) {
        return;
    }

    for (int i = 0; i < this->mSize; i++) {
        this->mData[i] = 0;
    }
    this->mSize = 0;

    // array is now empty, might as well resize it if appropiate
    if (this->mCapacity >= INITIAL_CAPACITY * RESIZE_MULTIPLIER) {
        this->Resize(INITIAL_CAPACITY);
    }
}

void List::DynamicIntArray::Reverse() {
    // alternatively, create a new array of same size
    // iterate i = this->mSize; i <= 0; i--; and set
    // members of the new array to effectievly reverse
    // however std::reverse is great and works with pointers
    std::reverse(this->mData, this->mData + this->mSize);
}

