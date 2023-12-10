#pragma once

#include <ostream>
namespace list {

class DynamicIntArray {
   private:
    static constexpr int INITIAL_CAPACITY{10};
    static constexpr int RESIZE_MULTIPLIER{2};

    int* mData;
    int mSize;
    int mCapacity;

    bool Resize(int newCapacity);
    void From(const DynamicIntArray& other);
    void InitUninitializedData();

   public:
    DynamicIntArray();
    DynamicIntArray(const DynamicIntArray& other);
    DynamicIntArray(DynamicIntArray&& other) noexcept;
    ~DynamicIntArray();

    inline int GetSize() const { return this->mSize; }
    inline int GetCapacity() const { return this->mCapacity; }

    inline friend std::ostream& operator<<(std::ostream& os,
                                           const DynamicIntArray& arr) {
        os << "(size " << arr.mSize << " capacity " << arr.mCapacity << ")\n[";

        for (int i = 0; i < arr.mCapacity; i++) {
            os << arr.mData[i];
            if (i < arr.mCapacity - 1) {
                os << ',';
            }
        }

        os << "]\n";
        return os;
    }

    DynamicIntArray& operator=(const DynamicIntArray& other);
    DynamicIntArray& operator=(DynamicIntArray&& other) noexcept;

    const int& operator[](int index) const;
    int& operator[](int index);

    bool Append(int data);
    void Reverse();
    void Clear();
};
}  // namespace list
