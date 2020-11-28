project(EulerPlayground)

cmake_minimum_required(VERSION 3.17)
include(cmake/gtest.cmake)

enable_testing()

add_subdirectory(src)
