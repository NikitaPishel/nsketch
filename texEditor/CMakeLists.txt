# Dark theme builder
add_executable(textureBuildDark ./interfaceLight.cpp)
target_link_libraries(textureBuildDark PRIVATE ngph)

# Light theme builder
add_executable(textureBuildLight ./interfaceDark.cpp)
target_link_libraries(textureBuildLight PRIVATE ngph)