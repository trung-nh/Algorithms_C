#include <stdio.h>
#include <stdlib.h>

int abs(int n)
{
    return (n > 0) ? n : -n;
}
// Naive approach
int threeSumClosest(int *nums, int numsSize, int target)
{
    int i, j, k, diff = 99999, res;
    for (i = 0; i < numsSize - 2; i++)
    {
        for (j = i + 1; j < numsSize - 1; j++)
        {
            for (k = j + 1; k < numsSize; k++)
            {
                if (abs(nums[i] + nums[j] + nums[k] - target) <= diff)
                {
                    res = nums[i] + nums[j] + nums[k];
                    diff = abs(nums[i] + nums[j] + nums[k] - target);
                }
            }
        }
    }
    return res;
}

// 2-pointer approach

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int threeSumClosest(int *nums, int numsSize, int target)
{
    int closest_sum = 999999;
    int ptr1, ptr2, i, cur_sum;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for (i = 0; i < numsSize; i++)
    {
        ptr1 = i + 1;
        ptr2 = numsSize - 1;
        while (ptr1 < ptr2)
        {
            cur_sum = nums[i] + nums[ptr1] + nums[ptr2];
            if (abs(cur_sum - target) < abs(closest_sum - target))
            {
                closest_sum = cur_sum;
            }
            if (cur_sum > target)
            {
                ptr2--;
            }
            else
            {
                ptr1++;
            }
        }
    }
    return closest_sum;
}