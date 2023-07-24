cmake_minimum_required(VERSION 3.10)
project(google-benchmark)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

include_directories(include)
add_library(link_list
  ./src/link_list.cpp
)

add_subdirectory(test)
