cmake_minimum_required(VERSION 3.29)
project(SDL3_HELPER)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL3 REQUIRED)

add_subdirectory(SDL_image)

add_subdirectory(src)