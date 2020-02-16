#include <iostream>

int main()
{
  uint32_t c[10];
  //uint8_t const *p = &c;

  uint32_t *vaddr(c);
  uint64_t vaddrVal(c - (uint32_t *)(0));

  uint64_t paddrVal = reinterpret_cast<uint64_t>(vaddr);
  //std::cout << "No casting : " << std::hex << vaddr << "\n";
  //printAddress();
  //std::cout << std::hex << p << "\n";
  printf("0 address : %0lx \n", (uint32_t *)(0));
  printf("Abhishek : %p \n", vaddr);
  printf("c	 : %p \n", c);
  printf("vaddrVal : %0lx \n", vaddrVal);
  printf("paddrVal : %0lx \n", paddrVal);
 
  return 0;
}
