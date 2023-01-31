cmake_minimum_required(VERSION 3.16)

project(BranchDB)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAG -fPIC -g)

add_subdirectory(src)

include_directories(
    ${PROJECT_SOURCE_DIR}/src/
)

link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/output/
)
link_libraries(
    branchcore branchutils pthread
)

add_executable(BranchDB main.cpp)
install(TARGETS BranchDB RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/output)
