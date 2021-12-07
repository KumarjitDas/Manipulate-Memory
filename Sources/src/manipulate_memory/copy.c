/**
 * @file copy.c
 * @author Kumarjit Das (kumarjitdas1999@gmail.com)
 * @brief Contains private memory-copying function definitions of this
 *        library.
 * @version 0.1.0
 * @date 2021-12-07
 *
 * @copyright Copyright (c) 2021
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

#include "utility.h"
#include "alignment.h"
#include "copy.h"

// #undef _KDI_ARCHITECTURE_64_BIT

#ifdef _KDI_ARCHITECTURE_64_BIT
void *_kdi_memory_copy_bytes(void *pDestination,
                             void *pSource,
                             uint64_t u64Size) {
    uint8_t *p8Destination = pDestination;
    uint8_t *p8Source = pSource;
    uint8_t *p8Destination_end = p8Destination + u64Size;
    while (p8Destination < p8Destination_end) {
        *p8Destination = *p8Source;
        ++p8Destination;
        ++p8Source;
    }
    return pDestination;
}

void *_kdi_memory_copy_aligned(void *pDestination,
                               void *pSource,
                               uint64_t u64Size) {
    uint8_t *p8Destination = pDestination;
    uint8_t *p8Source = pSource;
    uint8_t *p8Destination_end = _kdi_get_aligned_address(pDestination);
    while (p8Destination < p8Destination_end) {
        *p8Destination = *p8Source;
        ++p8Destination;
        ++p8Source;
    }
    uint64_t *p64Destination = (void *)p8Destination;
    uint64_t *p64Source = (void *)p8Source;
    uint64_t *p64Actual_destination_end = (void *)((uint8_t *)pDestination +
                                                   u64Size);
    uint64_t *p64Destination_end = _kdi_get_aligned_address(
        p64Actual_destination_end);
    if (p64Destination_end > p64Actual_destination_end) {
        p64Destination_end -= 1;  // here, 1 is equivalent to one element size
    }
    while (p64Destination < p64Destination_end) {
        *p64Destination = *p64Source;
        ++p64Destination;
        ++p64Source;
    }
    p8Destination = (void *)p64Destination;
    p8Source = (void *)p64Source;
    p8Destination_end = (void *)p64Actual_destination_end;
    while (p8Destination < p8Destination_end) {
        *p8Destination = *p8Source;
        ++p8Destination;
        ++p8Source;
    }
    return pDestination;
}
#else  /* _KDI_ARCHITECTURE_64_BIT not defined */
#endif /* _KDI_ARCHITECTURE_64_BIT */
