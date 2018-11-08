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

int setbits(int x, unsigned p, unsigned n, int y);

int main(void)
{
    int val1 = 0xabcd;
    int val2 = 0xfafbfcfd;

    printf("val1 = %#x\n", val1);
    printf("val2 = %#x\n", val2);

    unsigned int pos = 15U;
    unsigned int size = 4U;

    printf("\n");
    printf("setbits(%#x, %u, %u, %#x) = \t%#x\n",
                    val1, pos, size, val2,
                    setbits(val1, pos, size, val2));

    printf("\n");
    pos = 3U;
    size = 0U;
    printf("setbits(%#x, %u, %u, %#x) =\t%#x\n",
                    val1, pos, size, val2,
                    setbits(val1, pos, size, val2));

    printf("\n");
    pos = 7U;
    size = 9U;
    printf("setbits(%#x, %u, %u, %#x) = \t%#x\n",
                    val1, pos, size, val2,
                    setbits(val1, pos, size, val2));

    printf("\n");
    pos = 0U;
    size = 2U;
    printf("setbits(%#x, %u, %u, %#x) = \t%#x\n",
                    val1, pos, size, val2,
                    setbits(val1, pos, size, val2));

    printf("\n");
    pos = 36U;
    size = 9U;
    printf("setbits(%#x, %u, %u, %#x) = \t%#x\n",
                    val1, pos, size, val2,
                    setbits(val1, pos, size, val2));

    printf("\n");
    pos = 36U;
    size = 2U;
    printf("setbits(%#x, %u, %u, %#x) = \t%#x\n",
                    val1, pos, size, val2,
                    setbits(val1, pos, size, val2));

    printf("\n");
    pos = 36U;
    size = 40U;
    printf("setbits(%#x, %u, %u, %#x) = \t%#x\n",
                    val1, pos, size, val2,
                    setbits(val1, pos, size, val2));

    return 0;
}

int setbits(int x, unsigned p, unsigned n, int y)
{
    int retval = x;
    int rightbits = y;
    int bit_mask = 0x1;
    unsigned int ctr;
    unsigned int size_int = (sizeof(int) * CHAR_BIT);

    if(n == 0U)
    {
    #ifdef DEBUG
        printf("No bits need to be modified\n");
    #endif
        return retval;
    }

    /* Ensure low_lim and high_lim are bit index in [0, size_int - 1] */
    unsigned int low_lim  = (p < (n-1))                ? 0          : p - (n-1);
    low_lim               = (low_lim > (size_int - 1)) ? size_int-1 : low_lim ;
    unsigned int high_lim = (p > (size_int-1))         ? size_int-1 : p;

    #ifdef DEBUG
        printf("Low = %u\tHigh = %u\n", low_lim, high_lim);
    #endif

    /* Get rightmost n bits of y */
    for(ctr = 0; ctr < (high_lim - low_lim); ctr++)
    {
        bit_mask <<= 1;
        bit_mask  += 1;
    }

    rightbits &= bit_mask;
    #ifdef DEBUG
        printf("Rightmost bits of y =\t\t\t%#x\n", rightbits);
    #endif

    /* Create masks for operation on x */
    for(ctr = 0; ctr < low_lim; ctr++)
    {
        bit_mask <<= 1;
        rightbits <<= 1;
    }

    /* Clean bits [p, p-(n-1)] of x */
    retval &= ~bit_mask;
    #ifdef DEBUG
        printf("retval after and =\t\t\t%#x\n", retval);
    #endif

    /* Set bits [p, p-(n-1)] of x */
    retval |= rightbits;
    #ifdef DEBUG
        printf("retval after or =\t\t\t%#x\n", retval);
    #endif

    return retval;
}
