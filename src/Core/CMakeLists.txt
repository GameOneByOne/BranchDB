add_subdirectory(Engine)
add_subdirectory(Net)

set(LIBRARY_NAME brachcore)
set(LIBRARY_SRC_FILE
    $<TARGET_OBJECTS:branchengine>
    $<TARGET_OBJECTS:branchnet>
)

add_library(${LIBRARY_NAME} SHARED ${LIBRARY_SRC_FILE})

install(TARGETS ${LIBRARY_NAME} LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/output)
