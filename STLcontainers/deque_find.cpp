#include <algorithm>
#include <deque>
#include <iostream>
#include <random>
#include <chrono>

const int SIZE = 10;

// std::deque<int>::iterator myFind(std::deque<int> &);

int main(int argc, char** argv)
{
  std::cout << "Hello kirchki!\n";
  std::random_device seed;
  std::mt19937 engine( static_cast<unsigned long>(time(0)) );
  std::uniform_int_distribution<int> dist(0, 100);
  std::deque<int> randNumbers;
  
  for (int i = 0; i < SIZE; ++i)
  {
    randNumbers.push_back(dist(engine));
  }
  
  for( auto i : randNumbers ){
    std::cout << i << " ";
  }
  std::cout << "\n";
  
  int value = dist(engine);
  std::deque<int>::iterator it = std::find( randNumbers.begin(), randNumbers.end(), value);
  if( it!= randNumbers.end() ) std::cout << value << "found at " << it - randNumbers.begin();
  else std::cout << value << " not found\n";
  
  
  return 0;
}