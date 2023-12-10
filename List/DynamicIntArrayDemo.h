#include "DynamicIntArray.h"

namespace list {
inline void RunDynamicArray() {
    DynamicIntArray arr{};

    arr.Print();

    arr.Append(224);
    arr.Append(424);
    arr.Append(4);

    arr.Print();
}
}  // namespace list
