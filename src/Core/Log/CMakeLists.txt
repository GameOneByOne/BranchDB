set(OBJECT_NAME branchlog)
set(OBJECT_SRC_FILE
    ${CMAKE_CURRENT_SOURCE_DIR}/logger.cpp
)

add_compile_options(${CMAKE_CXX_FLAG}) 

add_library(${OBJECT_NAME} OBJECT ${OBJECT_SRC_FILE})
