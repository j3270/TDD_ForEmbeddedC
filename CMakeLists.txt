cmake_minimum_required(VERSION 3.7.0)
project(MyProject VERSION 0.1.0)

include(CTest)
enable_testing()

#set(CMAKE_C_STANDARD 99)
#set(CMAKE_CXX_STANDARD 14)

add_subdirectory(App)
add_subdirectory(Tests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
                                                              