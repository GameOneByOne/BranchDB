add_subdirectory(Engine)
add_subdirectory(Net)
add_subdirectory(Log)
add_subdirectory(Config)

set(LIBRARY_NAME branchcore)
set(LIBRARY_SRC_FILE
    $<TARGET_OBJECTS:branchconfig>
    $<TARGET_OBJECTS:branchnet>
    $<TARGET_OBJECTS:branchlog>
)

add_compile_options(${CMAKE_CXX_FLAG}) 

add_library(${LIBRARY_NAME} SHARED ${LIBRARY_SRC_FILE})

install(TARGETS ${LIBRARY_NAME} LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/output)
