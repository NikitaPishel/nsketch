# Executable for graphics tests
add_executable(gphTest gphTest.cpp)
target_include_directories(gphTest PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)
target_link_libraries(gphTest PRIVATE
    nsketch_lib
    GTest::gtest_main
)
add_test(NAME gphTest COMMAND gphTest)

# Executable for sketch tests
add_executable(sketchTest sketchTest.cpp)
target_include_directories(sketchTest PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)
target_link_libraries(sketchTest PRIVATE
    nsketch_lib
    GTest::gtest_main
)
add_test(NAME sketchTest COMMAND sketchTest)

# Executable for tool tests
add_executable(toolTest toolTest.cpp)
target_include_directories(toolTest PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)
target_link_libraries(toolTest PRIVATE
    nsketch_lib
    GTest::gtest_main
)

add_test(NAME toolTest COMMAND toolTest)