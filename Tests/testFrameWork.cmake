
function(build_test_framework arg_path_to_test_framework)

if(${USE_UNITY})

    message(STATUS "Unity test framework selected.")

    if(NOT TARGET unity)
        
        set(UNITY_EXTENSION_FIXTURE ON CACHE BOOL "enable extension fixtures")
        set(UNITY_EXTENSION_MEMORY ON CACHE BOOL "enable extension memory")

        add_subdirectory(
            ${arg_path_to_test_framework}
            ${CMAKE_SOURCE_DIR}/build/Unity
        )
    endif()

    #includes for framework
    set(TEST_FRAMEWORK_INCLUDES
        ${arg_path_to_test_framework}/src
        ${arg_path_to_test_framework}/extras/fixture/src
        ${arg_path_to_test_framework}/extras/memory/src
        PARENT_SCOPE
    )

else()

    if(${USE_CPP_U_TEST})
        message(STATUS "CppUtest test framework selected.")
    else()
        message(STATUS "No test framework selected, defaulting to CppUtest.")
    endif()

    if(NOT TARGET CppUTest)
        add_subdirectory(
            ${arg_path_to_test_framework}
            ${CMAKE_SOURCE_DIR}/build/CppUtest
        )
    endif()

    #includes for framework
    set(TEST_FRAMEWORK_INCLUDES ${arg_path_to_test_framework}/include PARENT_SCOPE)
    
endif()

endfunction()