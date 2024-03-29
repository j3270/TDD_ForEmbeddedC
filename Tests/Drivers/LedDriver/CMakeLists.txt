cmake_minimum_required(VERSION 3.7.0)
project(LedDriverTest VERSION 0.1.0)

include(CTest)
enable_testing()

option(USE_UNITY "Test built with Unity test framework if set." OFF)
option(USE_CPP_U_TEST "Test built with CppUtest test framework if set." OFF)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../testFrameWork.cmake)

if(${USE_UNITY})

    build_test_framework(${CMAKE_CURRENT_SOURCE_DIR}/../../../Unity)

    #sources for this test w/Unity
    set(SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../Drivers/LedDriver.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Mocks/RuntimeErrorStub.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Unity/main.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Unity/LedDriverTest.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Unity/LedDriverTestRunner.c
    )

    #includes for this test w/Unity
    set(INCLUDE_DIRS 
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../Drivers
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../Utils
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Mocks
        ${TEST_FRAMEWORK_INCLUDES}
    )

else()

    build_test_framework(${CMAKE_CURRENT_SOURCE_DIR}/../../../cpputest)

    #sources for this test w/CppUtest
    set(SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../Drivers/LedDriver.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Mocks/RuntimeErrorStub.c
        ${CMAKE_CURRENT_SOURCE_DIR}/CppUtest/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/CppUtest/LedDriverTest.cpp
    )
    
    #includes for this test w/CppUtest
    set(INCLUDE_DIRS 
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../Drivers
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../Utils
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Mocks
        ${TEST_FRAMEWORK_INCLUDES}
    )

endif()

set(EXECUTABLE LedDriverTest)
add_executable(${EXECUTABLE} ${SOURCES})

target_include_directories(${EXECUTABLE} PRIVATE ${INCLUDE_DIRS})

target_compile_definitions(${EXECUTABLE} PRIVATE ${DEFINES})

if(${USE_UNITY})
    target_link_libraries(${EXECUTABLE} $<TARGET_FILE:unity>)
else()
    target_link_libraries(${EXECUTABLE} $<TARGET_FILE:CppUTest>)
endif()


add_test(
    NAME "LedDriverTest" 
    COMMAND $<TARGET_FILE:LedDriverTest> "-v")
