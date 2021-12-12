##
# file: add_dependencies.cmake
# author: Kumarjit Das (kumarjitdas1999@gmail.com)
# brief: Creates the library.
# version: 0.4.0
# date: 2021-12-12
#
# License(MIT License):
#
# Copyright (c) 2021 Kumarjit Das | কুমারজিৎ দাস
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
#

write_status("Adding dependencies of '${KDI_PROJECT_NAME}'.")

# Setting the dependency directory in case if downloading is required
set(KDI_DEPENDENCY_DIR "${KDI_CURRENT_USER_PATH}/CMake-Project-Dependencies")
# Setting the dependency
set(KDI_DEPENDENCY "Align-Memory")
string(TOLOWER ${KDI_DEPENDENCY} KDI_DEPENDENCY_LOWER)
# Setting the dependency name space
set(KDI_DEPENDENCY_NAMESPACE "KDI")
# Setting the dependency library name
set(KDI_DEPENDENCY_LIBRARY "ALIGN_MEMORY")
string(TOLOWER ${KDI_DEPENDENCY_LIBRARY} KDI_DEPENDENCY_LIBRARY_LOWER)
# Setting the dependency version
set(KDI_DEPENDENCY_VERSION "0.9.0")
# Setting the dependency download directory
set(KDI_DEPENDENCY_DOWNLOAD_DIR "${KDI_DEPENDENCY_DIR}/Downloads/${KDI_DEPENDENCY}")
# Setting the dependency source directory
set(KDI_DEPENDENCY_SOURCE_DIR "${KDI_DEPENDENCY_DIR}/Sources/${KDI_DEPENDENCY}")
# Setting the dependency build directory
set(KDI_DEPENDENCY_BUILD_DIR "${KDI_DEPENDENCY_DIR}/Builds/${KDI_DEPENDENCY}/${KDI_BUILD_LIBRARY_TYPE}")
# Setting the dependency install directory
set(KDI_DEPENDENCY_INSTALL_DIR "${KDI_DEPENDENCY_DIR}/Installed/${KDI_DEPENDENCY}/${KDI_BUILD_LIBRARY_TYPE}")
# Setting the download URL of this dependency
set(KDI_DEPENDENCY_URL "https://github.com/KumarjitDas/Align-Memory.git")

# Include the dependency to this project
find_package(${KDI_DEPENDENCY} QUIET)
if(NOT ${KDI_DEPENDENCY}_FOUND)
    # Create the appropriate directories
    set(_DIR_LIST DOWNLOAD SOURCE BUILD INSTALL)
    foreach(_VAR IN LISTS _DIR_LIST)
        set(_DIR "${KDI_DEPENDENCY_${_VAR}_DIR}")
        if(NOT EXISTS ${_DIR})
            file(MAKE_DIRECTORY ${_DIR})
            write_status("Creating directory: ${_DIR}")
        endif()
    endforeach()

    if(NOT EXISTS "${KDI_DEPENDENCY_DIR}/Sources/${KDI_DEPENDENCY_LOWER}-src")
        write_status("Dependency, '${KDI_DEPENDENCY}', not found!")
        write_status("Trying to download '${KDI_DEPENDENCY}' from GitHub...")
        write_status("Download directory: ${KDI_DEPENDENCY_DOWNLOAD_DIR}")
        # Including "FetchContent" to download dependency
        include(FetchContent)
        # Setting the base directory for fetching
        set(FETCHCONTENT_BASE_DIR ${KDI_DEPENDENCY_DOWNLOAD_DIR})
        # Fetching dependency content from GitHub
        FetchContent_Declare(
            ${KDI_DEPENDENCY}
            GIT_REPOSITORY    ${KDI_DEPENDENCY_URL}
            GIT_TAG           "v${KDI_DEPENDENCY_VERSION}"
            GIT_PROGRESS      FALSE
        )
        FetchContent_MakeAvailable(${KDI_DEPENDENCY})
        if(NOT "${${KDI_DEPENDENCY_LOWER}_POPULATED}")
            write_status("Dependency, ${KDI_DEPENDENCY}, could not be downloaded from GitHub.")
            message(FATAL_ERROR "")
        else()
            write_status("Dependency, ${KDI_DEPENDENCY}, has been successfully downloaded.")
        endif()
        # Copying the downloaded source directory to dependency source directory
        file(REMOVE_RECURSE ${KDI_DEPENDENCY_SOURCE_DIR})
        file(COPY "${${KDI_DEPENDENCY_LOWER}_SOURCE_DIR}"
            DESTINATION "${KDI_DEPENDENCY_DIR}/Sources")
        file(RENAME
            "${KDI_DEPENDENCY_DIR}/Sources/${KDI_DEPENDENCY_LOWER}-src"
            ${KDI_DEPENDENCY_SOURCE_DIR})
    endif()
    # Configure the dependency
    execute_process(COMMAND
        ${CMAKE_COMMAND} -S . -B ${KDI_DEPENDENCY_BUILD_DIR} -DBUILD_SHARED_LIBS=${BUILD_SHARED_LIBS} -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=${CMAKE_EXPORT_COMPILE_COMMANDS} -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE} -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER_ID} -G "${CMAKE_GENERATOR}"
        WORKING_DIRECTORY ${KDI_DEPENDENCY_SOURCE_DIR})
    # Build the dependency
    execute_process(COMMAND
        ${CMAKE_COMMAND} --build . --config ${CMAKE_BUILD_TYPE}
        WORKING_DIRECTORY ${KDI_DEPENDENCY_BUILD_DIR})
    # Install the dependency
    execute_process(COMMAND
        ${CMAKE_COMMAND} --install ${KDI_DEPENDENCY_BUILD_DIR} --config ${CMAKE_BUILD_TYPE} --prefix ${KDI_DEPENDENCY_INSTALL_DIR})
    find_package(${KDI_DEPENDENCY} REQUIRED
                 PATHS "${KDI_DEPENDENCY_INSTALL_DIR}/lib/cmake/${KDI_DEPENDENCY_LOWER}")
endif()

write_status("Adding dependency: ${KDI_DEPENDENCY}")

# Adding the private include directories of the dependency
target_sources(${KDI_LIBRARY_NAME} PRIVATE "${${KDI_DEPENDENCY_LIBRARY}_INCLUDE_DIR}")
# Linking the dependency library with the main target library
target_link_libraries(${KDI_LIBRARY_NAME} ${KDI_DEPENDENCY_NAMESPACE}::${KDI_DEPENDENCY_LIBRARY_LOWER})
