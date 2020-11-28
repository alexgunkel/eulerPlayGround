
add_library(eu735l STATIC sieve.hpp sieve.cpp solver.hpp solver.cpp)
target_link_libraries(eu735l PUBLIC tbb)

add_executable(eu735 main.cpp)
target_link_libraries(eu735 eu735l)

add_executable(tst-735 ${TEST_MAIN} sieve.test.cpp solver.test.cpp)
target_link_libraries(tst-735 pthread gtest eu735l)
add_dependencies(tst-735 googletest_ep)

find_package(benchmark REQUIRED)
add_executable(bm-735 solver.bench.cpp sieve.bench.cpp)
target_link_libraries(bm-735 eu735l benchmark::benchmark_main)
