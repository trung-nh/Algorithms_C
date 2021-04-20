#include <stdio.h>
int max(int a, int b);
int main(void)
{
    int n, i, j, ans = 1;
    FILE *fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d", &n);
    int arr[n], dp[n];
    for (i = 1; i <= n; i++)
    {
        fscanf(fptr, "%d", &arr[i]);
        dp[i] = 1;
        for (j = 1; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (dp[i] > ans)
        {
            ans = dp[i];
        }
    }
    fptr = fopen("output.txt", "w");
    fprintf(fptr, "%d", ans);
    fclose(fptr);
    return 0;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}