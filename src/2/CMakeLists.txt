
add_library(fib fibonacci.hpp fibonacci.cpp)

add_executable(tst-fib fibonacci.test.cpp)
target_link_libraries(tst-fib fib test_main)

add_executable(eu2 main.cpp)
target_link_libraries(eu2 fib)
