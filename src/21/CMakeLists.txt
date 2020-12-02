
add_library(21 palindrome_sums.hpp palindrome_sums.cpp)

add_executable(tst-21 palindrome_sum.test.cpp)
target_link_libraries(tst-21 21 test_main)
