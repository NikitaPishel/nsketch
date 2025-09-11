cmake_minimum_required(VERSION 3.14)
project(nsketch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)

# Create a library of the core app 
add_library(nsketch_lib STATIC
    ./src/graphics/grid.cpp
    ./src/graphics/texture.cpp
    ./src/graphics/canvas.cpp
    ./src/graphics/iotex.cpp
    ./src/graphics/gphUtil.cpp
    ./src/sketch/sketch.cpp
    ./src/tools/tools.cpp
)

# Set the public include directories for the library.
target_include_directories(nsketch_lib PUBLIC
    ./include
)

# The main executable links to the library.
add_executable(nsketch ./src/main.cpp)
target_link_libraries(nsketch PRIVATE nsketch_lib)

# Option to enable tests (OFF by default)
option(BUILD_TESTS "Build unit tests" ON)

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