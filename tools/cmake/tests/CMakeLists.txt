cmake_minimum_required(VERSION 3.28.1)
project(tests VERSION 0.1.0)

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    include(CTest)
    enable_testing()
    
    option(USE_UNITY "Test built with Unity test framework if set." OFF)
    option(USE_CPPUTEST "Test built with CppUtest test framework if set." OFF)

    include(./testFrameWork.cmake)
    add_test_framework()   
endif()

add_subdirectory(
    app
    ${CMAKE_SOURCE_DIR}/build/app
)

add_subdirectory(
    drivers
    ${CMAKE_SOURCE_DIR}/build/drivers
)

add_subdirectory(
    utils
    ${CMAKE_SOURCE_DIR}/build/utils
)
