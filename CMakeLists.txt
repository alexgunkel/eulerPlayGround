project(EulerPlayground)

cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)
include(cmake/gtest.cmake)

enable_testing()

set(LIB_includes ${CMAKE_SOURCE_DIR}/lib/include)
add_subdirectory(lib)

set(LIB_link eulib)

add_subdirectory(src)

