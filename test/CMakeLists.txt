find_package(benchmark REQUIRED)

add_executable(benchmark_link_list
  ./perf/benchmark_link_list.cpp
)
target_link_libraries(benchmark_link_list
  PRIVATE
  benchmark::benchmark
  link_list
)

add_executable(benchmark_example
  ./perf/benchmark_example.cpp
)
target_link_libraries(benchmark_example
  PRIVATE
  benchmark::benchmark
)
