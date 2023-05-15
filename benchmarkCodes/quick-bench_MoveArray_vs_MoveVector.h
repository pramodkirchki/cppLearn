#include <benchmark/benchmark.h>
#include <array>
#include <vector>

struct S
{
  short i;
  short j;
};

using big_array = std::array<std::array<S,1638>, 4>;
using big_vector = std::vector<std::vector<S>>;
big_array S_arr;
big_vector S_vec;

template<typename T>
class Bar
{
  public:
  Bar(T s) : m_sarr(std::move(s)) {}
  private:
  T m_sarr;
};

static void MoveArray(benchmark::State& state) {
  for (auto _ : state) {
    Bar<big_array> b(S_arr);
    benchmark::DoNotOptimize(b);
  }
}
BENCHMARK(MoveArray);

static void MoveVector(benchmark::State& state) {
  S_vec.resize(4);
  for(auto &s : S_vec)
  {
    s.resize(1638);
  }
  for (auto _ : state) {
    Bar<big_vector> b(S_vec);
    benchmark::DoNotOptimize(b);
  }
}
BENCHMARK(MoveVector);
