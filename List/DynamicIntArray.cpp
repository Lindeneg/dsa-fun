#include "DynamicIntArray.h"

#include <cassert>
#include <iostream>

list::DynamicIntArray::DynamicIntArray() {
    this->mData = new int[INITIAL_CAPACITY];
    this->mSize = 0;
    this->mCapacity = INITIAL_CAPACITY;
}

list::DynamicIntArray::~DynamicIntArray() {
    std::cout << "Deconstructor called!\n";
    if (this->mData == nullptr) return;

    delete[] this->mData;
    this->mSize = 0;
    this->mCapacity = 0;
}

bool list::DynamicIntArray::Resize(int newCapacity) {
    assert(newCapacity > 0 && "cannot honor non-positive capacity");

    std::cout << "Resizing from " << this->mCapacity << " to " << newCapacity
              << '\n';

    int* oldData = this->mData;
    this->mData = new int[(unsigned long long)newCapacity];
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

    // initialize any uninitialized data within the capacity
    if (newCapacity > this->mSize) {
        for (int i = this->mSize; i < this->mCapacity; i++) {
            this->mData[i] = 0;
        }
    }

    return true;
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
    if (this->mCapacity > INITIAL_CAPACITY * RESIZE_MULTIPLIER) {
        this->Resize(INITIAL_CAPACITY);
    }
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

