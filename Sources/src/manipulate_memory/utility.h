/**
 * \file utility.h
 * \author Kumarjit Das (kumarjitdas1999@gmail.com)
 * \brief Contains all the private utility function declarations of this
 *        library.
 * \version 0.3.0
 * \date 2021-12-10
 *
 * \copyright Copyright (c) 2021
 *
 * License(MIT License):
 *
 * Copyright (c) 2021 Kumarjit Das | কুমারজিৎ দাস
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef _KDI_MANIPULATE_MEMORY_UTILITY_H_
#define _KDI_MANIPULATE_MEMORY_UTILITY_H_

#include <stdint.h>

#if defined(INT64_MAX) && defined(INT64_MIN)
#define _KDI_ARCHITECTURE_64_BIT
#endif /* defined(INT64_MAX) && defined(INT64_MIN) */

#ifdef _KDI_ARCHITECTURE_64_BIT
#define _KDI_MEMORY_WORD_SIZE sizeof(int64_t)
#else /* _KDI_ARCHITECTURE_64_BIT not defined */
#define _KDI_MEMORY_WORD_SIZE sizeof(int32_t)
#endif /* _KDI_ARCHITECTURE_64_BIT */

#define _KDI_MEMORY_COPY_SIZE_FOR_WHEN_TO_ALIGN 16

#endif /* _KDI_MANIPULATE_MEMORY_UTILITY_H_ */
