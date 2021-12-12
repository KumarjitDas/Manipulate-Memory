/**
 * \file manipulate_memory.c
 * \author Kumarjit Das (kumarjitdas1999@gmail.com)
 * \brief Contains all the definitions of all the library functions.
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

#include "manipulate_memory/manipulate_memory.h"
#include "utility.h"
#include "copy.h"

// #undef _KDI_ARCHITECTURE_64_BIT

#ifdef _KDI_ARCHITECTURE_64_BIT

void *kdi_copy_memory(void *pDestination,
                      void *pSource,
                      uint64_t u64Size) {
    if (u64Size < _KDI_MEMORY_COPY_SIZE_FOR_WHEN_TO_ALIGN) {
        return _kdi_copy_bytes_from_memory(pDestination,
                                           pSource,
                                           u64Size);
    }
    return _kdi_copy_words_from_memory(pDestination,
                                       pSource,
                                       u64Size);
}

void *kdi_move_memory(void *pDestination,
                      void *pSource,
                      uint64_t u64Size) {
    void *pSource_end = (uint8_t *)pSource + u64Size;
    if ((pDestination > pSource) &&
        (pDestination < pSource_end)) {
        if (u64Size < _KDI_MEMORY_COPY_SIZE_FOR_WHEN_TO_ALIGN) {
            return _kdi_copy_bytes_from_memory_reverse(pDestination,
                                                       pSource,
                                                       u64Size);
        }
        return _kdi_copy_words_from_memory_reverse(pDestination,
                                                   pSource,
                                                   u64Size);
    }
    return kdi_copy_memory(pDestination,
                           pSource,
                           u64Size);
}

void *kdi_set_memory(void *pMemory,
                     uint64_t u64Memory_size,
                     void *pValue,
                     uint64_t u64Value_size) {
    (void)pMemory;
    (void)u64Memory_size;
    (void)pValue;
    (void)u64Value_size;
    return pMemory;
}

void *kdi_find_in_memory(void *pMemory,
                         uint64_t u64Memory_size,
                         void *pValue,
                         uint64_t u64Value_size) {
    (void)pMemory;
    (void)u64Memory_size;
    (void)pValue;
    (void)u64Value_size;
    return NULL;
}

uint64_t kdi_find_in_memory_index(void *pMemory,
                                  uint64_t u64Memory_size,
                                  void *pValue,
                                  uint64_t u64Value_size) {
    (void)pMemory;
    (void)u64Memory_size;
    (void)pValue;
    (void)u64Value_size;
    return 0;
}

uint64_t kdi_find_in_memory_element_index(void *pMemory,
                                          uint64_t u64Memory_size,
                                          void *pValue,
                                          uint64_t u64Value_size) {
    (void)pMemory;
    (void)u64Memory_size;
    (void)pValue;
    (void)u64Value_size;
    return 0;
}

void *kdi_replace_in_memory(void *pMemory,
                            uint64_t u64Memory_size,
                            void *pFind_value,
                            void *pReplace_value,
                            uint64_t u64Value_size) {
    (void)pMemory;
    (void)u64Memory_size;
    (void)pFind_value;
    (void)pReplace_value;
    (void)u64Value_size;
    return NULL;
}

int64_t kdi_compare_memory(void *p1,
                           void *p2,
                           uint64_t u64Size) {
    (void)p1;
    (void)p2;
    (void)u64Size;
    return 0;
}

void *kdi_apply_function_in_memory(void *pMemory,
                                   uint64_t u64Size,
                                   void (*pfFunction)(void *)) {
    (void)pMemory;
    (void)u64Size;
    (void)pfFunction;
    return NULL;
}

void *kdi_apply_index_function_in_memory(void *pMemory,
                                         uint64_t u64Size,
                                         void (*pfFunction)(uint64_t,
                                                            void *)) {
    (void)pMemory;
    (void)u64Size;
    (void)pfFunction;
    return NULL;
}

void *kdi_apply_element_index_function_in_memory(void *pMemory,
                                                 uint64_t u64Size,
                                                 void (*pfFunction)(uint64_t,
                                                                    void *)) {
    (void)pMemory;
    (void)u64Size;
    (void)pfFunction;
    return NULL;
}

#else  /* _KDI_ARCHITECTURE_64_BIT not defined */
#endif /* _KDI_ARCHITECTURE_64_BIT */
