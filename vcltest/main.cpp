#include <iostream>
#include "vcl.h"

int main()
{
  std::cout << "Hello! INSTRSET is " << INSTRSET << "\n" ;
  #if defined(__AVX2__)
    std::cout << "AVX2 defined\n";
  #elif defined(__AVX__)
    std::cout << "AVX defined\n";
  #endif
  return 0;
}