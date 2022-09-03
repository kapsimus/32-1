cmake_minimum_required(VERSION 3.22)
project(32_1)

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_executable(32_1 main.cpp include/Film.h src/Film.cpp)
add_subdirectory(nlohmann_json)
target_include_directories(32_1 PUBLIC include)

target_link_libraries(32_1 PRIVATE nlohmann_json::nlohmann_json)
