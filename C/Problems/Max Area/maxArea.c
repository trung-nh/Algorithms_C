// https://leetcode.com/problems/container-with-most-water/
#include <stdio.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int maxArea(int *height, int heightSize)
{
    if (heightSize <= 1)
    {
        return 0;
    }
    int *lptr, *rptr, res = 0;
    lptr = height;
    rptr = &height[heightSize - 1];
    while (lptr < rptr)
    {
        res = max(res, min(*lptr, *rptr) * (rptr - lptr));
        if (*lptr < *rptr)
        {
            lptr++;
        }
        else
        {
            rptr--;
        }
    }
    return res;
}

int main()
{
    int  arr[9] ={1,8,6,2,5,4,8,3,7};
    printf("%d\n",maxArea(arr,9));
    return 0;
}