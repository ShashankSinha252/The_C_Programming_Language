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
#include <string.h>

#define MAX_CHAR_ARR    100

void reverse(char s[]);
void itob(unsigned int n, char s[], unsigned int b);

int main(void)
{
    char str_val[MAX_CHAR_ARR];
    unsigned int val, base;

    /* Test vectors */
    val = 72U;
    base = 10U;
    itob(val, str_val, base);
    printf("%d represented as base %u = %s\n", val, base, str_val);

    val = 51227U;
    base = 36U;
    itob(val, str_val, base);
    printf("%d represented as base %u = %s\n", val, base, str_val);

    val = 122U;
    base = 7U;
    itob(val, str_val, base);
    printf("%d represented as base %u = %s\n", val, base, str_val);

    val = 72U;
    base = 2U;
    itob(val, str_val, base);
    printf("%d represented as base %u = %s\n", val, base, str_val);

    return 0;
}

/* itob(n,s,b): Convert integer n to representation
 *              in base b captured in s
 */
void itob(unsigned int n, char s[], unsigned int b)
{
    unsigned int val;
    unsigned int base;
    unsigned int len;
    unsigned int t;

    val = n;
    base = b;
    len = 0U;

    if(n == 0U || s == NULL || b == 0U || b > 36)
    {
        return;
    }

    for(val = n; val > 0U; val /= base)
    {
        t = val % base;
        if(t < 10U)
        {
            s[len++] = '0' + t;
        }
        else
        {
            s[len++] = 'a' + (t-10);
        }
    }
    s[len] = '\0';

    reverse(s);
}

/* reverse(s): Reverse string s */
void reverse(char s[])
{
    unsigned int p, q, len;
    char c;

    if(s == NULL)
    {
        return;
    }

    len = strlen(s);
    for(p = 0U, q = len-1; p < q; p++, q--)
    {
        c = s[p];
        s[p] = s[q];
        s[q] = c;
    }
}
