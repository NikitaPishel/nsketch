add_executable(testAll gphTest.cpp sketchTest.cpp toolTest.cpp)

# Link GoogleTest libraries (assuming gtest is installed)
target_link_libraries(testAll PRIVATE GTest::gtest_main)

# Register test with CTest
add_test(NAME testAll COMMAND testAll)