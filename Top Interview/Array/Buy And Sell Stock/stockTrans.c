// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/

// You are given an array prices for which the ith element is the price of a given stock on day i.

// Find the maximum profit you can achieve. You may complete as many transactions as you like
// (i.e., buy one and sell one share of the stock multiple times).

// Note: You may not engage in multiple transactions simultaneously
// (i.e., you must sell the stock before you buy again).

#include <stdio.h>

int maxProfit(int *prices, int pricesSize)
{
    int res = 0;
    int i;
    for (i = 1; i < pricesSize; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            res += prices[i] - prices[i - 1];
        }
    }
    return res;
}

int maxProfit_(int *prices, int pricesSize)
{
    if (pricesSize < 2)
    {
        return 0;
    }
    int res = 0;
    int i, peak = prices[0], low = prices[0];
    for (i = 1; i < pricesSize; i++)
    {
        // find valley point
        while (i < pricesSize && prices[i] < prices[i - 1])
        {
            i++;
        }
        low = prices[i - 1];
        // find peak point
        while (i < pricesSize && prices[i] > prices[i - 1])
        {
            i++;
        }
        peak = prices[i - 1];
        res += peak - low;
    }
    return res;
}

int main()
{
    int price[10] = {100, 10, 20, 15, 35, 55, 75, 10, 40, 30};
    printf("%d\n", maxProfit(price, 10));
    printf("%d\n", maxProfit_(price, 10));
    return 0;
}