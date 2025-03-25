cmake_minimum_required(VERSION 3.16)

project(bookEditer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick QuickControls2)

qt_standard_project_setup(REQUIRES 6.5)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
# file(GLOB_RECURSE QRCS ${CMAKE_CURRENT_SOURCE_DIR}/resources/*.qrc)
file(GLOB_RECURSE QML_FILES "qml/*.qml")

if(APPLE)
    file(GLOB_RECURSE MM_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.mm)
    list(APPEND SOURCES ${MM_SOURCES})
endif()

if(APPLE)
    set(resources_list ${CMAKE_CURRENT_SOURCE_DIR}/resources/AppIcon.icns)
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCES} qml.qrc ${QRCS} ${resources_list})
elseif(WIN32)
    add_executable(${PROJECT_NAME} ${SOURCES} ${QML_FILES} #[[${QRCS}]])
    # qm_add_win_rc_enhanced(${PROJECT_NAME}
    #     NAME      ${PROJECT_NAME}
    #     VERSION   ${PROJECT_VERSION}
    #     COMPANY   ${COMPANY_NAME}
    #     COPYRIGHT ${AIMO_COPYRIGHT}
    #     ICONS     ${CMAKE_CURRENT_SOURCE_DIR}/resources/logo.ico
    # )
else()
    add_executable(${PROJECT_NAME} ${SOURCES} qml.qrc ${QRCS})
endif()

qt6_add_qml_module(${PROJECT_NAME}
    URI "Main"
    VERSION 1.0
    QML_FILES qml/Main.qml
    # RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/images/checkmark.png
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(${PROJECT_NAME} PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.bookEditer
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Quick Qt6::QuickControls2
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
