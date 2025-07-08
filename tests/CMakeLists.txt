add_executable(testAll testGph.cpp)

# Link GoogleTest libraries (assuming gtest is installed)
find_package(GTest REQUIRED)
target_link_libraries(testAll GTest::gtest_main)

# Register test with CTest
add_test(NAME testAll COMMAND testAll)