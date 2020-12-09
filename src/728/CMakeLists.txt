
add_library(circleOfCoins circle_of_coins.cpp circle_of_coins.hpp)
target_include_directories(circleOfCoins PUBLIC ${LIB_includes})

add_executable(tst-728 circle.test.cpp)
target_link_libraries(tst-728 circleOfCoins test_main)

add_executable(run-728 main.cpp)
target_link_libraries(run-728 circleOfCoins)
