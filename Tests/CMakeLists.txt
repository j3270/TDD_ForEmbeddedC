cmake_minimum_required(VERSION 3.7.0)
project(Tests VERSION 0.1.0)

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    include(CTest)
    enable_testing()
    
    option(USE_UNITY "Test built with Unity test framework if set." OFF)
    option(USE_CPPUTEST "Test built with CppUtest test framework if set." OFF)

    include(./testFrameWork.cmake)
    add_test_framework()   
endif()

add_subdirectory(
    stdio
    ${CMAKE_SOURCE_DIR}/build/stdio
)
add_subdirectory(
    Drivers/LedDriver
    ${CMAKE_SOURCE_DIR}/build/Drivers/LedDriver
)
add_subdirectory(
    Utils/Random
    ${CMAKE_SOURCE_DIR}/build/Utils/Random
)
add_subdirectory(
    Utils/CircularBuffer
    ${CMAKE_SOURCE_DIR}/build/Utils/CircularBuffer
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
