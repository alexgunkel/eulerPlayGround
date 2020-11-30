
set(TEST_MAIN ${PROJECT_SOURCE_DIR}/src/test_main.cpp)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)

add_subdirectory(primes)
add_subdirectory(719)
add_subdirectory(735)
