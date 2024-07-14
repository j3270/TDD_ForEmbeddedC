cmake_minimum_required(VERSION 3.28.1)
project(App VERSION 0.1.0)


set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/app/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/app/RandomHelloWorld.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/utils/CircularBuffer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/utils/Random.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/utils/RuntimeError.c
)

set(INCLUDE_DIRS 
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/app/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/utils/include
)

set(EXECUTABLE App)
add_executable(${EXECUTABLE} ${SOURCES})

target_include_directories(${EXECUTABLE} PRIVATE ${INCLUDE_DIRS})

target_compile_definitions(${EXECUTABLE} PRIVATE ${DEFINES})
