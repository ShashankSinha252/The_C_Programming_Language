/*
 * NAME OF FILE: USAGE
 *
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

#define IN_NUM      0
#define OUT_NUM     1

int isJunk(char c);
int getVal(char c);
long int htoi(char *str);

int main(void)
{

	//Testing of function htoi
	char hexstr1[] = "0xABCD";
	char hexstr2[] = "0x1234";
	char hexstr3[] = "asas0324sdf";
	char hexstr4[] = "101x234";
	char hexstr5[] = "0234x12a";
	char hexstr6[] = "qsqs0324sdf";

	printf("Value of hexadecimal string %s:\t%#lx\n", hexstr1, htoi(hexstr1));
	printf("Value of hexadecimal string %s:\t%#lx\n", hexstr2, htoi(hexstr2));
	printf("Value of hexadecimal string %s:\t%#lx\n", hexstr3, htoi(hexstr3));
	printf("Value of hexadecimal string %s:\t%#lx\n", hexstr4, htoi(hexstr4));
	printf("Value of hexadecimal string %s:\t%#lx\n", hexstr5, htoi(hexstr5));
	printf("Value of hexadecimal string %s:\t%#lx\n", hexstr6, htoi(hexstr6));

	return 0;
}

long int htoi(char *str)
{
    long int readVal = 0L;
    int state = OUT_NUM;
    int leadingZero = 0;
	char newChar;

    while((newChar = *(str++)) != 0)
    {
        int  junkChar = isJunk(newChar);

        if(state == OUT_NUM)
        {
            if(junkChar == 1)
            {
                continue;
            }
            else
            {
                if(newChar == 'x' || newChar == 'X')
                {
                    break;
                }
                if(newChar == '0')
                {
                    leadingZero = 1;
                }

                readVal = getVal(newChar);
                state = IN_NUM;
            }
        }
        else
        {
            if(junkChar == 1)
            {
                state = OUT_NUM;
                break;
            }
            else
            {
                if(newChar == 'x' || newChar == 'X')
                {
                    if(leadingZero == 1)
                    {
                        readVal = 0;
                        leadingZero = 0;
                    }
                    else
                    {
                        //Only Ox or OX at start of integer is allowed
                        break;
                    }
                }
                else
                {
                    leadingZero = 0;

                    readVal <<= 4;
                    readVal += getVal(newChar);
                }
            }
        }

    }

	return readVal;
}

int isJunk(char c)
{
    int junk = 1;

    if ((c >= '0' && c <= '9')
     || (c >= 'a' && c <= 'f')
     || (c >= 'A' && c <= 'F')
     || (c == 'x' || c == 'X'))
    {
        junk = 0;
    }

    return junk;
}

int getVal(char c)
{
    int retVal = 0;

    if(c >= '0' && c <= '9')
    {
        retVal = c - '0';
    }
    if(c >= 'a' && c <= 'f')
    {
        retVal = 10 + (c - 'a');
    }
    if(c >= 'A' && c <= 'F')
    {
        retVal = 10 + (c - 'A');
    }

    return retVal;
}
