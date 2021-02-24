// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/

// Given a sorted array nums, remove the duplicates in-place such that
// each element appears only once and returns the new length.

// Do not allocate extra space for another array, you must do this by
// modifying the input array in-place with O(1) extra memory.

// Nums is sorted in ascending order.
#include <stdio.h>

int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 0 || nums == NULL)
    {
        return 0;
    }
    if (numsSize == 1)
    {
        return 1;
    }
    int i = 0, j;
    for (j = 1; j < numsSize; j++)
    {
        if (nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    if (i + 1 < numsSize)
    {
        nums[i + 1] = '\0';
    }
    return i + 1;
}

int main()
{
    int i;
    int a[10] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5};
    int b[2] = {1, 2};
    int asize = removeDuplicates(a, 10);
    int bsize = removeDuplicates(b, 2);
    for (i = 0; i < asize; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    for (i = 0; i < bsize; i++)
    {
        printf("%d\t", b[i]);
    }
    return 0;
}