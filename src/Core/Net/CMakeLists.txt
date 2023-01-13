set(OBJECT_NAME branchnet)
set(OBJECT_SRC_FILE
    ${CMAKE_CURRENT_SOURCE_DIR}/netComm.cpp
)

add_library(${OBJECT_NAME} OBJECT ${OBJECT_SRC_FILE})
