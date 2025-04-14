project(app VERSION 1.0 LANGUAGES CXX)

qt_add_executable(${CMAKE_PROJECT_NAME}
    main.cpp
)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    # 避免控制台窗口干扰用户体验‌
    WIN32_EXECUTABLE ON
    # 在 macOS 平台生成 .app 格式的应用程序包，包含标准目录结构（如 Contents/Resources 和 Contents/MacOS），符合 macOS 应用分发规范‌1。
    # ‌附加效果‌：自动生成默认的 Info.plist 文件，可通过 MACOSX_BUNDLE_INFO_PLIST 属性自定义该文件路径‌1。
    MACOSX_BUNDLE ON
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    mainQml
    OpenBookLog
    Qt6::Gui
    Qt6::Qml
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    "$<BUILD_INTERFACE:${GENERATED_INCLUDE_DIR}>"
)
