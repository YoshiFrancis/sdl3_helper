cmake_minimum_required(VERSION 3.29) 
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main new_main.cpp)

set(LIBS)
list(APPEND LIBS sdl::sdl)
list(APPEND LIBS SDL3_image::SDL3_image)

add_library(sdl3_helper STATIC Transform.cpp Texture.cpp structs.cpp test.cpp test_main.cpp)
target_link_libraries(sdl3_helper PRIVATE ${LIBS})

target_include_directories(sdl3_helper PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(main PUBLIC sdl3_helper)
