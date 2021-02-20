// https://leetcode.com/problems/number-of-good-pairs/
#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int combi(int n, int k)
{
    if (n == k || k == 0)
    {
        return 1;
    }
    return (combi(n - 1, k - 1) + combi(n - 1, k));
}
int numIdenticalPairs(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return 1;
    }
    if (numsSize < 1)
    {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int i, count = 1, res = 0;
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            count++;
            if (i == numsSize - 1)
            {
                res += combi(count, 2);
            }
        }
        else
        {
            if (count >= 2)
            {
                res += combi(count, 2);
                count = 1;
            }
        }
    }
    return res;
}
int main()
{
    int arr[6] = {1, 2,2,3,3,4};
    printf("%d\n", numIdenticalPairs(arr, 6));
    return 0;
}