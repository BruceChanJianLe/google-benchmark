#include <benchmark/benchmark.h>
#include <cstddef>
#include "link_list/link_list.hpp"


static void linkListBench(benchmark::State &s)
{
  cjl::LinkedList ll;

  // Extract link list size
  int len = s.range(0);

  std::vector<int> index(len);
  std::iota(index.begin(), index.end(), 0);

  // Run the benchmark
  for (auto _ : s)
  {
    for (auto& id : index)
    {
      ll.append(id);
    }
  }
}

// Register the benchmark
BENCHMARK(linkListBench)->DenseRange(0, 99);

int main (int argc, char *argv[])
{
  benchmark::Initialize(&argc, argv);
  benchmark::RunSpecifiedBenchmarks();
  return 0;
}
