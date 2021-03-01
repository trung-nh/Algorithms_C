// https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/576/
// You are a professional robber planning to rob houses along a street. Each house has a
// certain amount of money stashed, the only constraint stopping you from robbing each of
// them is that adjacent houses have security system connected and it will automatically
// contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house,
// determine the maximum amount of money you can rob tonight without alerting the police.

#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int rob(int *nums, int numsSize)
{
    switch (numsSize)
    {
    case 0:
        return 0;
    case 1:
        return nums[0];
    case 2:
        return max(nums[0], nums[1]);
    case 3:
        return max(nums[0] + nums[2], nums[1]);
    default:
        if (numsSize < 0)
        {
            return -1;
        }
        break;
    }
    // bottom-up approach :
    int tabula[numsSize];
    tabula[0] = nums[0];
    tabula[1] = max(nums[0], nums[1]);
    tabula[2] = max(nums[2] + nums[0], nums[1]);
    int i, res;
    res = max(tabula[2], tabula[1]);
    for (i = 3; i < numsSize; i++)
    {
        // Key
        tabula[i] = max(tabula[i - 2], tabula[i - 3]) + nums[i];
        res = max(res, tabula[i]);
    }
    return res;
}

int main()
{
    int a[7] = {10, 2, 5, 7, 20, 5, 10};
    int b[7] = {5, 100, 6, 1, 200, 210, 10};
    printf("res a = %d\n", rob(a, sizeof(a) / sizeof(int))); // 45
    printf("res b = %d\n", rob(b, sizeof(b) / sizeof(int))); // 100+1+210 = 311
    return 0;
}