set(OBJECT_NAME branchengine)
set(OBJECT_SRC_FILE
    ${CMAKE_CURRENT_SOURCE_DIR}/engine.cpp
)

add_library(${OBJECT_NAME} OBJECT ${OBJECT_SRC_FILE})
