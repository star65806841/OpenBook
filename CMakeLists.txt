cmake_minimum_required(VERSION 3.21)

project(OpenBook VERSION 1.0.0 LANGUAGES CXX)

# ----------------------------------
# C++ Settings
# ----------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(COMPANY_NAME "PairIdeaCo")
set(COMPANY_COPYRIGHT "Copyright PairIdea Co., Ltd. All rights reserved")
# ----------------------------------
# 查找 Qt 组件
# ----------------------------------
find_package(Qt6 COMPONENTS Core Gui Quick QuickControls2 Qml REQUIRED)

# ----------------------------------
# 添加QML模块路径
# ----------------------------------
# list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bookEditer/view")

#===================================
# Output Directories.
#===================================
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(GENERATED_INCLUDE_DIR ${CMAKE_BINARY_DIR}/include)
# ----------------------------------
# 添加子目录
# ----------------------------------
add_subdirectory(bookEditer)
add_subdirectory(thirdparty)
# add_subdirectory(aimoquickcontrolplugins)
# add_subdirectory(src/core)
# add_subdirectory(src/qml)
# add_subdirectory(src/app)

# ----------------------------------
# Add source modules
# ----------------------------------
file(GLOB_RECURSE THIRDPARTY_SROUCES
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/*.cpp"
)

