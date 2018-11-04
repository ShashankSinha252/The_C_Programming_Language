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

int bitcount(unsigned int input);

int main(void)
{
    int val = 0xABCD;

    int bitsOne = bitcount(val);
    printf("Number of 1s in %#x : %d\n", val, bitsOne);
    return 0;
}

// bitcount: returns number of 1 bits in input
int bitcount(unsigned int input)
{
    int ones = 0;

    while(input > 0)
    {
        /* -1 is represented with all bits as 1. When we
         * subtract -1, it is same as adding -1. This converts
         * rightmost 1 bit to 0, leaving all other 1 bit
         * untouched
         */
        input &= (input - 1);
        ones++;
    }

    return ones;
}
