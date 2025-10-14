file(GLOB_RECURSE SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

# Exclude main file as it won't be used in tests
list(REMOVE_ITEM SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

# Create a library of the core app 
add_library(nsketch_lib STATIC
    ${SRC_FILES}
)

target_include_directories(nsketch_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

# The main executable links to the library.
add_executable(nsketch "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

# link ALL OBJECTS from nsketch lib to executable
target_link_libraries(nsketch PRIVATE
    -Wl,--whole-archive nsketch_lib -Wl,--no-whole-archive
)

set_target_properties(nsketch PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)