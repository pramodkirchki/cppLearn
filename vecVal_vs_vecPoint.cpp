#include <iostream>
#include <vector>
#include <algorithm>
// A big object - Paticle??

class LargeObject
{

public:
  LargeObject(int id_) : m_id(id_)
  {
  }
  int getID() const { return m_id;}
private:
  long long m_l {0};
  int m_id;
  char m_c {0};
  int m_arr[100];
};

bool compare_by_value(const LargeObject& a, const LargeObject& b) {
    return a.getID() < b.getID();
}

bool compare_by_ptr(const LargeObject* a, const LargeObject* b) {
    return a->getID() < b->getID();
}

// vector of such objects
// vector of unique pointers to the objects.

int main(int argc, char **argv)
{
  LargeObject largeObject(10);
  std::vector<LargeObject> vecLargeObjectsVal;
  for (int i = 0; i < 25; i++)
  {
    vecLargeObjectsVal.push_back(largeObject);
  }
  std::vector<LargeObject*> vecLargeObjectsPtr;
  for (int i = 0; i < 25; i++)
  {
    vecLargeObjectsPtr.push_back(new LargeObject(10));
  }  
  std::cout << "Size of LargeData : " << sizeof(largeObject) << "\n";
  std::cout << "Size of std::vector values : " << sizeof(vecLargeObjectsVal) << "\n";
  std::cout << "Size of std::vector pointers : " << sizeof(vecLargeObjectsPtr) << "\n";

  std::sort(vecLargeObjectsVal.begin(), vecLargeObjectsVal.end(), compare_by_value);
  std::sort(vecLargeObjectsPtr.begin(), vecLargeObjectsPtr.end(), compare_by_ptr);

  return 0;
}
// Reason?
//  1. copying?
//  2. Apply algorithms on vec of pointers => can also be applied to FTL containers?