cmake_minimum_required(VERSION 3.0.0)

SET (PROJECT_NAME "MATH_LIB")

SET (PROJECT_VERSION "0.1.0")

#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})


enable_testing()


add_subdirectory (library)

add_subdirectory (test)

add_subdirectory (examples)


