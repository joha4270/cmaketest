cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 14)
project(dependency)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library(liba liba.cpp)
target_include_directories(liba
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

install(FILES include/liba.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

add_library(libb libb.cpp)
target_include_directories(libb
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

install(FILES include/libb.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
target_link_libraries(libb PRIVATE liba)



install(TARGETS libb
        EXPORT libtargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        )

install(TARGETS liba
        EXPORT libtargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        )

install(EXPORT libtargets
        FILE dependency.cmake
        NAMESPACE Dependency::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dependency
        )

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
        "${CMAKE_CURRENT_BINARY_DIR}/dependencyConfig.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dependency
        )

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/dependencyConfig.cmake"

        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dependency
        )