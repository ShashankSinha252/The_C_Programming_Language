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

void escape(char s[], char t[]);
void capture(char s[], char t[]);

int main(void)
{
    char str_in[] = "Who \k\j knows \n what \t is \n\t\t\t\n all about";
    char str_escape[2 * strlen(str_in)];
    char str_capture[2 * strlen(str_in)];

    escape(str_in, str_escape);
    capture(str_escape, str_capture);
    printf("Input  : %s\n", str_in);
    printf("Escape : %s\n", str_escape);
    printf("Capture: %s\n", str_capture);

    return 0;
}

/*
 * escape(s,t): For every newline and tab character in s, convert
 *              it to printable character in t
 *
 * NOTE: Assumes t has enough space for new string
 */
void escape(char s[], char t[])
{
    unsigned int s_len, t_len;
    s_len = 0;
    t_len = 0;

    if(s == NULL || t == NULL)
    {
        return;
    }

    for(s_len = 0; s_len < strlen(s); s_len++)
    {
        switch(s[s_len])
        {
            case '\t':
                t[t_len++] = '\\';
                t[t_len++] = 't';
                break;
            case '\n':
                t[t_len++] = '\\';
                t[t_len++] = 'n';
                break;
            default:
                t[t_len++] = s[s_len];
        }
    }
    t[t_len] = '\0';
}

/*
 * capture(s,t): For every '\n' and '\t' printed in s, convert
 *               to newline and tabspace in t
 *
 * NOTE: Assumes t has enough space for new string
 */
void capture(char s[], char t[])
{
    unsigned int s_len, t_len;
    s_len = 0;
    t_len = 0;

    if(s == NULL || t == NULL)
    {
        return;
    }

    while(s[s_len] != '\0')
    {
        if(s[s_len] == '\\')
        {
            s_len++;
            switch(s[s_len])
            {
                case 'n':
                    t[t_len++] = '\n';
                    s_len++;
                    break;
                case 't':
                    t[t_len++] = '\t';
                    s_len++;
                    break;
                default:
                    t[t_len++] = '\\';
                    t[t_len++] = s[s_len++];
            }
        }
        else
        {
            t[t_len++] = s[s_len++];
        }
    }
    t[t_len] = '\0';
}
