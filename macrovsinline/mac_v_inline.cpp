#include <iostream>

// calling printMax with the maximum of a and b
#define CALL_WITH_MAX(a, b) printMax((a > b ? a : b))

void printMax(int a)
{
  std::cout << "Max is :" << a << std::endl;
}

inline callWithMax(const& a, const& b)
{
  printMax((a > b ? a : b));
}

int main(int argc, char const* argv[])
{
  std::cout << "Hello\n";
  int a;
  a = 6;
  // We would expect to call with a = 7 and b = 6
  std::cout << "With Macro => ";
  CALL_WITH_MAX(++a, 6); // Prints 8, because incremented twice
  a = 6;
  std::cout << "With inline => ";
  callWithMax(++a, 6);	// Prints 7 as expected
  return 0;
}
