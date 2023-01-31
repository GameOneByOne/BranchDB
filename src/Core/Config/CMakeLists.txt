set(OBJECT_NAME branchconfig)
set(OBJECT_SRC_FILE
    ${CMAKE_CURRENT_SOURCE_DIR}/config.cpp
)

add_library(${OBJECT_NAME} OBJECT ${OBJECT_SRC_FILE})
