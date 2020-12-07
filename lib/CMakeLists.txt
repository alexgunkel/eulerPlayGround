
add_executable(tst-libs test/gcd.test.cpp)
target_include_directories(tst-libs PUBLIC ${LIB_includes})
target_link_libraries(tst-libs test_main)
