cmake_minimum_required(VERSION 3.16)

project(bookEditer VERSION 1.0 LANGUAGES CXX)

# ----------------------------------
# 启用自动处理 moc/uic/rcc
# ----------------------------------
qt_standard_project_setup(REQUIRES 6.5)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# set(CMAKE_AUTOUIC ON)

# ----------------------------------
# 编译器警告
# ----------------------------------
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# ----------------------------------
# 添加子目录
# ----------------------------------
add_subdirectory(core)
add_subdirectory(view)
add_subdirectory(app)
