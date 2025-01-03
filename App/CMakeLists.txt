cmake_minimum_required(VERSION 3.0)

project(NetworkApp VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include_directories(home/admin/CLionProjects/test/Library/NetworkLib/include)


add_executable(NetworkApp main.cpp)

add_library(NetworkLib SHARED IMPORTED)
set_target_properties(NetworkLib PROPERTIES IMPORTED_LOCATION /home/admin/CLionProjects/test/Library/NetworkLib/build/NetworkLib.a)

target_link_libraries(NetworkApp PRIVATE NetworkLib)
#target_link_libraries(NetworkApp PRIVATE /home/admin/CLionProjects/test/Library/NetworkLib/build/NetworkLib.a)

#Can use link_directories as well 
