
add_executable(number_split number_splitting.cpp number_splitting.h number_string.cpp number_string.h)
target_link_libraries(number_split tbb)

add_executable(tst-719 ${TEST_MAIN} number_splitting_test.cpp number_string_test.cpp)
target_link_libraries(tst-719 gtest pthread)

add_test(
        NAME tst-719-number-splitting
        COMMAND tst-719
)

