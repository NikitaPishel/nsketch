#!/bin/bash
set -e  # Exit on any error

# Variables
BUILD_DIR="./build"
SOURCE_DIR="."
BUILD_TESTS="${TESTS:-ON}"
AUTO_TEST="${AUTO_TEST:-OFF}"

# Create build directory if it doesn't exist
mkdir -p "$BUILD_DIR"

# Configure CMake and build the project
cmake -B "$BUILD_DIR" -S "$SOURCE_DIR" -DBUILD_TESTS=$BUILD_TESTS
cmake --build "$BUILD_DIR"

# Run tests automatically if AUTO_TESTS is true
if [ "$AUTO_TEST" = "ON" ] && [ "$BUILD_TESTS" = "ON" ]; then
    cd "$BUILD_DIR"
    ctest --output-on-failure
fi
