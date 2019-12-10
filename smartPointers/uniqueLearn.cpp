#include <iostream>
#include <vector>
#include <typeinfo>

constexpr uint32_t SIZE = 0xFFFFFFFE;

class SomeClass
{
  public:
    SomeClass( std::vector<int64_t> &Ints ):
    vecInts( Ints )
    {}
    auto printName() { return typeid(*this).name(); }
  private:
    std::vector<int64_t> vecInts;
};

int main( int argc, char *argv[])
{
  std::cout << "Hello!";
  std::vector<int64_t> myVec( SIZE, 10);
  SomeClass myObject( myVec );

  std::cout << "Size of the object " << myObject.printName() << " is : " << sizeof(myObject) ;
  return 0;
}