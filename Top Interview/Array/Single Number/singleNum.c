// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

//O(n^2)
int singleNumber(int *nums, int numsSize)
{
    if (numsSize < 2)
    {
        return nums[0];
    }
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int i;
    for (i = 0; i < numsSize - 2; i += 2)
    {
        if (nums[i] != nums[i + 1])
        {
            return nums[i];
        }
    }
    return nums[numsSize - 1];
}

// O(n) Using XOR bit "^"
int singleNumber_XOR(int *nums, int numsSize)
{
    int res = 0, i;
    for (i = 0; i < numsSize; i++)
    {
        res ^= nums[i];
    }
    return res;
}

int main(){
    int nums[7]= {9,11,2,9,11,365,365};
    printf("res=%d\n",singleNumber_XOR(nums,7));
    printf("11 XOR 11 =%d\n", 11^11);
    printf("11 XOR 0 =%d\n", 11^0);
    printf("11 XOR 11 XOR 2 =%d\n", 11^11^2);
    printf("11 XOR 11 XOR 0 =%d\n", 11^11^0);
    return 0;
}