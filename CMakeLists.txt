cmake_minimum_required(VERSION 3.26.3)

project(opengl-cpp
    VERSION 0.1.0
    # LANGUAGES CXX
    # DESCRIPTION "Learning OpenGL in C++"
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
add_subdirectory(external/glad)

# glfw options
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} PUBLIC
    external/glad/include
    external/glfw/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE glad glfw OpenGL::GL)

