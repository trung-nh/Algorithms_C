// https://www.geeksforgeeks.org/shortest-common-supersequence/

#include <stdio.h>

int lcs(char X[], char Y[], int n, int m);
int scs(char X[], char Y[], int n, int m);
int max(int a, int b);

int main()
{
    int n, m, res, i;
    FILE *fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d%d", &n, &m);
    char X[n + 1], Y[m + 1];
    for (i = 1; i <= n; i++)
    {
        fscanf(fptr, "%s", &X[i]);
    }
    for (i = 1; i <= m; i++)
    {
        fscanf(fptr, "%c", &Y[i]);
    }
    res = scs(X, Y, n, m);
    printf("%d", res);
    fclose(fptr);
    return 0;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(char X[], char Y[], int n, int m)
{
    int dp[n + 1][m + 1];
    int i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if (i == 0 | j == 0)
            {
                dp[i][j] = 0;
            }
            else if (X[i] == Y[j])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
int scs(char X[], char Y[], int n, int m)
{
    return (n + m - lcs(X, Y, n, m));
}