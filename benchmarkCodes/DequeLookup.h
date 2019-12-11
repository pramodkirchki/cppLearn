#ifndef DEQUELOOKUP_H
#define DEQUELOOKUP_H
/*
 * find_Bench.h
 *
 *  Created on: 11.12.2019
 *      Author: MURALIDH
 */

#include <algorithm>
#include <deque>
#include <cstdlib>
#include <random>
#include <chrono>
#include <benchmark/benchmark.h>

inline std::deque<int>::iterator stdFindDeque( std::deque<int> &randNumbers, int value )
{
  return std::find( randNumbers.begin(), randNumbers.end(), value );
}

std::deque<int> constructRandomDeque( int size )
{
  std::deque<int> randNumbers;
  for (int i = 0; i < size; ++i)
  {
	  randNumbers.push_back( std::rand() % size );
  }
  return randNumbers;
}

static void BM_stdFindDeque( benchmark::State &state )
{
  const int size = static_cast<int>(state.range(0));
  std::deque<int> randNumbers;
  int value;
  for (auto _ : state)
  {
  	state.PauseTiming();
  	randNumbers = constructRandomDeque( size );
    value = std::rand() % size;
  	state.ResumeTiming();
    benchmark::DoNotOptimize( stdFindDeque( randNumbers, value ) ); 
  }
}
BENCHMARK(BM_stdFindDeque)->Range(1 << 3, 1 << 12);

// Using fixtures.
class DequeFixture : public ::benchmark::Fixture {
 public:
  void SetUp(const ::benchmark::State& st) {
    m_randNumbers = constructRandomDeque( static_cast<int>(st.range(0)) );
  }

  void TearDown(const ::benchmark::State&) { m_randNumbers.clear(); }

  std::deque<int> m_randNumbers;
};

BENCHMARK_DEFINE_F(DequeFixture, findElement)(benchmark::State& state) {
  const int size = static_cast<int>(state.range(0));
  int value = std::rand() % size;
  for (auto _ : state) {
    benchmark::DoNotOptimize( stdFindDeque( m_randNumbers, value ) );
  }
}
BENCHMARK_REGISTER_F(DequeFixture, findElement)->Range(1 << 3, 1 << 12);

#endif /* DEQUELOOKUP_H */
