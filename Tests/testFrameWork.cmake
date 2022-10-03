
set(UNITY_INCLUDE_DIRS
${CMAKE_CURRENT_SOURCE_DIR}/../../../Unity/src
${CMAKE_CURRENT_SOURCE_DIR}/../../../Unity/extras/fixture/src
${CMAKE_CURRENT_SOURCE_DIR}/../../../Unity/extras/memory/src
)

set(UNITY_EXTENSION_FIXTURE ON CACHE BOOL "enable extension fixtures")
set(UNITY_EXTENSION_MEMORY ON CACHE BOOL "enable extension memory")
add_subdirectory(
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../Unity
    ${CMAKE_CURRENT_SOURCE_DIR}/build/Uinty
    EXCLUDE_FROM_ALL
)