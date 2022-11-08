cmake_minimum_required(VERSION 3.23)
project(FlappyBird)

set(CMAKE_CXX_STANDARD 23)

include_directories(lib/glad/include)
include_directories(lib/glfw/include)
include_directories(lib/glm/glm)
include_directories(src)

add_subdirectory(lib/glfw)
add_subdirectory(lib/glad)

add_executable(FlappyBird main.cpp src/Graphics/Graphics.cpp src/Graphics/Graphics.hpp src/Graphics/Cords.hpp src/Graphics/Rendering.cpp)

target_link_libraries(FlappyBird glfw glad)