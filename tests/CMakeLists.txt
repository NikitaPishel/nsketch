# Executable for sketch tests
add_executable(sketchTest sketchTest.cpp)
target_include_directories(sketchTest PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/include
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
    ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(toolTest PRIVATE
    nsketch_lib
    GTest::gtest_main
)

add_test(NAME toolTest COMMAND toolTest)