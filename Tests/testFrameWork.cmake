
if(${USE_UNITY})

    if(NOT TARGET unity)
        message(STATUS "Unity test framework selected.")

        set(UNITY_EXTENSION_FIXTURE ON CACHE BOOL "enable extension fixtures")
        set(UNITY_EXTENSION_MEMORY ON CACHE BOOL "enable extension memory")

        add_subdirectory(
            ${CMAKE_CURRENT_SOURCE_DIR}/../../Unity
            ${CMAKE_CURRENT_SOURCE_DIR}/build/Uinty
            EXCLUDE_FROM_ALL
        )
    endif()

    set(UNITY_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Unity/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Unity/extras/fixture/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Unity/extras/memory/src
    )

else()

    if(NOT TARGET CppUTest)
        if(${USE_CPP_U_TEST})
            message(STATUS "CppUtest test framework selected.")
        else()
            message(STATUS "No test framework selected, defaulting to CppUtest.")
        endif()
    
        add_subdirectory(
            ${CMAKE_CURRENT_SOURCE_DIR}/../../cpputest
            ${CMAKE_CURRENT_SOURCE_DIR}/build/cpputest
            EXCLUDE_FROM_ALL
        )
    endif()

    set(CPP_UTEST_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/../../cpputest/include
    )
    
endif()