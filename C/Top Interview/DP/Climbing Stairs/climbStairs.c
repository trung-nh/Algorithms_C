// https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/569/
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps.
// In how many distinct ways can you climb to the top?

#include<stdlib.h>

// dp[i]= dp[i-1]+dp[i-2]=> analogous to Fibonacci
int climbStairs(int n)
{
    if (n < 1)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int first = 1;
    int second = 2;
    for (int i = 3; i <= n; i++)
    {
        int third = first + second;
        first = second;
        second = third;
    }
    return second;
}