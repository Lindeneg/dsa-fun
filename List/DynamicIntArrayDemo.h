#include <iostream>

#include "DynamicIntArray.h"

namespace list {
inline void RunDynamicArray() {
    DynamicIntArray arr{};

    std::cout << "Arr1: ";
    arr.Print();

    std::cout << "\nFilling Arr1 with 6 elements\n";
    arr.Append(42);
    arr.Append(7);
    arr.Append(3);
    arr.Append(21);
    arr.Append(16);
    arr.Append(32);

    std::cout << "Arr1: ";
    arr.Print();

    std::cout << "\nForcing a resize\n";
    arr.Append(17);
    arr.Append(19);
    arr.Append(24);
    arr.Append(13);
    arr.Append(6);

    std::cout << "Arr1: ";
    arr.Print();

    std::cout << "\nCopying arr1 into empty arr2\n";
    auto arr2 = arr;
    std::cout << "Arr1: ";
    arr.Print();
    std::cout << "Arr2: ";
    arr2.Print();

    std::cout << "\nCopy Assigning arr1 into empty arr3\n";
    DynamicIntArray arr3;
    arr3 = arr;
    std::cout << "Arr3: ";
    arr3.Print();

    std::cout << "\nGetting arr1[3]: " << arr[3] << '\n';
    std::cout << "Setting arr1[7] to 99";
    arr[7] = 99;
    std::cout << "\nArr1: ";
    arr.Print();

    std::cout << "\nTesting arr1.Clear()\n";
    arr.Clear();
    std::cout << "Arr1: ";
    arr.Print();

    std::cout << "\nReversing arr2\nBefore: ";
    arr2.Print();
    arr2.Reverse();
    std::cout << "After: ";
    arr2.Print();

    std::cout << '\n';
}
}  // namespace list
