project(app VERSION 1.0 LANGUAGES CXX)

if(WIN32)
    file(GLOB_RECURSE APP_SRC *.h *.cpp)
elseif(APPLE)
    file(GLOB_RECURSE MM_SOURCES *.mm)
    list(APPEND SOURCES ${MM_SOURCES})
endif()

qt_add_executable(${CMAKE_PROJECT_NAME}
    ${APP_SRC}
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
    # QWKCore
    # QWKQuick
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${GENERATED_INCLUDE_DIR}>")
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
