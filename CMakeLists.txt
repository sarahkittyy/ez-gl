cmake_minimum_required(VERSION 3.13)
project(EZ-GL)

option(BUILD_DEBUG "Build the debug binaries" OFF)
option(BUILD_TESTS "Build the ez-gl tests" OFF)

add_compile_options(-Wall)
if(BUILD_DEBUG)
	add_compile_options(-g)
endif()

set(CMAKE_CXX_STANDARD 17)
set(BUILD_SHARED_LIBS ON)
set(BUILD_STATIC_LIBS OFF)

# GLFW options
set(GLFW_INSTALL OFF)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
add_subdirectory("lib/glfw")

# GLM options
set(GLM_TEST_ENABLE_CXX_17 ON)
set(GLM_TEST_ENABLE OFF)
set(GLM_TEST_)
add_subdirectory("lib/glm")
 
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_library(GLFW REQUIRED)

if(BUILD_TESTS)
	add_subdirectory("test")
endif()

# compile sources
file(GLOB_RECURSE sources "src/*.cpp")
add_library(ezgl ${sources})
add_dependencies(ezgl glm_shared glfw)
target_include_directories(ezgl PUBLIC "include" "lib/glfw/include" "lib/glm")
target_link_libraries(ezgl GL glfw GLEW glm_shared)