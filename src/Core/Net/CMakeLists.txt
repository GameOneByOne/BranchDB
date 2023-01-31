set(OBJECT_NAME branchnet)
set(OBJECT_SRC_FILE
    ${CMAKE_CURRENT_SOURCE_DIR}/netServer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/netClient.cpp
)

include_directories(
    ${PROJECT_SOURCE_DIR}/src/Core/
)

add_compile_options(${CMAKE_CXX_FLAG}) 

add_library(${OBJECT_NAME} OBJECT ${OBJECT_SRC_FILE})
