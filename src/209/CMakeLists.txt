
add_executable(run-209 main.cpp truth_table.hpp truth_table.cpp)
target_include_directories(run-209 PRIVATE ${LIB_includes})

add_executable(tst-209 truth_table.test.cpp truth_table.hpp truth_table.cpp)
target_link_libraries(tst-209 test_main)
