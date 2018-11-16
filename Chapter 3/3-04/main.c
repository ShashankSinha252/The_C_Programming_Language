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

void itoa(int n, char s[]);

int main(void)
{
    int val;
    char str_val[MAX_CHAR_ARR];
    char str_test[MAX_CHAR_ARR];
    char format_str[] = "%d";

    /* Test itoa against library implementation */
    for(val = INT_MIN; val < INT_MAX; val++)
    {
        itoa(val, str_val);
        snprintf(str_test, MAX_CHAR_ARR, format_str, val);
        if(strcmp(str_val, str_test) != 0)
        {
            printf("Error\n");
            printf("%s\n", str_val);
            printf("%s\n", str_test);
        }
    }

    return 0;
}

/* itoa: converts integer n to characters in s
 *
 * NOTE: Assumes s has enough memory to store n
 */
void itoa(int n, char s[])
{
    char sign, temp;
    int val, rem;
    unsigned int s_len;
    unsigned int p, q;

    sign = (n < 0) ? '-' : '\0';
    val = n;
    s_len = 0;

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

        s[s_len++] = '0' + rem;
        val /= 10;
    }

    if(sign != '\0')
    {
        s[s_len++] = sign;
    }
    s[s_len] = '\0';

    /* Reverse string to get valid string */
    for(p = 0, q = s_len-1; p < q; p++, q--)
    {
        temp = s[p];
        s[p] = s[q];
        s[q] = temp;
    }
}
