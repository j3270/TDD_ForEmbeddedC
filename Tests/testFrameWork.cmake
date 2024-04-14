
function(add_test_framework)
    if(${USE_UNITY})
        if (NOT DEFINED ENV{UNITY_HOME})
	        message(FATAL_ERROR "UNITY_HOME environment variable is not defined!")
        else()
            message(STATUS "UNITY_HOME = $ENV{UNITY_HOME}")
        endif()

        set(UNITY_EXTENSION_FIXTURE ON CACHE BOOL "enable extension fixtures")
        set(UNITY_EXTENSION_MEMORY ON CACHE BOOL "enable extension memory")

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
        if (NOT DEFINED ENV{CPPUTEST_HOME})
            message(FATAL_ERROR "CPPUTEST_HOME environment variable is not defined!")
        else()
            message(STATUS "CPPUTEST_HOME = $ENV{CPPUTEST_HOME}")
        endif()

        # Out of tree builds must provide a build dir
        add_subdirectory(
            $ENV{CPPUTEST_HOME}/
            ${CMAKE_SOURCE_DIR}/build/CppUtest
        )
        set(TEST_FRAMEWORK_INCLUDES $ENV{CPPUTEST_HOME}/include PARENT_SCOPE)
    endif()
endfunction()