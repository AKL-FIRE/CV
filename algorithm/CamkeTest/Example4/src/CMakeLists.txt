set(SRC_LIST main.c)
include_directories(${PROJECT_SOURCE_DIR}/libhello)
add_executable(main ${SRC_LIST})
target_link_libraries(main libhello)
