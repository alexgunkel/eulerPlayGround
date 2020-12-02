
add_library(palindrome palindrome_product.hpp palindrome_product.cpp)

add_executable(tst-4 palindrome.test.cpp)
target_link_libraries(tst-4 palindrome test_main)
