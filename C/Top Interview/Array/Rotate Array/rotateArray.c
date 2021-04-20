// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/
// Given an array, rotate the array to the right by k steps, where k is non-negative.

#include <stdio.h>
#include <stdlib.h>

void rotate(int *nums, int numsSize, int k)
{
    if (k < 1 || numsSize <= 1 || nums == NULL)
    {
        return;
    }
    k = k % numsSize;
    int *tmp = (int *)malloc(sizeof(int) * k);
    int i;
    for (i = 0; i < k; i++)
    {
        tmp[i] = nums[numsSize - k + i];
    }
    for (i = numsSize - 1; i > k - 1; i--)
    {
        nums[i] = nums[i - k];
    }
    for (i = 0; i < k; i++)
    {
        nums[i] = tmp[i];
    }
    free(tmp);
    return;
}
void reverse(int *nums, int numsSize)
{
    int tmp;
    int i;
    for (i = 0; i < numsSize / 2; i++)
    {
        tmp = nums[i];
        nums[i] = nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = tmp;
    }
}
void rotate_in_place(int *nums, int numsSize, int k)
{
    if (k % numsSize < 1 || numsSize <= 1 || nums == NULL)
    {
        return;
    }
    k = k % numsSize;
    // reverse the whole arr
    reverse(nums, numsSize);
    // reverse first k elements
    reverse(nums, k);
    //reverse last n-k elements
    reverse((nums + k), numsSize - k);
}

int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    // rotate(arr, 7, 2);
    rotate_in_place(arr, 7, 3);
    int i;
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}