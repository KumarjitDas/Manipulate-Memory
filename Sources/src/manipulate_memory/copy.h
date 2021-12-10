/**
 * \file copy.h
 * \author Kumarjit Das (kumarjitdas1999@gmail.com)
 * \brief Contains private memory-copying function declarations of this
 *        library.
 * \version 0.2.0
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

#ifndef _KDI_MANIPULATE_MEMORY_COPY_H_
#define _KDI_MANIPULATE_MEMORY_COPY_H_

#include "utility.h"

// #undef _KDI_ARCHITECTURE_64_BIT

#ifdef _KDI_ARCHITECTURE_64_BIT
void *_kdi_memory_copy_bytes(void *pDestination,
                             void *pSource,
                             uint64_t u64Size);

void *_kdi_memory_copy_bytes_reverse(void *pDestination,
                                     void *pSource,
                                     uint64_t u64Size);

void *_kdi_memory_copy_aligned(void *pDestination,
                               void *pSource,
                               uint64_t u64Size);

void *_kdi_memory_copy_aligned_reverse(void *pDestination,
                                       void *pSource,
                                       uint64_t u64Size);
#else  /* _KDI_ARCHITECTURE_64_BIT not defined */
#endif /* _KDI_ARCHITECTURE_64_BIT */

#endif /* _KDI_MANIPULATE_MEMORY_COPY_H_ */
