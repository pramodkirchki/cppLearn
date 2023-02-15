#include "stdint.h"
#include<iostream>
#include <cstring>
#include<array>
#include <set>
typedef uint32_t myType;
 uint32_t arr[2] = { 0x0000aa55, 0x55aa0000};
// uint16_t arr[4] = { 0xaa55, 0x0000, 0x0000, 0x55aa};
// uint8_t arr[8] = { 0x55, 0xaa, 0x00, 0x00, 0x00, 0x00, 0xaa, 0x55};

void func1()
{
    myType *arr2 = (myType*)&arr;

    myType res = arr2[0] | arr2[1];
    std::cout << "func1 : Result : " << std::hex << static_cast<uint32_t>(res);
}

void func2()
{
    myType arr2[8];
    std::memcpy(arr2, arr, 8);

    myType res = arr2[0] | arr2[1];
    std::cout << "\nfunc2 : Result : " << std::hex << static_cast<uint32_t>(res);
}

int main()
{
    std::array<std::array<int,3>,4> arr = {0};
    func1();
    func2();
    std::set<uint8_t> testvector{2,4,2,1};
    testvector.insert(5);
    testvector.insert(0);

    std::cout << "Printing array ";
    for(auto a : arr)
    {
        for(auto b : a)
        std::cout << b << " " ;
    }
    for(auto a: testvector)
    {
        std::cout << "\n" << static_cast<uint32_t>(a) << ", ";
    }
    std::cout << "\nSize : " << testvector.size();
    int i = 0x10000 | 2;
    std::cout << "\ni : " << i;
    return 0;
}