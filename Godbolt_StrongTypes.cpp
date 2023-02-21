#include <iostream>

/*
 Motivation :
- using, typedef do not offer type safety.
- btl::nr::NamedParam also donot offer type safety, becasue it is not strong type.
    For example: NamedParam<int> and NamedParam<char> are not interchangeable, but 
    Height = NamedParam<int> and Weight = NamedParam<int> are interchangeable

- Reference - https://www.fluentcpp.com/2016/12/08/strong-types-for-strong-interfaces/
*/

template <typename T>
struct NamedParam
{
  using Base       = NamedParam<T>;
  using value_type = T;
  NamedParam(NamedParam const&other) 
  {
    std::cout << "\n NamedParam copied\n";
  }

  explicit NamedParam(T v)
    : m_value(v){};
  T get() const { return m_value; }
  
  // NamedParam provides operations for built-in types.
  // If only selected operators need to be provided, refer crtp example at 
  // https://www.fluentcpp.com/2017/05/23/strong-types-inheriting-functionalities-from-underlying/
  // OR
  // https://www.foonathan.net/2016/10/strong-typedefs/
  auto operator==(const NamedParam& rhs) const
  {
	  return m_value == rhs.get();
  }

private:
    operator T() { return m_value; }
  T m_value;
};

// Phantom is a Tag that makes NamedParam strong
template<typename T, typename Phantom>
struct StrongNamedParam : NamedParam<T>
{
    StrongNamedParam(T v)
    : NamedParam<T>(v) {};

    StrongNamedParam(StrongNamedParam const &s): NamedParam<T>(s.get())
    {
        std::cout << "StrongNamedParam copied!\n";
    }

    StrongNamedParam(StrongNamedParam &&s): NamedParam<T>(s.get())
    {
        std::cout << "StrongNamedParam moved!!\n";
    }
};

// The Phantom parameter makes Height and Weight strong types
// Note: Height = StrongNamedParam<int, struct HeightParameter> and Width = StrongNamedParam<int, struct HeightParameter> are still interchangeable
using Height = StrongNamedParam<int, struct HeightParameter>;
using Width = StrongNamedParam<int, struct WidthParameter>;

// Both copy and Ref passing supported
void printFunc(Height i, Width &j)
{
    if(i.get() == j.get())
    {
        std::cout << "The values Height and Width are equal\n";
    }
    std::cout << "\n First = " << i.get() << ", Second=" << j.get() << "\n";
}

int main()
{
    Height i(42);
    Width j(42);
    printFunc(i, j);
    // printFunc(i, i); // Error because Height and Weight are strong types and hence are not interchangeable
    return 0;
}