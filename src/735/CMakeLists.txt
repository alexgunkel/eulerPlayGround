
add_library(lib-735 STATIC sieve.hpp sieve.cpp solver.hpp solver.cpp analyzer.hpp analyzer.cpp exponential_explorer.hpp exponential_explorer.cpp)
target_include_directories(lib-735 PUBLIC ${LIB_includes})
target_link_libraries(lib-735 PUBLIC tbb)

add_executable(run-735 main.cpp)
target_link_libraries(run-735 lib-735 ${LIB_link})

add_executable(tst-735 ${TEST_MAIN} sieve.test.cpp solver.test.cpp analyzer.test.cpp exponential_explorer.test.cpp)
target_link_libraries(tst-735 pthread gtest lib-735)
add_dependencies(tst-735 googletest_ep)

find_package(benchmark REQUIRED)
add_executable(bm-735 sieve.bench.cpp solver.bench.cpp)
target_link_libraries(bm-735 lib-735 benchmark::benchmark_main)
