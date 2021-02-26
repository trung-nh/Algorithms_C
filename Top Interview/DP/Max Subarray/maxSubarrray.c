
#include <stdio.h>

int maxSubArray(int *nums, int numsSize)
{
    if (numsSize < 1)
    {
        return 0;
    }
    int res = nums[0];
    int cur_sum = nums[0];
    int i;
    for (i = 1; i < numsSize; i++)
    {
        if (cur_sum < 0)
        {
            cur_sum = 0;
        }
        cur_sum += nums[i];
        if (cur_sum > res)
        {
            res = cur_sum;
        }
    }
    return res;
}

int main()
{
    int a[7] = {1, -5, 7, -2, 6, -9, 8};
    int b[7] = {-7, -8, -5, -1, -2, -10, -3};
    int c[2] = {-2, 1};
    printf("max subArr of a = %d\n", maxSubArray(a, 7)); // 7+(-2) +6
    printf("max subArr of b = %d\n", maxSubArray(b, 7)); // -1
    printf("max subArr of c = %d\n", maxSubArray(c, 7)); // 1
    return 0;
}