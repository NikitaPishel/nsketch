# Add the texture creator executable
add_executable(textureBuild ./interface.cpp)

# Link the texture creator to your texture library
target_link_libraries(textureBuild PRIVATE ngph)