
add_library(multiples-sum multiples_sum.hpp multiples_sum.cpp)

add_executable(tst-multiples multiples_sum.test.cpp)
target_link_libraries(tst-multiples test_main multiples-sum)

add_executable(1 main.cpp)
target_link_libraries(1 multiples-sum)

add_test(tst-multiples tst)

add_test(
        NAME tst-1-multiples
        COMMAND tst-multiples
)