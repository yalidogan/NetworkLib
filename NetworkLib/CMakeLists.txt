cmake_minimum_required(VERSION 3.0)

project(NetworkLib) 

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)


file(GLOB SOURCES "src/*.cpp")

add_library(NetworkLib STATIC ${SOURCES})


#Set it to include the correct source files for the library target 
target_include_directories(NetworkLib PUBLIC "${PROJECT_SOURCE_DIR}/include")