
function(add_test_framework)
    if(${USE_UNITY})
        # Out of tree builds must provide a build dir
        add_subdirectory(
            $ENV{UNITY_HOME}
            ${CMAKE_SOURCE_DIR}/build/Unity
        )
        set(TEST_FRAMEWORK_INCLUDES
            $ENV{UNITY_HOME}/src
            $ENV{UNITY_HOME}/extras/fixture/src
            $ENV{UNITY_HOME}/extras/memory/src
            PARENT_SCOPE
        )
    else()
        # Out of tree builds must provide a build dir
        add_subdirectory(
            $ENV{CPPUTEST_HOME}/
            ${CMAKE_SOURCE_DIR}/build/CppUtest
        )
        set(TEST_FRAMEWORK_INCLUDES $ENV{CPPUTEST_HOME}/include PARENT_SCOPE)
    endif()
endfunction()