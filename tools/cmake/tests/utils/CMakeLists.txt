cmake_minimum_required(VERSION 3.28.1)
project(utils_tests VERSION 0.1.0)

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    include(CTest)
    enable_testing()
    
    option(USE_UNITY "Test built with Unity test framework if set." OFF)
    option(USE_CPPUTEST "Test built with CppUtest test framework if set." OFF)

    include(./../../testFrameWork.cmake)
    add_test_framework()   
endif()

if(${USE_UNITY})
    #sources for this test w/Unity
    set(SOURCES
    )

    #includes for this test w/Unity
    set(INCLUDE_DIRS 
        ${TEST_FRAMEWORK_INCLUDES}
    )
else()
    #sources for this test w/CppUtest
    set(SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../src/utils/CircularBuffer.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../src/utils/Random.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../tests/utils/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../tests/utils/CircularBufferTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../tests/utils/RandomTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../tests/mocks/RuntimeErrorStub.c
    )
    
    #includes for this test w/CppUtest
    set(INCLUDE_DIRS 
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../src/utils/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../tests/mocks/include
    )
endif()

set(INCLUDE_DIRS 
    ${INCLUDE_DIRS}
    ${TEST_FRAMEWORK_INCLUDES}
)

set(EXECUTABLE ${PROJECT_NAME})
add_executable(${EXECUTABLE} ${SOURCES})

target_include_directories(${EXECUTABLE} PRIVATE ${INCLUDE_DIRS})

target_compile_definitions(${EXECUTABLE} PRIVATE ${DEFINES})

target_compile_options(${EXECUTABLE} PRIVATE --coverage)

if(${USE_UNITY})
    target_link_libraries(${EXECUTABLE} 
        gcov 
        $<TARGET_FILE:unity>
    )
else()
    target_link_libraries(${EXECUTABLE}
        gcov 
        $<TARGET_FILE:CppUTest> 
        $<TARGET_FILE:CppUTestExt>
    )
endif()

if(${USE_UNITY})
    target_link_libraries(${EXECUTABLE} $<TARGET_FILE:unity>)
else()
    target_link_libraries(${EXECUTABLE} $<TARGET_FILE:CppUTest>)
endif()

add_test(
    NAME ${PROJECT_NAME} 
    COMMAND $<TARGET_FILE:${PROJECT_NAME}> "-v")
