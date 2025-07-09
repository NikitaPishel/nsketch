add_executable(testAll testGph.cpp)

# Link GoogleTest libraries (assuming gtest is installed)
target_link_libraries(testAll PRIVATE GTest::gtest_main)

# Register test with CTest
add_test(NAME testAll COMMAND testAll)