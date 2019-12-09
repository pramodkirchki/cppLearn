#include <iostream>
#include <vector>

class SomeClass
{
  public:
    SomeClass( uint32_t index, std::vector<int64_t> &Ints ):
    m_index( index ),
    vecInts( Ints )
    {}
    void printName() { std::cout<< }
    uint32_t getIndex() {return m_index;}
  private:
    uint32_t m_index{0};
    std::vector<int64_t> vecInts;
};

int main( int argc, char *argv[])
{
  return 0;
}