cmake_minimum_required(VERSION 3.0.0)

SET (PROJECT_NAME "math_lib")
SET (PROJECT_VERSION "0.1.0")


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")


project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

#include(CTest)
#enable_testing()

file(GLOB SOURCES
    *.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

