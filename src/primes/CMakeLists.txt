
add_library(primes generator.h generator.cpp)

add_executable(greatestprime greates.cpp)
target_link_libraries(greatestprime primes)

add_executable(tst-primes ${TEST_MAIN} generator.test.cpp)
target_link_libraries(tst-primes PRIVATE primes pthread gtest)
add_test(tst-primes tst-primes)

find_package(benchmark REQUIRED)
add_executable(bm-primes generator.bench.cpp)
target_link_libraries(bm-primes benchmark::benchmark_main primes)
