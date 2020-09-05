project(EulerPlayground)

cmake_minimum_required(VERSION 3.17)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
add_test(
        NAME unit-test
        COMMAND tests
)
