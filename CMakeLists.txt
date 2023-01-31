cmake_minimum_required(VERSION 3.16)

project(BranchDB)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAG -fPIC -g)

add_subdirectory(src)

add_executable(BranchDB main.cpp)
install(TARGETS BranchDB RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/output)
