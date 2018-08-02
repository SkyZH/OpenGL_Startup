cmake_minimum_required (VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)
project (GLTest)
# The version number.
set (GLTest_VERSION_MAJOR 1)
set (GLTest_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/src/GLTestConfig.h.in"
  "${PROJECT_BINARY_DIR}/GLTestConfig.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add the executable
add_executable(GLTest src/main.cpp)

# libraries
find_package(GLEW REQUIRED)
target_link_libraries(GLTest PRIVATE GLEW::GLEW)
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(GLTest PRIVATE glfw)
