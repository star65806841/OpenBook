qt_add_library(mainQml STATIC)
qt6_add_qml_module(mainQml
    URI "Main"
    VERSION 1.0
    NO_PLUGIN
    QML_FILES Main.qml
    OUTPUT_DIRECTORY ${GENERATED_INCLUDE_DIR}/Qml/Main
)

# ----------------------------------
# 添加QML模块路径
# ----------------------------------
# list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bookEditer/view")
