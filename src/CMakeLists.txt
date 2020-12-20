
set(TEST_MAIN ${PROJECT_SOURCE_DIR}/src/test_main.cpp)
add_library(test_main STATIC test_main.cpp)
target_link_libraries(test_main PUBLIC pthread gtest)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)

add_subdirectory(primes)
add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(21)
add_subdirectory(22)
add_subdirectory(209)
add_subdirectory(700)
add_subdirectory(719)
add_subdirectory(728)
add_subdirectory(735)

