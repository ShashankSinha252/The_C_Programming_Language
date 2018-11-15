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

#define SIZE_ARR(x)     (sizeof(x)/sizeof(x[0]))

int binsearch(int x, int v[], int n);

int main(void)
{
    int input_arr[] = {20, 30, 40, 50, 60, 70, 80, 90, 100};
    int search_arr[] = {20, 22, 50, 45, 32,89,
                        60, 100, 53, 70, 90, 40};

    int result;
    unsigned int ctr;
    for(ctr = 0; ctr < SIZE_ARR(search_arr); ctr++)
    {
        result = binsearch(search_arr[ctr], input_arr, SIZE_ARR(input_arr));
        printf("Position of %d in input_arr: %d\n", search_arr[ctr], result);
    }

    return 0;
}

/* Reusing debug flag for switching between functions */
#ifndef DEBUG
/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high)
    {
        mid = (low+high)/2;
        if (x < v[mid])
        {
            high = mid-1;
        }
        else if (x > v[mid])
        {
            low = mid+1;
        }
        else
        {
            return mid;
        }
    }
    return -1;  /* No match */
}
# else
/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid, retval;

    low = 0;
    high = n-1;
    retval = -1;

    while(low < high-1)
    {
        mid = (low+high)/2;
        if(x >= v[mid])
        {
            low = mid;
        }
        else
        {
            high = mid-1;
        }
    }

    if(x == v[low])
    {
        retval = low;
    }
    else if(x == v[low+1])
    {
        retval = low+1;
    }

    return retval;
}
#endif
