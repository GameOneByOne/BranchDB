cmake_minimum_required(VERSION 3.16)

project(BranchDB)

set(CMAKE_CXX_COMPILER g++)

add_executable(BranchDB main.cpp)

install(TARGETS BranchDB RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/output)
