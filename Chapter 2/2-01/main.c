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
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("Let's start.\n");
    printf("\n");

    //Retrieve min, max values from limits.h
    printf("Get limit values from header.\n");

    printf("signed char    : Min = %d  \t\t\tMax = %d\n",  SCHAR_MIN, SCHAR_MAX);
    printf("signed short   : Min = %hd \t\t\tMax = %hd\n", SHRT_MIN, SHRT_MAX);
    printf("signed int     : Min = %d  \t\tMax = %d\n",    INT_MIN, INT_MAX);
    printf("signed long    : Min = %ld \tMax = %ld\n",     LONG_MIN, LONG_MAX);
    printf("\n");
    printf("unsigned char  : Min = %u  \t\t\tMax = %u\n",  0, UCHAR_MAX);
    printf("unsigned short : Min = %hu \t\t\tMax = %hu\n", 0 , USHRT_MAX);
    printf("unsigned int   : Min = %u  \t\t\tMax = %u\n",  0, UINT_MAX);
    printf("unsigned long  : Min = %lu \t\t\tMax = %lu\n", 0L, ULONG_MAX);
    printf("\n");
    printf("float          : Min = %E  \t\tMax = %E\n",    FLT_MIN, FLT_MAX);
    printf("double         : Min = %lE \t\tMax = %lE\n",   DBL_MIN, DBL_MAX);
    printf("long double    : Min = %LE \t\tMax = %LE\n",   LDBL_MIN, LDBL_MAX);
    printf("\n");

    //Get bit width for various types of integer
    unsigned int bits_char  = sizeof(char)  * 8;
    unsigned int bits_short = sizeof(short) * 8;
    unsigned int bits_int   = sizeof(int)   * 8;
    unsigned int bits_long  = sizeof(long)  * 8;

    #ifdef DEBUG
        printf("Bits for char        : \t%u\n",  bits_char);
        printf("Bits for short       : \t%u\n",  bits_short);
        printf("Bits for int         : \t%u\n",  bits_int);
        printf("Bits for long        : \t%u\n",  bits_long);
        printf("\n");

        printf("Bits for float       : \t%lu\n", 8u * sizeof(float));
        printf("Bits for double      : \t%lu\n", 8u * sizeof(double));
        printf("Bits for long double : \t%lu\n", 8u *sizeof(long double));
        printf("\n");
    #endif

    //Compute limit values
    signed char  schar_min  = -1 << (bits_char - 1);
    signed char  schar_max  = ~schar_min;
    signed short sshort_min = -1 << (bits_short - 1);
    signed short sshort_max = ~sshort_min;
    signed int   sint_min   = -1 << (bits_int - 1);
    signed int   sint_max   = ~sint_min;
    signed long  slong_min  = -1L << (bits_long - 1);
    signed long  slong_max  = ~slong_min;

    unsigned char  uchar_max  = (unsigned char)  (0u - 1u);
    unsigned short ushort_max = (unsigned short) (0u - 1u);
    unsigned int   uint_max   =                   0u - 1u;
    unsigned long  ulong_max  =                   0lu - 1lu;

    printf("Compute limit values.\n");
    printf("signed char    : Min = %d  \t\t\tMax = %d\n",  schar_min, schar_max);
    printf("signed short   : Min = %hd \t\t\tMax = %hd\n", sshort_min, sshort_max);
    printf("signed int     : Min = %d  \t\tMax = %d\n",    sint_min, sint_max);
    printf("signed long    : Min = %ld \tMax = %ld\n",     slong_min, slong_max);
    printf("\n");
    printf("unsigned char  : Min = %u  \t\t\tMax = %u\n",  0, uchar_max);
    printf("unsigned short : Min = %u  \t\t\tMax = %u\n",  0, ushort_max);
    printf("unsigned int   : Min = %u  \t\t\tMax = %u\n",  0, uint_max);
    printf("unsigned long  : Min = %lu \t\t\tMax = %lu\n", 0UL, ulong_max);

    //Floating point computations

    return 0;
}
