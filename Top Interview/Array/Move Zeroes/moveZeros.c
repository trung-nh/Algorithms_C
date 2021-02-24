// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/567/
// Given an array nums, write a function to move all 0's
// to the end of it while maintaining the relative order of the non-zero elements.

// You must do this in-place.
#include <stdio.h>

void moveZeroes(int *nums, int numsSize)
{
    if (numsSize <= 1)
    {
        return;
    }
    /*Faster*/
    int i, lastNonZeroId = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            nums[lastNonZeroId++] = nums[i];
        }
    }
    for (i = lastNonZeroId; i < numsSize; i++)
    {
        nums[i] = 0;
    }

    /*Slower */
    // int i = 0, j = 1;
    // nums[i] &nums[j] keeps track of zeros and non-zeros respectively
    // while (i < numsSize - 1 && j < numsSize)
    // {
    //     while (nums[i] != 0 && i < numsSize - 1)
    //     {
    //         if (i == numsSize - 2)
    //         {
    //             return;
    //         }
    //         i++;
    //     }
    //     while (nums[j] == 0 && j < numsSize)
    //     {
    //         if (j == numsSize - 1)
    //         {
    //             return;
    //         }
    //         j++;
    //     }
    //     nums[i] = nums[j];
    //     nums[j] = 0;
    // }
}

int main()
{
    int a[10] = {4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
    moveZeroes(a, sizeof(a) / sizeof(a[0]));
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}