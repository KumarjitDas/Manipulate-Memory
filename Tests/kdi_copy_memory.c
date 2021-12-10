/**
 * \file kdi_copy_memory.c
 * \author Kumarjit Das (kumarjitdas1999@gmail.com)
 * \brief Tests for `kdi_copy_memory` function.
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

#include "manipulate_memory/manipulate_memory.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <assert.h>

#define ARRAY_LENGTH 1000000

typedef int16_t mytype_t;

#ifdef KDI_MANIPULATE_MEMORY_ARCHITECTURE_64_BIT

void reset_array(mytype_t *mtArray, uint64_t u64Length) {
    mytype_t *mtArray_end = mtArray + u64Length;
    while (mtArray < mtArray_end) {
        *mtArray = 0;
        ++mtArray;
    }
}

int main() {
    // Generating seed from time to use in `srand`
    unsigned int uiSeed = (unsigned int)time(NULL);
    srand(uiSeed);

    uint64_t u64Size = ARRAY_LENGTH * sizeof(mytype_t);
    mytype_t *pmtArray1 = malloc(u64Size);
    if (pmtArray1 == NULL) {
        return EXIT_FAILURE;
    }
    mytype_t *pmtArray2 = malloc(u64Size);
    if (pmtArray2 == NULL) {
        free(pmtArray1);
        return EXIT_FAILURE;
    }
    for (uint64_t i = 0; i < ARRAY_LENGTH; ++i) {
        pmtArray2[i] = (mytype_t)rand();
    }
    mytype_t *pmtReturned_pointer = NULL;
    uint64_t u64Current_length, u64Match_count;

    // Test 1
    u64Current_length = 3;
    u64Match_count = 0;
    reset_array(pmtArray1, ARRAY_LENGTH);
    pmtReturned_pointer = kdi_copy_memory(
        pmtArray1,                              // *pDestination
        pmtArray2,                              // *pSource
        u64Current_length * sizeof(mytype_t));  //  u64Size
    assert(pmtReturned_pointer == pmtArray1);
    for (uint64_t i = 0; i < u64Current_length; ++i) {
        if (pmtArray1[i] == pmtArray2[i]) {
            ++u64Match_count;
        }
    }
    assert(u64Match_count == u64Current_length);

    // Test 2
    u64Current_length = 8;
    u64Match_count = 0;
    reset_array(pmtArray1, ARRAY_LENGTH);
    pmtReturned_pointer = kdi_copy_memory(
        pmtArray1,                              // *pDestination
        pmtArray2,                              // *pSource
        u64Current_length * sizeof(mytype_t));  //  u64Size
    assert(pmtReturned_pointer == pmtArray1);
    for (uint64_t i = 0; i < u64Current_length; ++i) {
        if (pmtArray1[i] == pmtArray2[i]) {
            ++u64Match_count;
        }
    }
    assert(u64Match_count == u64Current_length);

    // Test 3
    u64Current_length = 17;
    u64Match_count = 0;
    reset_array(pmtArray1, ARRAY_LENGTH);
    pmtReturned_pointer = kdi_copy_memory(
        pmtArray1,                              // *pDestination
        pmtArray2,                              // *pSource
        u64Current_length * sizeof(mytype_t));  //  u64Size
    assert(pmtReturned_pointer == pmtArray1);
    for (uint64_t i = 0; i < u64Current_length; ++i) {
        if (pmtArray1[i] == pmtArray2[i]) {
            ++u64Match_count;
        }
    }
    assert(u64Match_count == u64Current_length);

    // Test 4
    u64Current_length = 128;
    u64Match_count = 0;
    reset_array(pmtArray1, ARRAY_LENGTH);
    pmtReturned_pointer = kdi_copy_memory(
        pmtArray1,                              // *pDestination
        pmtArray2,                              // *pSource
        u64Current_length * sizeof(mytype_t));  //  u64Size
    assert(pmtReturned_pointer == pmtArray1);
    for (uint64_t i = 0; i < u64Current_length; ++i) {
        if (pmtArray1[i] == pmtArray2[i]) {
            ++u64Match_count;
        }
    }
    assert(u64Match_count == u64Current_length);

    // Test 5
    u64Current_length = 128;
    u64Match_count = 0;
    reset_array(pmtArray1, ARRAY_LENGTH);
    pmtReturned_pointer = kdi_copy_memory(
        (pmtArray1 + 69),                       // *pDestination
        pmtArray2,                              // *pSource
        u64Current_length * sizeof(mytype_t));  //  u64Size
    assert(pmtReturned_pointer == (pmtArray1 + 69));
    for (uint64_t i = 0; i < u64Current_length; ++i) {
        if ((pmtArray1 + 69)[i] == pmtArray2[i]) {
            ++u64Match_count;
        }
    }
    assert(u64Match_count == u64Current_length);

    // Test 6
    u64Current_length = ARRAY_LENGTH;
    u64Match_count = 0;
    reset_array(pmtArray1, ARRAY_LENGTH);
    pmtReturned_pointer = kdi_copy_memory(
        pmtArray1,                              // *pDestination
        pmtArray2,                              // *pSource
        u64Current_length * sizeof(mytype_t));  //  u64Size
    assert(pmtReturned_pointer == pmtArray1);
    for (uint64_t i = 0; i < u64Current_length; ++i) {
        if (pmtArray1[i] == pmtArray2[i]) {
            ++u64Match_count;
        }
    }
    assert(u64Match_count == u64Current_length);

    free(pmtArray1);
    free(pmtArray2);
    return EXIT_SUCCESS;
}

#else  /* KDI_MANIPULATE_MEMORY_ARCHITECTURE_64_BIT not defined */
#endif /* KDI_MANIPULATE_MEMORY_ARCHITECTURE_64_BIT */
