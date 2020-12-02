
add_library(primefac prime_factorizer.h prime_factorizer.cpp)

add_executable(tst-primefac prime_factorizer.test.cpp)
target_link_libraries(tst-primefac primefac test_main)
