cmake_minimum_required(VERSION 3.14)
project(nsketch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)

# Main executable
add_executable(nsketch ./src/main.cpp)
target_include_directories(nsketch PRIVATE ./include)

# Option to enable tests (OFF by default)
option(BUILD_TESTS "Build unit tests" OFF)

if(BUILD_TESTS)
    include(FetchContent)
    enable_testing()

    # Download and unpack gtest
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
    )

    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    # Add test subdirectory (tests folder must contain its own CMakeLists.txt)
    add_subdirectory(tests)
endif()
