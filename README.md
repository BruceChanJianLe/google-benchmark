# Google Benchmark

This repository is me trying to use google-benchmark :D

If you are looking for a template cpp project with google benchmark, check [this](https://github.com/BruceChanJianLe/cpp-benchmark) out!

For more details, please visit the office github repo (https://github.com/google/benchmark).

## Installing

```bash
sudo apt install libbenchmark-dev
```

Ref: https://www.howtoinstall.me/ubuntu/18-04/libbenchmark-dev/

## Setting up cmake

```cmake
find_package(benchmark REQUIRED)

add_executable(some_library_perf
  ./perf/some_library_perf.cpp
)
target_link_libraries(some_library_perf
  PRIVATE
  benchmark::benchmark
)
```

Ref: https://stackoverflow.com/questions/58807225/google-benchmark-as-a-cmake-dependency

## Compiling

```bash
git clone https://github.com/BruceChanJianLe/google-benchmark
cd google-benchmark
mkdir build
cmake -S . -B build
cmake --build build
```


## Running

```bash
# Run all tests
./build/test/some_library_perf
# Run selected test
./build/test/some_library_perf --benchmark_filter=stringBench/15
# Run selected test with min test requirement
./build/test/some_library_perf --benchmark_filter=stringBench/15 --benchmark_min_time=3
```

## Usage

### Linking Against Custom Main

```cpp
...
// After defining your benchmark
// Create your main like so
int main(int argc, char** argv)
{
   your_custom_init();
   ::benchmark::Initialize(&argc, argv);
   ::benchmark::RunSpecifiedBenchmarks();
}
```

Ref: https://stackoverflow.com/questions/34401965/google-benchmark-custom-main
