// https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/
#include <stdio.h>

// LIS[i] return the longest increasing subsequence up to index i
// LDS[i] return the longest decreasing subsequence from index i
int lbs();

int max(int a, int b);

int main()
{
    int res;
    res = lbs();
    FILE *fptr = fopen("output.txt", "w");
    fprintf(fptr, "%d", res);
    fclose(fptr);
    return 0;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int lbs()
{
    FILE *fptr = fopen("input.txt", "r");
    int i, j, res = 0, n;
    fscanf(fptr, "%d", &n);
    int arr[n], LIS[n], LDS[n];
    for (i = 1; i <= n; i++)
    {
        fscanf(fptr, "%d", &arr[i]);
        LIS[i] = 1;
        for (j = 1; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
        // printf("lis i = %d: %d\n", i, LIS[i]);
        printf(" %d\n", arr[i]);
    }
    LDS[n] = 1;
    for (i = n - 1; i >= 1; i--)
    {
        LDS[i] = 1;
        for (j = n; j > i; j--)
        {
            if (arr[i] > arr[j])
            {
                LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }
        // printf("lds i = %d: %d\n", i, LDS[i]);
    }
    for (i = 1; i <= n; i++)
    {
        res = max(LIS[i] + LDS[i] - 1, res);
    }
    return res;
}
