project(ToolUnit VERSION 1.0.0 LANGUAGES CXX)
# ----------------------------------
# Build Options
# ----------------------------------
option(TOOLUNIT_BUILD_LOG "Build Log module" ON)
# option(TOOLUNIT_BUILD_XLSX "Build Xlsx module" ON)
# option(TOOLUNIT_BUILD_TRANSLATE_CORE "Build Translate core module" ON)
# option(TOOLUNIT_BUILD_DUMP "Build Dump module" ON)
# option(TOOLUNIT_BUILD_DOCUMENTATIONS "Build documentations" OFF)
# option(TOOLUNIT_KERNEL_SERVER_DEBUG "Use saas debug server" OFF)
option(TOOLUNIT_INSTALL "Install library" OFF)

# ----------------------------------
# Project Variables
# ----------------------------------
# set(TOOLUNIT_VERSION ${PROJECT_VERSION})
set(TOOLUNIT_INSTALL_NAME ${PROJECT_NAME})
set(TOOLUNIT_GENERATED_INCLUDE_DIR ${GENERATED_INCLUDE_DIR}/${TOOLUNIT_INSTALL_NAME})
# set(TOOLUNIT_TRANSLATE_LIST)

# ----------------------------------
# CMake Settings
# ----------------------------------
if(MSVC)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /manifest:no")
  set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /manifest:no")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /manifest:no")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")

  if(NOT DEFINED CMAKE_DEBUG_POSTFIX)
      set(CMAKE_DEBUG_POSTFIX "d")
  endif()
endif()

if (LINUX)
  add_compile_options(-fPIC)
  add_compile_options(-no-pie)
endif()

# ----------------------------------
# Add source modules
# ----------------------------------
# file(GLOB_RECURSE THIRDPARTY_SROUCES
#     "${CURRENT_SOURCE_DIR}/thirdparty/*.h"
#     "${CURRENT_SOURCE_DIR}/thirdparty/*.cpp"
# )

if(TOOLUNIT_BUILD_LOG)
    add_subdirectory(OpenBookLog)
endif()
add_subdirectory(qwindowkit)
# if(AIMOKIT_INSTALL)
#     include(GNUInstallDirs)
#     include(CMakePackageConfigHelpers)
# endif()

# ----------------------------------
# Add source modules
# ----------------------------------
# add_subdirectory(AimoCommon)

# if(AIMOKIT_BUILD_XLSX)
#   add_subdirectory(AimoXlsx)
#   file(GLOB_RECURSE AIMOKIT_TMP
#       "${CMAKE_CURRENT_SOURCE_DIR}/AimoXlsx/src/*.h"
#       "${CMAKE_CURRENT_SOURCE_DIR}/AimoXlsx/src/*.cpp")
#   list(APPEND AIMOKIT_TRANSLATE_LIST ${AIMOKIT_TMP})
# endif()

# if(AIMOKIT_BUILD_TRANSLATE_CORE)
#     add_subdirectory(AimoTranslateCore)
# endif()

# if(AIMOKIT_BUILD_DUMP)
#     add_subdirectory(AimoDump)
# endif()

# add_subdirectory(Zint)
# add_subdirectory(miniLZO)
# add_subdirectory(AimoKernel)

# ----------------------------------
# Add translate files
# ----------------------------------
# qm_import(Translate)

# find_package(Qt5 COMPONENTS LinguistTools)

# set(__locales
#     "zh_CN"
#     "zh_HK"
#     "de"
#     "en"
#     "es"
#     "fr"
#     "id"
#     "it"
#     "pl"
#     "ru"
#     "ro"
#     "tr"
#     "cs"
#     "ar"
#     "ja"
# )

# qm_add_translation(aimokit
#     SOURCES ${AIMOKIT_TRANSLATE_LIST}
#     LOCALES ${__locales}
#     TS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/translationTS
#     QM_DIR ${CMAKE_CURRENT_SOURCE_DIR}/translationQM
#     TS_OPTIONS "-no-obsolete"
# )
