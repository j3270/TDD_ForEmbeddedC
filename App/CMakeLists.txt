cmake_minimum_required(VERSION 3.7.0)
project(App VERSION 0.1.0)


set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/HelloWorld.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../Utils/CircularBuffer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../Utils/Random.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../Utils/RuntimeError.c
)

set(INCLUDE_DIRS 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Utils
)

set(EXECUTABLE App)
add_executable(${EXECUTABLE} ${SOURCES})

target_include_directories(${EXECUTABLE} PRIVATE ${INCLUDE_DIRS})

target_compile_definitions(${EXECUTABLE} PRIVATE ${DEFINES})
