cmake_minimum_required(VERSION 3.7.0)
project(StdioTests VERSION 0.1.0)

include(CTest)
enable_testing()

option(USE_UNITY "Test built with Unity test framework if set." OFF)
option(USE_CPP_U_TEST "Test built with CppUtest test framework if set." OFF)

include(${CMAKE_CURRENT_SOURCE_DIR}/../testFrameWork.cmake)

if(${USE_UNITY})

    build_test_framework(${CMAKE_CURRENT_SOURCE_DIR}/../../Unity)

    #sources for this test w/Unity
    set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Unity/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Unity/SprintfTest.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Unity/SprintfTestRunner.c
    )

    #includes for this test w/Unity
    set(INCLUDE_DIRS 
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${TEST_FRAMEWORK_INCLUDES}
    )

else()

    build_test_framework(${CMAKE_CURRENT_SOURCE_DIR}/../../cpputest)

    #sources for this test w/CppUtest
    set(SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/CppUtest/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/CppUtest/SprintfTest.cpp
    )
    
    #includes for this test w/CppUtest
    set(INCLUDE_DIRS 
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${TEST_FRAMEWORK_INCLUDES}
    )

endif()

set(EXECUTABLE StdioTest)
add_executable(${EXECUTABLE} ${SOURCES})

target_include_directories(${EXECUTABLE} PRIVATE ${INCLUDE_DIRS})

target_compile_definitions(${EXECUTABLE} PRIVATE ${DEFINES})

if(${USE_UNITY})
    target_link_libraries(${EXECUTABLE} $<TARGET_FILE:unity>)
else()
    target_link_libraries(${EXECUTABLE} $<TARGET_FILE:CppUTest>)
endif()


add_test(
    NAME "StdioTest" 
    COMMAND $<TARGET_FILE:StdioTest> "-v")
