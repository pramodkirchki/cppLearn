#include <algorithm>
#include <deque>
#include <iostream>
#include <random>
#include <chrono>

const int SIZE = 10;

std::deque<int>::iterator myFind(std::deque<int> &myDeque, const int& value)
{
  for( auto it = myDeque.begin(); it != myDeque.end(); ++it)
  {
    if((*it) == value)
      return it;
  }
  return myDeque.end();
}

int main(int argc, char** argv)
{
  std::cout << "Hello kirchki!\n";
  std::random_device seed;
  std::mt19937 engine( static_cast<unsigned long>(time(0)) );
  std::uniform_int_distribution<int> dist(0, 100);
  std::deque<int> randNumbers;
  std::deque<int> myNumbers = {1,2,3,4,5,6,7,8,9,10};
  for (int i = 0; i < SIZE; ++i)
  {
    randNumbers.push_back(dist(engine));
  }
  
  for( auto i : myNumbers ){
    std::cout << i << " ";
  }
  std::cout << "\n";
  
  int value = dist(engine);
  value = 10;
  std::deque<int>::iterator it = std::find( myNumbers.begin(), myNumbers.end(), value);
  if( it!= myNumbers.end() ) std::cout << value << " found at " << it - myNumbers.begin() << "\n";
  else std::cout << value << " not found\n";
  
  it = myFind(myNumbers, value);
  if( it!= myNumbers.end() ) std::cout << value << " found at " << it - myNumbers.begin() << "\n";
  else std::cout << value << " not found\n";
  
  return 0;
}