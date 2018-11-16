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
#include <ctype.h>

#define DIGIT       0
#define UPPER       1
#define LOWER       2
#define WHITESPACE  3

#define PASS        0
#define CHECK       1
#define EXPAND      2

void expand(char s[], char t[]);

int main(void)
{
    char str_in[] = "--  asfas  aasf-gg-9as-   -a-c-g0-9B-D- asf-a0-3-   af";
    char str_out[2 * strlen(str_in)];

    expand(str_in, str_out);
    printf("In : %s\n", str_in);
    printf("Out: %s\n", str_out);

    return 0;
}

void expand(char s[], char t[])
{
    int state, expand_style;
    char c, ctr;
    unsigned int s_len, t_len;

    s_len = t_len = 0;
    expand_style = WHITESPACE;
    state = PASS;
    while((c = s[s_len]) != '\0')
    {
        if(c == '-')
        {
            if(state == PASS && s_len > 0)
            {
                state = CHECK;
            }
            else
            {
                state = PASS;
            }
        }

        switch(state)
        {
            case PASS:
                t[t_len++] = s[s_len++];
                break;
            case CHECK:
                if(isdigit(s[s_len-1]) != 0)
                {
                    expand_style = DIGIT;
                    state = EXPAND;
                }
                else if(isupper(s[s_len-1]) != 0)
                {
                    expand_style = UPPER;
                    state = EXPAND;
                }
                else if(islower(s[s_len-1]) != 0)
                {
                    expand_style = LOWER;
                    state = EXPAND;
                }
                else
                {
                    t[t_len++] = s[s_len];
                    expand_style = WHITESPACE;
                    state = PASS;
                }
                s_len++;
                break;
            case EXPAND:
                if((isdigit(c) != 0) && (expand_style == DIGIT))
                {
                    for(ctr = s[s_len-2]+1; ctr < c ; ctr++)
                    {
                        t[t_len++] = ctr;
                    }
                    t[t_len++] = s[s_len];
                }
                else if((islower(c) != 0) && (expand_style == LOWER))
                {
                    for(ctr = s[s_len-2]+1; ctr < c ; ctr++)
                    {
                        t[t_len++] = ctr;
                    }
                    t[t_len++] = s[s_len];
                }
                else if((isupper(c) != 0) && (expand_style == UPPER))
                {
                    for(ctr = s[s_len-2]+1; ctr < c ; ctr++)
                    {
                        t[t_len++] = ctr;
                    }
                    t[t_len++] = s[s_len];
                }
                else
                {
                    t[t_len++] = '-';
                    t[t_len++] = s[s_len];
                }
                s_len++;
                expand_style = WHITESPACE;
                state = PASS;
                break;
        }
    }
    t[t_len] = '\0';
}
