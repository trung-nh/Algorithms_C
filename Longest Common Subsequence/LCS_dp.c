// https://codeforces.com/group/Ir5CI6f3FD/contest/276073/problem/Q

#include <stdio.h>

// DP
int max(int a, int b);
int lcs(int X[], int Y[], int n, int m);

void main()
{
    int n, m, i, res;
    FILE *fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d%d", &n, &m);
    int X[n], Y[m];
    for (i = 1; i <= n; i++)
    {
        fscanf(fptr, "%d", &X[i]);
    }
    for (i = 1; i <= m; i++)
    {
        fscanf(fptr, "%d", &Y[i]);
    }
    res = lcs(X, Y, n, m);
    fptr = fopen("output.txt", "w");
    fprintf(fptr, "%d", res);
    fclose(fptr);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(int X[], int Y[], int n, int m)
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