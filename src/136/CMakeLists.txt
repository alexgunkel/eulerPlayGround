
add_library(lib-136 solution.cpp solution.hpp)

add_executable(tst-136 solution.test.cpp)
target_link_libraries(tst-136 PRIVATE lib-136 test_main)
add_test(NAME tst-136 COMMAND tst-136)
