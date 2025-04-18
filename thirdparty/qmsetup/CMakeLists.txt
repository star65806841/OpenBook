cmake_minimum_required(VERSION 3.19)

project(qmsetup VERSION 0.0.2.1)

# ----------------------------------
# Configure Options
# ----------------------------------
option(QMSETUP_VCPKG_TOOLS_HINT "Install executables to tools directory" OFF)
option(QMSETUP_STATIC_RUNTIME "Static link runtime libraries on Windows" OFF)

# ----------------------------------
# CMake Settings
# ----------------------------------
if(NOT DEFINED CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

if(NOT DEFINED CMAKE_LIBRARY_OUTPUT_DIRECTORY)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
endif()

if(NOT DEFINED CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
endif()

# ----------------------------------
# Project Variables
# ----------------------------------
set(QMSETUP_VERSION ${PROJECT_VERSION})
set(QMSETUP_INSTALL_NAME ${PROJECT_NAME})
set(QMSETUP_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

include(cmake/QMSetupAPI.cmake)

add_subdirectory(src)
