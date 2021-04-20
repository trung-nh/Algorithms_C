// https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/572/
// You are given an array prices where prices[i] is the price
// of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing
// a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot
// achieve any profit, return 0.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}
// valley-peak approach
int maxProfit(int *prices, int pricesSize)
{
    if (pricesSize < 2)
    {
        return 0;
    }
    int min_price = INT_MAX;
    int max = 0;
    int i;
    for (i = 0; i < pricesSize; i++)
    {
        // Unless prices rise, code will never reach 'else if' scope
        if (prices[i] < min_price)
        {
            min_price = prices[i];
        }
        else if (prices[i] - min_price > max)
        {
            max = prices[i] - min_price;
        }
    }
    return max;
}
// DP approach
// int maxProfit_dp(int *prices, int pricesSize)
// {
//     if (pricesSize < 2)
//     {
//         return 0;
//     }
//     int min_price;
//     // bottom-up (tabulation) => tabula[i] stores the max profit if we SELL ON DAY Ith
//     int *tabula = (int *)calloc(pricesSize, sizeof(int));
//     min_price = (prices[0] < prices[1]) ? prices[0] : prices[1];
//     int i;
//     for (i = 1; i < pricesSize; i++)
//     {
//         tabula[i] = max(tabula[i - 1], prices[i] - min_price);
//         if (min_price > prices[i])
//         {
//             min_price = prices[i];
//         }
//     }
//     i = tabula[pricesSize - 1];
//     free(tabula);
//     return i;
// }

int main()
{
    int a[6] = {7, 1, 5, 6, 2, 9};
    int b[10] = {7, 4, 5, 6, 2, 9, 7, 8, 1, 9};
    // decresing arr
    int c[5] = {5, 4, 3, 2, 1};
    printf("------- DP approach -------\n");
    printf("%d\n", maxProfit_dp(a, sizeof(a) / sizeof(int))); // 9-1=8
    printf("%d\n", maxProfit_dp(b, sizeof(b) / sizeof(int))); // 9-1=8
    printf("%d\n", maxProfit_dp(c, sizeof(c) / sizeof(int))); // 0
    printf("------- Peak-Valley approach -------\n");
    printf("%d\n", maxProfit(a, sizeof(a) / sizeof(int))); // 9-1=8
    printf("%d\n", maxProfit(b, sizeof(b) / sizeof(int))); // 9-1=8
    printf("%d\n", maxProfit(c, sizeof(c) / sizeof(int))); // 0
    return 0;
}