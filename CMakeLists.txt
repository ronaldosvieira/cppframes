#cmake_minimum_required(VERSION 2.8)

#project(cppframes)

#set(CMAKE_BUILD_TYPE Debug)

#set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(EXT_PROJECTS_DIR ${CMAKE_SOURCE_DIR}/ext)
#set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

##add_compile_options(-std=gnu++11)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#include_directories("${PROJECT_SOURCE_DIR}/include")
##file(GLOB SOURCES "src/*.cpp")
#file(GLOB TEST_SOURCES "src/*.cpp" "test/*.hpp" "test/*.h")
##add_library(cppframes STATIC ${SOURCES})

## Includes Catch in the project:
#add_subdirectory(${EXT_PROJECTS_DIR}/catch)
#include_directories(${CATCH_INCLUDE_DIR} ${COMMON_INCLUDES})
#enable_testing(true)  # Enables unit-testing.

#add_executable(cppframes-test ${CMAKE_SOURCE_DIR}/test/catch.hpp ${TEST_SOURCES})

project(cppframes-test)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

include_directories(include)

file(GLOB SOURCES "include/*" "test/*") #"src/*")
add_executable(${PROJECT_NAME} ${SOURCES})
