# ----------------------------------
# Find basic dependencies
# ----------------------------------
add_subdirectory(thirdparty/qmsetup)
# find_package(qmsetup QUIET)
# if(NOT TARGET qmsetup::library)
    # Modify this variable according to your project structure
    # set(_source_dir ${CMAKE_SOURCE_DIR}/thirdparty/qmsetup)

    # Import install function
    # include("${_source_dir}/cmake/modules/private/InstallPackage.cmake")

    # Install package in place
    # set(_package_path)
    # qm_install_package(qmsetup
    #     SOURCE_DIR ${_source_dir}
    #     BUILD_TYPE Release
    #     RESULT_PATH _package_path
    # )

    # Find package again
    # find_package(qmsetup QUIET PATHS ${_package_path})

    # Update import path
    # set(qmsetup_DIR ${_package_path} CACHE PATH "" FORCE)
# endif()
