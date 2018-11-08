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

int rightrot(int x, unsigned int n);

int main(void)
{
    printf("Let's start.\n");

    int val = 0xFBCD;
    unsigned int rot = 6U;
    printf("rightrot(%#x, %u) = %#x\n", val, rot, rightrot(val, rot));

    return 0;
}


int rightrot(int x, unsigned int n)
{
    int rotval;
    unsigned int ctr;
    int left_most_bit_mask;

    rotval = x;
    left_most_bit_mask = 0x1;

    /* NOTE: Using CHAR_BIT instead of 8 for portability;
     *       Using loop to calculate mask instead of (~0 >> 1)
     *       to deal with sign extension
     */
    for(ctr = 0U; ctr < ((sizeof(int) * CHAR_BIT) - 1); ctr++)
    {
        left_most_bit_mask <<= 1;
    }

    for(ctr = 0U; ctr < n; ctr++)
    {
        //Dealing with sign extension
        if ((rotval  & 0x1) == 0x1)
        {
            rotval = (rotval >> 1) | left_most_bit_mask;
        } else {
            rotval = (rotval >> 1) & ~left_most_bit_mask;
        }
    }
    return rotval;

}
