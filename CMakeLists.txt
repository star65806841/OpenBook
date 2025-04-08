cmake_minimum_required(VERSION 3.16)

project(OpenBook VERSION 1.0.0 LANGUAGES CXX)

# ----------------------------------
# C++ Settings
# ----------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----------------------------------
# 查找 Qt 组件
# ----------------------------------
find_package(Qt6 COMPONENTS Core Gui Quick QuickControls2 REQUIRED)

# ----------------------------------
# 启用自动处理 moc/uic/rcc
# ----------------------------------
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# ----------------------------------
# 添加子目录
# ----------------------------------
add_subdirectory(3rdparty)
add_subdirectory(bookEditer)