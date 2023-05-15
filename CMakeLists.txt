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

add_subdirectory(external/glad)
add_subdirectory(external/spdlog)

target_include_directories(${PROJECT_NAME} PUBLIC
    external/glad/include
    external/spdlog/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE glad glfw OpenGL::GL spdlog)

# # testing_start()
#
# # gtest
# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)
#
# enable_testing()
# include(GoogleTest)
#
# add_subdirectory(test)
# # testing_end()
