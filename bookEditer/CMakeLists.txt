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

qt_add_executable(${CMAKE_PROJECT_NAME}
    app/main.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    mainQml
    Qt6::Gui
    Qt6::Qml
)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    # 避免控制台窗口干扰用户体验‌
    WIN32_EXECUTABLE ON
    # 在 macOS 平台生成 .app 格式的应用程序包，包含标准目录结构（如 Contents/Resources 和 Contents/MacOS），符合 macOS 应用分发规范‌1。
    # ‌附加效果‌：自动生成默认的 Info.plist 文件，可通过 MACOSX_BUNDLE_INFO_PLIST 属性自定义该文件路径‌1。
    MACOSX_BUNDLE ON
)
