#pragma once

namespace list {

class DynamicIntArray {
   private:
    static constexpr int INITIAL_CAPACITY{10};
    static constexpr int RESIZE_MULTIPLIER{2};

    int* mData;
    int mSize;
    int mCapacity;

    bool Resize(int newCapacity);

   public:
    DynamicIntArray();
    // DynamicIntArray(const DynamicIntArray& other);
    // DynamicIntArray(DynamicIntArray&& other) noexcept;
    ~DynamicIntArray();

    inline int GetSize() const { return this->mSize; }
    inline int GetCapacity() const { return this->mCapacity; }

    // copy assign
    // DynamicIntArray& operator=(const DynamicIntArray& other);
    // move assign
    // DynamicIntArray& operator=(DynamicIntArray&& other) noexcept;
    // get from index
    // const int& operator[](int index) const;
    // reassign from index
    // int& operator[](int index);

    bool Append(int data);
    // void InsertAt(int data, int index);
    // void Reverse();
    void Clear();
    void Print() const;
};
}  // namespace list
