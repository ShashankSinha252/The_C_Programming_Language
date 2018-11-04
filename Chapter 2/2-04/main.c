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

#define CHAR_SET_SIZE   256

void squeeze(char s1[], char s2[]);

int main(void)
{
    char str1[] = "A happy dog is a good dog";
    char str2[] = "Highway to hell";

    printf("str1 : %s\nstr2: %s\n", str1, str2);
    squeeze(str1, str2);
    printf("squeeze(str1, str2): %s\n", str1);

    return 0;
}

//Delete all characters in s2 from s1
void squeeze(char s1[], char s2[])
{
    char c;
    int ctr;
    int hashmap[CHAR_SET_SIZE] = {0};
    int pos;

    for(ctr = 0; (c = s2[ctr]) != '\0'; ctr++)
    {
        hashmap[c]++;
    }

    //Delete any character in s1 which is in hashmap
    for(pos = ctr = 0; ((c = s1[ctr]) != '\0') && (pos <= ctr); ctr++)
    {
        if(hashmap[c] == 0)
        {
            s1[pos++] = c;
        }
    }
    s1[pos] = '\0';
}
