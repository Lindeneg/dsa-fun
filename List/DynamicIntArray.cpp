#include "DynamicIntArray.h"

#include <algorithm>
#include <cassert>
#include <iostream>

list::DynamicIntArray::DynamicIntArray()
    : mData(new int[INITIAL_CAPACITY]), mSize(0), mCapacity(INITIAL_CAPACITY) {
    if (this->mData != nullptr) {
        this->InitUninitializedData();
    }
}

list::DynamicIntArray::DynamicIntArray(const DynamicIntArray& other)
    : mData(nullptr), mSize(0), mCapacity(0) {
    std::cout << "Copy Constructor Called!\n";
    this->From(other);
}

list::DynamicIntArray::DynamicIntArray(DynamicIntArray&& other) noexcept
    : mData(nullptr), mSize(0), mCapacity(0) {
    std::cout << "Move Constructor Called!\n";

    this->From(other);

    delete[] other.mData;
    other.mData = nullptr;
    other.mCapacity = 0;
    other.mSize = 0;
}

list::DynamicIntArray& list::DynamicIntArray::operator=(
    const DynamicIntArray& other) {
    std::cout << "Copy Assignment Operator called!\n";

    if (this == &other) return *this;

    this->From(other);

    return *this;
}

list::DynamicIntArray& list::DynamicIntArray::operator=(
    DynamicIntArray&& other) noexcept {
    std::cout << "Move Assignment Operator called!\n";

    if (this == &other) return *this;

    this->From(other);

    delete[] other.mData;
    other.mData = nullptr;
    other.mCapacity = 0;
    other.mSize = 0;

    return *this;
}

list::DynamicIntArray::~DynamicIntArray() {
    std::cout << "Deconstructor called!\n";
    if (this->mData == nullptr) return;

    delete[] this->mData;
    this->mSize = 0;
    this->mCapacity = 0;
}

const int& list::DynamicIntArray::operator[](int index) const {
    assert(this->mData != nullptr && index < this->mCapacity);
    return this->mData[index];
}

int& list::DynamicIntArray::operator[](int index) {
    assert(this->mData != nullptr && index < this->mCapacity);
    return this->mData[index];
}

void list::DynamicIntArray::From(const DynamicIntArray& other) {
    assert(other.mCapacity > 0 && "cannot copy empty array");

    // remove old data, if any
    if (this->mData != nullptr) {
        delete[] this->mData;
        this->mSize = 0;
        this->mCapacity = 0;
    }

    this->mData = new int[other.mCapacity];
    this->mSize = other.mSize;
    this->mCapacity = other.mCapacity;

    for (int i = 0; i < this->mSize; i++) {
        this->mData[i] = other[i];
    }

    this->InitUninitializedData();
}

bool list::DynamicIntArray::Resize(int newCapacity) {
    assert(newCapacity > 0 && "cannot honor non-positive capacity");

    std::cout << "Resizing from " << this->mCapacity << " to " << newCapacity
              << '\n';

    int* oldData = this->mData;
    // we inform of result via return bool, so std::nothrow used here
    this->mData = new (std::nothrow) int[(unsigned long long)newCapacity];
    if (!this->mData) {
        std::cout << "Failed to aquire new memory\n";

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

void list::DynamicIntArray::InitUninitializedData() {
    if (this->mData != nullptr && this->mCapacity > this->mSize) {
        // initialize any uninitialized data within the capacity
        for (int i = this->mSize; i < this->mCapacity; i++) {
            this->mData[i] = 0;
        }
    }
}

bool list::DynamicIntArray::Append(int data) {
    std::cout << "Appending " << data << '\n';

    if (this->mSize + 1 > this->mCapacity) {
        bool didResize = this->Resize(this->mCapacity * RESIZE_MULTIPLIER);
        if (!didResize) {
            return false;
        }
    }

    this->mData[this->mSize++] = data;

    return true;
}

void list::DynamicIntArray::Clear() {
    std::cout << "Clearing Array\n";

    if (this->mSize <= 0) return;

    for (int i = 0; i < this->mSize; i++) {
        this->mData[i] = 0;
    }
    this->mSize = 0;

    // array is now empty, might as well resize it if appropiate
    if (this->mCapacity >= INITIAL_CAPACITY * RESIZE_MULTIPLIER) {
        this->Resize(INITIAL_CAPACITY);
    }
}

void list::DynamicIntArray::Reverse() {
    // alternatively, create a new array of same size
    // iterate i = this->mSize; i <= 0; i--; and set
    // members of the new array to effectievly reverse
    // however std::reverse is great and works with pointers
    std::reverse(this->mData, this->mData + this->mSize);
}

void list::DynamicIntArray::Print() const {
    std::cout << "(size " << this->mSize << " capacity " << this->mCapacity
              << ")\n[";

    for (int i = 0; i < this->mCapacity; i++) {
        std::cout << this->mData[i];
        if (i < this->mCapacity - 1) {
            std::cout << ',';
        }
    }

    std::cout << "]\n";
}

