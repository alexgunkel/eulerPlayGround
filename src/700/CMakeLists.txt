
add_library(lib-700 STATIC euler_coin.cpp euler_coin.hpp)
target_include_directories(lib-700 PUBLIC ${LIB_includes})

add_executable(run-700 main.cpp)
target_link_libraries(run-700 lib-700 ${LIB_link})
