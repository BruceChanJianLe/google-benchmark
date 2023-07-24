#include <benchmark/benchmark.h>
#include <string>
#include <vector>


static void stringBench(benchmark::State &s)
{
  // Extract the string size
  int len = s.range(0);

  // Create a vector to store our strings
  std::vector<std::string> v;
  v.reserve(10000);

  // Run the benchmark
  for (auto _ : s)
  {
    for (int i = 0; i < 1000; ++i)
    {
      std::string str(len, 'x');
      v.push_back(str);
    }
  }
}

// Register the benchmark
BENCHMARK(stringBench)->DenseRange(0, 32)->Unit(benchmark::kMillisecond);

// Run main
BENCHMARK_MAIN();
