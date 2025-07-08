cmake_minimum_required(VERSION 3.10)
project(nsketch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)

# Main executable
add_executable(nsketch ./src/main.cpp)

# Option to enable tests (OFF by default)
option(BUILD_TESTS "Build unit tests" OFF)

if(BUILD_TESTS)
    enable_testing()

    # Add test subdirectory (tests folder must contain its own CMakeLists.txt)
    add_subdirectory(tests)
endif()
