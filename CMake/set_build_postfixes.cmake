##
# file: set_build_postfixes.cmake
# author: Kumarjit Das (kumarjitdas1999@gmail.com)
# brief: Set the build postfixes of the project library.
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

write_status("Setting build postfixes.")

# Add `-s` as postfix to the build output when building static libraries
if(NOT BUILD_SHARED_LIBS)
    set(STATIC_POSTFIX "-s")
endif()

# Setting build postfixes for different build configurations
set_target_properties(
    ${KDI_LIBRARY_NAME}      PROPERTIES
    OUTPUT_NAME            "${KDI_LIBRARY_NAME}"
    DEBUG_POSTFIX          "${STATIC_POSTFIX}-d"
    RELEASE_POSTFIX        "${STATIC_POSTFIX}"
    MINSIZEREL_POSTFIX     "${STATIC_POSTFIX}-mr"
    RELWITHDEBINFO_POSTFIX "${STATIC_POSTFIX}-rd"
)
