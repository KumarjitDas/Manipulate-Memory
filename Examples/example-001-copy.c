/**
 * \file example-001-copy.c
 * \author Kumarjit Das (kumarjitdas1999@gmail.com)
 * \brief An example for `Manipulate-Memory` library function
 *        `kdi_copy_memory`.
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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

// #undef KDI_MANIPULATE_MEMORY_ARCHITECTURE_64_BIT

#ifdef KDI_MANIPULATE_MEMORY_ARCHITECTURE_64_BIT
void show_usage(void) {
    printf(
        "Usage: example-001-copy <al> <cl>\n"
        "    al - a positive integer representing array length\n"
        "    cl - a positive integer representing copying length\n");
}

void print_array(const char *const sMessage,
                 uint32_t *p32Array,
                 uint64_t u64Length) {
    printf("%s: ", sMessage);
    for (uint64_t i = 0; i < u64Length; ++i) {
        printf("%u, ", p32Array[i]);
    }
    printf("END\n");
}

int main(int argc, char **argv) {
    if (argc < 3) {
        show_usage();
        return EXIT_FAILURE;
    }

    printf("\n Manipulate-Memory library example:\n\n");

    unsigned int uiSeed = time(NULL);
    srand(uiSeed);
    uint64_t u64Array_length = strtoull(argv[1], NULL, 10);
    uint64_t u64Copy_length = strtoull(argv[2], NULL, 10);
    uint32_t *p32Array = malloc(u64Array_length * sizeof(uint32_t));
    if (p32Array == NULL) {
        fprintf(stderr,
                "ERROR: Could not allocate memory for the array.\n");
        return EXIT_FAILURE;
    }
    uint32_t *p32Copy = malloc(u64Array_length * sizeof(uint32_t));
    if (p32Copy == NULL) {
        fprintf(stderr,
                "ERROR: Could not allocate memory for the copying array.\n");
        free(p32Array);
        return EXIT_FAILURE;
    }
    for (uint64_t i = 0; i < u64Array_length; ++i) {
        p32Array[i] = (uint32_t)rand() % 100;
    }
    printf("\nBefore copying...\n\n");
    print_array("Array", p32Array, u64Array_length);
    print_array("Copy", p32Copy, u64Array_length);

    (void)kdi_copy_memory(
        p32Copy,                             // *pDestination
        p32Array,                            // *pSource
        u64Copy_length * sizeof(uint32_t));  //  u64Size
    printf("\nAfter copying...\n\n");
    print_array("Array", p32Array, u64Array_length);
    print_array("Copy", p32Copy, u64Array_length);

    free(p32Array);
    free(p32Copy);
    return EXIT_SUCCESS;
}
#else  /* KDI_MANIPULATE_MEMORY_ARCHITECTURE_64_BIT not defined */
#endif /* KDI_MANIPULATE_MEMORY_ARCHITECTURE_64_BIT */
