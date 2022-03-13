cmake_minimum_required(VERSION 3.22)
project(cmaketest)

include(ExternalProject)

ExternalProject_Add(
    dependency
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependency
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/install/dependency
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
)

ExternalProject_Add(
        main
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/main
        DEPENDS dependency
        CMAKE_ARGS -DCMAKE_PREFIX_PATH=${CMAKE_CURRENT_BINARY_DIR}/install
                   -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
)