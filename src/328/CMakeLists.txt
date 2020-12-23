
add_library(lib-328 strategy.cpp strategy.hpp distance_finder.cpp distance_finder.hpp)

add_executable(tst-328 strategy.test.cpp distance_finder.test.cpp)
target_link_libraries(tst-328 lib-328 test_main)
add_test(NAME tst-328 COMMAND tst-328)
