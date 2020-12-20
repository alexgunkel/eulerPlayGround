
set(SRC_PATH_22 ${CMAKE_CURRENT_SOURCE_DIR}/p022_names.txt)
configure_file(config.22.h.in config.22.h)
add_library(lib-22 names.cpp names.hpp)

add_executable(tst-22 name.test.cpp)
target_include_directories(tst-22 PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(tst-22 PRIVATE lib-22 test_main)
add_test(NAME tst-22 COMMAND tst-22)
