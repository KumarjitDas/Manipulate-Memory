/**
 * \file manipulate_memory.h
 * \author Kumarjit Das (kumarjitdas1999@gmail.com)
 * \brief Contains all `Manipulate-Memory` library function declarations.
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

#ifndef _KDI_MANIPULATE_MEMORY_H_
#define _KDI_MANIPULATE_MEMORY_H_

#include "manipulate_memory_api.h"
#include "manipulate_memory_version.h"

#include <stdint.h>

#if defined(INT64_MAX) && defined(INT64_MIN)
#ifndef KDI_MANIPULATE_MEMORY_ARCHITECTURE_64_BIT
#define KDI_MANIPULATE_MEMORY_ARCHITECTURE_64_BIT
#endif /* KDI_MANIPULATE_MEMORY_ARCHITECTURE_64_BIT */
#endif /* defined(INT64_MAX) && defined(INT64_MIN) */

// #undef KDI_MANIPULATE_MEMORY_ARCHITECTURE_64_BIT

#ifdef KDI_MANIPULATE_MEMORY_ARCHITECTURE_64_BIT

/**
 * \brief Copy the source to the destination and return the destination.
 *
 * \param pDestination destination memory location
 * \param pSource      source memory location
 * \param u64Size      copying size
 *
 * \return destination memory location
 *
 * \warning `pDestination` and `pSource` should be non-null pointers
 * \warning `u64Size` should be a non-zero value
 *
 * \since v0.3.0
 */
void KDI_MANIPULATE_MEMORY_API *
kdi_copy_memory(void *pDestination,
                void *pSource,
                uint64_t u64Size);

/**
 * \brief Copy the source to the destination while avoiding any overlap and
 *        return the destination.
 *
 * \param pDestination destination memory location
 * \param pSource      source memory location
 * \param u64Size      copying size
 *
 * \return destination memory location
 *
 * \warning `pDestination` and `pSource` should be non-null pointers
 * \warning `u64Size` should be a non-zero value
 *
 * \since v0.3.0
 */
void KDI_MANIPULATE_MEMORY_API *
kdi_move_memory(void *pDestination,
                void *pSource,
                uint64_t u64Size);

void KDI_MANIPULATE_MEMORY_API *
kdi_manipulate_memory_set(void *pMemory,
                          uint64_t u64Memory_size,
                          void *pValue,
                          uint64_t u64Value_size);

void KDI_MANIPULATE_MEMORY_API *
kdi_manipulate_memory_find(void *pMemory,
                           uint64_t u64Memory_size,
                           void *pValue,
                           uint64_t u64Value_size);

uint64_t KDI_MANIPULATE_MEMORY_API
kdi_manipulate_memory_find_index(void *pMemory,
                                 uint64_t u64Memory_size,
                                 void *pValue,
                                 uint64_t u64Value_size);

uint64_t KDI_MANIPULATE_MEMORY_API
kdi_manipulate_memory_find_element_index(void *pMemory,
                                         uint64_t u64Memory_size,
                                         void *pValue,
                                         uint64_t u64Value_size);

void KDI_MANIPULATE_MEMORY_API *
kdi_manipulate_memory_replace(void *pMemory,
                              uint64_t u64Memory_size,
                              void *pFind_value,
                              void *pReplace_value,
                              uint64_t u64Value_size);

int64_t KDI_MANIPULATE_MEMORY_API
kdi_manipulate_memory_compare(void *p1,
                              void *p2,
                              uint64_t u64Size);

void KDI_MANIPULATE_MEMORY_API *
kdi_manipulate_memory_apply(void *pMemory,
                            uint64_t u64Size,
                            void (*pfFunction)(void *));

void KDI_MANIPULATE_MEMORY_API *
kdi_manipulate_memory_apply_index(void *pMemory,
                                  uint64_t u64Size,
                                  void (*pfFunction)(uint64_t,
                                                     void *));
void KDI_MANIPULATE_MEMORY_API *
kdi_manipulate_memory_apply_element_index(void *pMemory,
                                          uint64_t u64Size,
                                          void (*pfFunction)(uint64_t,
                                                             void *));

#else  /* KDI_MANIPULATE_MEMORY_ARCHITECTURE_64_BIT not defined */
#endif /* KDI_MANIPULATE_MEMORY_ARCHITECTURE_64_BIT */

#endif /* _KDI_MANIPULATE_MEMORY_H_ */
