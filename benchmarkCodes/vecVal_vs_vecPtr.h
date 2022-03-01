#ifndef VECVAL_VS_VECPTR
#define VECVAL_VS_VECPTR
/*
 * vecVal_vs_vecPtr.h
 *
 *  Created on: 25.12.2019
 *      Author: MURALIDH
 */

#include <algorithm>
#include <memory>
#include <vector>
#include <random>
#include <benchmark/benchmark.h>

class LargeObject
{

public:
  LargeObject(int id_) : m_id(id_)
  {
  }
  int getID() { return m_id;}
private:
  long long m_l {0};
  int m_id;
  char m_c {0};
  int m_arr[100];
};

using vecLargeObjectVal = std::vector<LargeObject>;
using vecLargeObjectPtr = std::vector<std::unique_ptr<LargeObject>>;
inline void stdSortVectorVal( vecLargeObjectVal &randNumbers )
{
  std::sort( randNumbers.begin(), randNumbers.end(), [](LargeObject& a, LargeObject& b) { return a.getID() < b.getID(); } );
}

inline void stdSortVectorPtr( vecLargeObjectPtr &randNumbers )
{
  std::sort( randNumbers.begin(), randNumbers.end(), [](const std::unique_ptr<LargeObject>& a, const std::unique_ptr<LargeObject>& b){ return a->getID() < b->getID(); } );
}

vecLargeObjectVal constructRandomContainerVal( int size )
{
  vecLargeObjectVal randNumbers;
  for (int i = 0; i < size; ++i)
  {
	  randNumbers.push_back( LargeObject( std::rand() % size ) );
  }
  return randNumbers;
}

vecLargeObjectPtr constructRandomContainerPtr( int size )
{
  vecLargeObjectPtr randNumbers;
  for (int i = 0; i < size; ++i)
  {
  	std::unique_ptr<LargeObject> ptr2LargeObject(new LargeObject( std::rand() % size ));
	  randNumbers.push_back(std::move(ptr2LargeObject));
  }
  return randNumbers;
}

// Using fixtures.
class TestFixture : public ::benchmark::Fixture {
 public:
  void SetUp(const ::benchmark::State& st) {
    m_randNumbers = constructRandomContainerVal( static_cast<int>(st.range(0)) );
    m_randNumbersPtr = constructRandomContainerPtr( static_cast<int>(st.range(0)) );
  }

  void TearDown(const ::benchmark::State&) {
  	m_randNumbers.clear();
  	m_randNumbersPtr.clear();
  }

 vecLargeObjectVal m_randNumbers;
 vecLargeObjectPtr m_randNumbersPtr;
};

BENCHMARK_DEFINE_F(TestFixture, BM_stdSortVectorVal)(benchmark::State& state) {
  for (auto _ : state) {
    stdSortVectorVal( m_randNumbers );
  }
}

BENCHMARK_DEFINE_F(TestFixture, BM_stdSortVectorPtr)(benchmark::State& state) {
  for (auto _ : state) {
    stdSortVectorPtr( m_randNumbersPtr );
  }
}
BENCHMARK_REGISTER_F(TestFixture, BM_stdSortVectorVal)->Range(1 << 3, 1 << 12);
BENCHMARK_REGISTER_F(TestFixture, BM_stdSortVectorPtr)->Range(1 << 3, 1 << 12);

#endif /* VECVAL_VS_VECPTR */
