
add_executable(tst-2 fibonacci.test.cpp)
target_link_libraries(tst-2 test_main)
target_include_directories(tst-2 PRIVATE ${LIB_includes})

add_executable(run-2 main.cpp)
target_include_directories(run-2 PRIVATE ${LIB_includes})
