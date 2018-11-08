/*
 * Copyright (c) 2018
 * Shashank Sinha
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include <stdio.h>
#include <limits.h>

int invert(int x, unsigned p, unsigned n);

int main(void)
{
    printf("Let's start\n");

    int val = 0xABCD;
    unsigned int pos;
    unsigned int size;

    /* Test invert() */
    pos = 39U;
    size = 2U;
    printf("invert(%#x, %u, %u) = %#x\n",
                    val, pos, size, invert(val, pos, size));

    pos = 39U;
    size = 12U;
    printf("invert(%#x, %u, %u) = %#x\n",
                    val, pos, size, invert(val, pos, size));

    pos = 39U;
    size = 33U;
    printf("invert(%#x, %u, %u) = %#x\n",
                    val, pos, size, invert(val, pos, size));

    pos = 39U;
    size = 42U;
    printf("invert(%#x, %u, %u) = %#x\n",
                    val, pos, size, invert(val, pos, size));

    pos = 9U;
    size = 2U;
    printf("invert(%#x, %u, %u) = %#x\n",
                    val, pos, size, invert(val, pos, size));

    pos = 9U;
    size = 9U;
    printf("invert(%#x, %u, %u) = %#x\n",
                    val, pos, size, invert(val, pos, size));

    pos = 9U;
    size = 12U;
    printf("invert(%#x, %u, %u) = %#x\n",
                    val, pos, size, invert(val, pos, size));

    pos = 0U;
    size = 0U;
    printf("invert(%#x, %u, %u) = %#x\n",
                    val, pos, size, invert(val, pos, size));

    pos = 0U;
    size = 12U;
    printf("invert(%#x, %u, %u) = %#x\n",
                    val, pos, size, invert(val, pos, size));

    return 0;
}

int invert(int x, unsigned p, unsigned n)
{
    int retval = x;
    int bit_mask = 0x1;

    unsigned int ctr;
    unsigned int size_int = (sizeof(int) * CHAR_BIT);

    // No bits need to be flipped
    if (n == 0)
    {
    #ifdef DEBUG
        printf("No bits need to be flipped\n");
    #endif
        return x;
    }

    /* Ensure low_lim and high_lim are bit index in [0, size_int - 1] */
    unsigned int low_lim  = (p < (n-1))                ? 0          : p - (n-1);
    low_lim               = (low_lim > (size_int - 1)) ? size_int-1 : low_lim ;
    unsigned int high_lim = (p > (size_int-1))         ? size_int-1 : p;

    #ifdef DEBUG
        printf("Low = %u\tHigh = %u\n", low_lim, high_lim);
    #endif

    /*           <-First loop->
     *     00000011111111111111000000000000000
     *                         <-Second loop->
     */
    for(ctr = 0; ctr < (high_lim - low_lim); ctr++)
    {
        bit_mask <<= 1;
        bit_mask += 1;
    }

    for(ctr = 0; ctr < low_lim; ctr++)
    {
        bit_mask <<= 1;
    }

    #ifdef DEBUG
        printf("bit_mask = %#x\n", bit_mask);
    #endif

    /* Flip required bits */
    retval ^= bit_mask;

    return retval;
}
