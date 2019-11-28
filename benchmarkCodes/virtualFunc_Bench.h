/*
 * virtualFunc_Bench.h
 *
 *  Created on: 28.11.2019
 *      Author: MURALIDH
 */

#ifndef SRC_APPLICATIONS_NRPHYBENCH_EXAMPLES_VIRTUALFUNC_BENCH_H_
#define SRC_APPLICATIONS_NRPHYBENCH_EXAMPLES_VIRTUALFUNC_BENCH_H_

#include <benchmark/benchmark.h>
#include <stdlib.h>
#include <time.h>
#include <memory>

class Base {
public:
  // Needs to be called for existing object. Hence cannot be static
  virtual int addNumVirt( int x ) { return (i + x); }
  int addNum( int x ) { return (x + i); }
  virtual ~Base() {}

private:
  uint32_t i{10};
};

class Derived : public Base {
public:
  // Overrides of virtual functions are always virtual
  int addNumVirt( int x ) { return (x + i); }
  int addNum( int x ) { return (x + i); }

private:
  uint32_t i{20};
};

static void BM_nonVirtualFunc(benchmark::State &state)
{
 srand(time(0));
 auto x = rand();
 std::unique_ptr<Derived> derived = std::make_unique<Derived>();
 for (auto _ : state)
 {
	auto result = derived->addNum( x );
   benchmark::DoNotOptimize(result);
 }
}
BENCHMARK(BM_nonVirtualFunc);

static void BM_virtualFunc(benchmark::State &state)
{
 srand(time(0));
 auto x = rand();
 std::unique_ptr<Base> derived = std::make_unique<Derived>();
 for (auto _ : state)
 {
	auto result = derived->addNumVirt( x );
   benchmark::DoNotOptimize(result);
 }
}
BENCHMARK(BM_virtualFunc);

#endif /* SRC_APPLICATIONS_NRPHYBENCH_EXAMPLES_VIRTUALFUNC_BENCH_H_ */
