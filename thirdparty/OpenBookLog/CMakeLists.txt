project(OpenBookLog VERSION 1.0.0 LANGUAGES CXX)

# ----------------------------------
# Build Options
# ----------------------------------
option(TOOLUNIT_BUILD_LOG_EXAMPLES "Build Log examples" OFF)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(${PROJECT_NAME} STATIC
  src/pairlogglobal.h
  src/alogger.h
  src/alogger.cpp
)
# ----------------------------------
# Project Variables
# ----------------------------------
set(LOG_GENERATED_INCLUDE_DIR ${TOOLUNIT_GENERATED_INCLUDE_DIR}/${PROJECT_NAME})
set(WITH_GTEST OFF)
set(WITH_GFLAGS OFF)
set(BUILD_TESTING OFF)
set(BUILD_SHARED_LIBS OFF)
add_subdirectory(3rdparty/glog)
# 编译阶段_宏定义 标准导出安装
target_compile_definitions(${PROJECT_NAME} PRIVATE PAIRLOG_LIBRARY)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core glog)
# qm_include_qt_private(${PROJECT_NAME} PRIVATE Core)

if(TOOLUNIT_BUILD_LOG_EXAMPLES)
	add_subdirectory(examples)
endif()

# ----------------------------------
# Install
# ----------------------------------
set(_install_options)
if(TOOLUNIT_INSTALL)
    install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Targets
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}" OPTIONAL
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}" OPTIONAL
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}" OPTIONAL
    )

    target_include_directories(${PROJECT_NAME} PUBLIC
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${AIMOKIT_INSTALL_NAME}>"
    )
    
    set(_install_options
        INSTALL_DIR "${CMAKE_INSTALL_INCLUDEDIR}/${AIMOKIT_INSTALL_NAME}/Log"
    )
endif()

# qm_import(Preprocess)
# Generate a standard include directory in build directory
# qm_sync_include(src "${LOG_GENERATED_INCLUDE_DIR}"
#         ${_install_options} FORCE
# )
# target_include_directories(${PROJECT_NAME} PUBLIC
#     "$<BUILD_INTERFACE:${LOG_GENERATED_INCLUDE_DIR}>"
# )
