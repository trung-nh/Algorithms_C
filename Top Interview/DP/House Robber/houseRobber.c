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
        return (nums[0] > nums[1]) ? nums[0] : nums[1];
    default:
        if (numsSize < 0)
        {
            return -1;
        }
        break;
    }
    // top-down memo approach :
    int memo[numsSize];
    memo[0] = nums[0];
    memo[1] = max(nums[0], nums[1]);
    memo[2] = max(nums[2] + nums[0], nums[1]);
    int *tmp_max = max(memo[1], memo[2]);
    return robMemo(nums, numsSize, memo, tmp_max);
}
int robMemo(int *nums, int numsSize, int *memo, int *max)
{
    int i;
    for (i = 3; i < numsSize; i++)
    {
        memo[i] = (memo[i - 3] > memo[i - 2]) ? memo[i - 3] : memo[i - 2];
        memo[i] += nums[i];
        *max = (memo[i] > (*max)) ? memo[i] : (*max);
    }
    return *max;
}

int main()
{

    return 0;
}