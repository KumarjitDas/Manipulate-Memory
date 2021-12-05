##
# file: validate_build_config.cmake
# author: Kumarjit Das (kumarjitdas1999@gmail.com)
# brief: Validates the project build configuration.
# version: 0.1.0
# date: 2021-12-05
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

write_status("Validating build configuration.")

set(VALID_BUILD_TYPES "Release" "Debug" "MinSizeRel" "RelWithDebInfo")
# Validate build configuration
if(NOT CMAKE_CONFIGURATION_TYPES)
    # Setting the default build type to release
    if(${CMAKE_BUILD_TYPE} STREQUAL "")
        set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build configuration" FORCE)
    endif()
    # Checking validity of build type in multiple build configuration
    list(FIND VALID_BUILD_TYPES ${CMAKE_BUILD_TYPE} INDEX)
    if(${INDEX} MATCHES -1)
        message(
            FATAL_ERROR
            "Invalid build type. Valid build types are: ${VALID_BUILD_TYPES}"
        )
    endif()
    # Setting all valid build type in multiple build configuration
    if(DEFINED CMAKE_BUILD_TYPE)
        set_property(CACHE CMAKE_BUILD_TYPE
                     PROPERTY STRINGS ${VALID_BUILD_TYPES})
    endif()
endif()
