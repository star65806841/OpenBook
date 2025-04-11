qt_add_library(mainQml STATIC)
qt6_add_qml_module(mainQml
    URI "Main"
    VERSION 1.0
    NO_PLUGIN
    QML_FILES Main.qml
    OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Qml/Main
)
# target_include_directories(mainQml INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
