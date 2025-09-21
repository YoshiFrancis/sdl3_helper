cmake_minimum_required(VERSION 3.29) 
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL3)

add_library(sdl3_helper STATIC test.cpp)

target_link_libraries(sdl3_helper PUBLIC sdl::sdl SDL3_image::SDL3_image)

target_include_directories(sdl3_helper PUBLIC ${PROJECT_SOURCE_DIR}/include)
