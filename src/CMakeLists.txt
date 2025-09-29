file(GLOB_RECURSE SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

# Exclude main file as it won't be used in tests
list(REMOVE_ITEM SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

# Create a library of the core app 
add_library(nsketch_lib STATIC
    ${SRC_FILES}
)

# Set the public include directories for the library.
target_include_directories(nsketch_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

# The main executable links to the library.
add_executable(nsketch "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
target_link_libraries(nsketch PRIVATE nsketch_lib)