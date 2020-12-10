
add_library(circleOfCoins circle_of_coins.cpp circle_of_coins.hpp)
target_include_directories(circleOfCoins PUBLIC ${LIB_includes})
target_link_libraries(circleOfCoins PUBLIC ${LIB_link})

add_executable(tst-728 circle.test.cpp)
target_link_libraries(tst-728 circleOfCoins test_main)
add_test(
        NAME tst-728-coin-flipping
        COMMAND tst-728
)

add_executable(run-728 main.cpp)
target_link_libraries(run-728 circleOfCoins)

find_package(benchmark REQUIRED)
add_executable(bm-728 circle.bench.cpp)
target_link_libraries(bm-728 circleOfCoins benchmark::benchmark_main)
