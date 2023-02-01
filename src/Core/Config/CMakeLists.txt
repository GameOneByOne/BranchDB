set(OBJECT_NAME branchconfig)
set(OBJECT_SRC_FILE
    ${CMAKE_CURRENT_SOURCE_DIR}/config.cpp
)

include_directories(
    ${PROJECT_SOURCE_DIR}/src/
)

add_compile_options(${CMAKE_CXX_FLAG}) 

add_library(${OBJECT_NAME} OBJECT ${OBJECT_SRC_FILE})
