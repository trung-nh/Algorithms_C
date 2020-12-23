// https://codeforces.com/group/Ir5CI6f3FD/contest/276073/problem/Q

#include <stdio.h>

// RECURSION
int max(int a, int b);
int lcs(int X[], int Y[], int n, int m);

void main()
{
    int n, m, i, res;
    FILE *fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d%d", &n, &m);
    int X[n], Y[m];
    for (i = 0; i < n; i++)
    {
        fscanf(fptr, "%d", &X[i]);
    }
    for (i = 0; i < m; i++)
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
    if (n == 0 | m == 0)
    {
        return 0;
    }
    if (X[n - 1] == Y[m - 1])
    {
        return (1 + lcs(X, Y, n - 1, m - 1));
    }
    else
    {
        return max(lcs(X, Y, n - 1, m), lcs(X, Y, n, m - 1));
    }
}