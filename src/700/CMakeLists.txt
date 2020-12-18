
add_library(lib-700 STATIC euler_coin.cpp euler_coin.hpp)
target_link_libraries(lib-700 PUBLIC ${LIB_link})
target_include_directories(lib-700 PUBLIC ${LIB_includes})

add_executable(run-700 main.cpp)
target_link_libraries(run-700 lib-700)

add_executable(tst-700 euler_coin.test.cpp)
target_link_libraries(tst-700 PRIVATE lib-700 test_main)
add_test(
        NAME tst-700-euler_coin
        COMMAND tst-700
)

