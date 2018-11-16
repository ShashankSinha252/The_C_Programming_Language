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
#include <string.h>

#define MAX_CHAR_ARR    1000

void itoa(int n, char s[], unsigned int width);

int main(void)
{
    int val;
    char str_val[MAX_CHAR_ARR];

    /* Test vectors */
    val = INT_MIN-2;
    itoa(val, str_val, 20U);
    printf("%d : %s\n", val, str_val);

    val = INT_MIN-2;
    itoa(val, str_val, 11U);
    printf("%d : %s\n", val, str_val);

    val = INT_MIN-2;
    itoa(val, str_val, 12U);
    printf("%d : %s\n", val, str_val);

    val = INT_MIN-2;
    itoa(val, str_val, 10U);
    printf("%d : %s\n", val, str_val);

    val = INT_MIN-2;
    itoa(val, str_val, 13U);
    printf("%d : %s\n", val, str_val);

    return 0;
}

/* itoa: converts integer n to string s, with
 *       minimum length as 'width'
 * NOTE: Assumes s has enough memory to store n
 */
void itoa(int n, char s[], unsigned int width)
{
    char sign, temp;
    int val, rem;
    unsigned int len;
    unsigned int p, q;
    unsigned int n_char;

    sign = (n < 0) ? '-' : '\0';
    val = n;
    len = 0;

    /* Handle special case */
    if(val == 0)
    {
        s[0] = '0';
        s[1] = '\0';
        return;
    }

    /* Form string in reverse */
    while(val != 0)
    {
        rem = val % 10;
        if(rem < 0)
        {
            rem = -rem;
        }

        s[len++] = '0' + rem;
        val /= 10;
    }

    n_char = (n < 0) ? width-1 : width;
    for(; len < n_char;)
    {
        s[len++] = '0';
    }

    if(sign != '\0')
    {
        s[len++] = sign;
    }
    s[len] = '\0';

    /* Reverse string to get valid string */
    for(p = 0, q = len-1; p < q; p++, q--)
    {
        temp = s[p];
        s[p] = s[q];
        s[q] = temp;
    }
}
