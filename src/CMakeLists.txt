cmake_minimum_required(VERSION 3.20.0)
project(math)

set(CMAKE_C_STANDARD 11)
include_directories(${CMAKE_SOURCE_DIR}/include/)

add_subdirectory(include)
 
add_executable(main.c)

target_link_libraries(${PROJECT_NAME} include)