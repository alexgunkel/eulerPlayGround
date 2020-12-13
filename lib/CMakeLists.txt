

add_library(eulib STATIC src/modulo.cpp src/gcd.cpp)
target_include_directories(eulib PUBLIC ${LIB_includes})

add_executable(tst-libs test/gcd.test.cpp test/modulo.test.cpp test/primes.test.cpp)
target_include_directories(tst-libs PUBLIC ${LIB_includes})
target_link_libraries(tst-libs test_main eulib)

find_package(benchmark REQUIRED)
add_executable(bm-libs test/module.bench.cpp test/primes.bench.cpp)
target_include_directories(bm-libs PUBLIC ${LIB_includes})
target_link_libraries(bm-libs eulib benchmark::benchmark_main)

add_executable(lib-playground main.cpp)
target_include_directories(lib-playground PUBLIC ${LIB_includes})
target_link_libraries(lib-playground test_main eulib)
