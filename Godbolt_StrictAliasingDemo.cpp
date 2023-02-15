#include "stdint.h"
#include<iostream>
#include <cstring>

typedef uint64_t myType;
 uint32_t arr[2] = { 0x0000aa55, 0x55aa0000};
// uint16_t arr[4] = { 0xaa55, 0x0000, 0x0000, 0x55aa};
// char arr[8] = { 0x55, 0xaa, 0x00, 0x00, 0x00, 0x00, 0xaa, 0x55};

// Violates strict aliasing
// pun to char and char to something else also violates strict aliasing rule
void func1()
{
    auto *arr2 = reinterpret_cast<myType*>(reinterpret_cast<char*>(&arr));

    myType res = arr2[0] | arr2[1];
    std::cout << "func1 : Result : " << std::hex << static_cast<uint32_t>(res);
}

// Type pun using std::memcpy
// If you really want to access one object using a pointer type of another object
void func2()
{
    myType arr2[8];
    std::memcpy(arr2, arr, 8);

    myType res = arr2[0] | arr2[1];
    std::cout << "\nfunc2 : Result : " << std::hex << static_cast<uint32_t>(res);
}

int main()
{
    func1();
    func2();

    return 0;
}

/*

References:
- https://accu.org/journals/overload/28/160/anonymous/
- https://www.youtube.com/watch?v=_qzMpk-22cc&ab_channel=CppCon

Notes:
- Type casting v/s Type Punning. Type punning = When pointers are casted and alias the other. If 2 different pointers point to the same thing, they are aliasing.
- Type punning can lead to UB if not done correctly - Compilers could optimize away store. -Wstrict-aliasing catches the violation
- Type punning to the "effective" type allowed.
- Type punning to char and back allowed.
- Type punning to other types - Type pun correctly - using memcpy allowed - Optimizer replaces memcpy with mov.
- Type punning to void and then from void to other type and back to void - not sure ?
*/
