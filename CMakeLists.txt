cmake_minimum_required(VERSION 3.21)

project(OpenBook VERSION 1.0.0 LANGUAGES CXX)

# ----------------------------------
# C++ Settings
# ----------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----------------------------------
# 查找 Qt 组件
# ----------------------------------
find_package(Qt6 COMPONENTS Core Gui Quick QuickControls2 Qml Widgets REQUIRED)
#===================================
# Output Directories.
#===================================
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/include/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/include/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/include/bin)
set(GENERATED_INCLUDE_DIR ${CMAKE_BINARY_DIR}/include)
# ----------------------------------
# 添加子目录
# ----------------------------------
include(generalSettings.cmake)
# include(qmsetup.cmake)
add_subdirectory(bookEditer)
add_subdirectory(thirdparty)
# add_subdirectory(aimoquickcontrolplugins)
# add_subdirectory(src/core)
# add_subdirectory(src/qml)
# add_subdirectory(src/app)

# qm_import(Filesystem)
# qm_init_directories()
