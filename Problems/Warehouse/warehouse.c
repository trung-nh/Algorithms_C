//https://codeforces.com/group/Ir5CI6f3FD/contest/276073/problem/J

#include <stdio.h>

void solve()
{
    int n, T, D, rs, i, j, d, k;
    FILE *fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d%d%d", &n, &T, &D);
    int a[n], t[n];
    int s[n][T + 1];
    for (i = 0; i <= n - 1; i++)
    {
        fscanf(fptr, "%d", &a[i]);
    }
    for (i = 0; i <= n - 1; i++)
    {
        fscanf(fptr, "%d", &t[i]);
    }
    for (k = 0; k <= T; k++)
    {
        if (k != t[0])
            s[0][k] = 0;
        else
            s[0][k] = a[0];
    }
    for (i = 1; i < n; i++)
    {
        for (k = 0; k <= T; k++)
        {
            if (k != t[i])
            {
                s[i][k] = 0;
            }
            else
            {
                s[i][k] = a[i];
            }

            for (d = 1; d <= D; d++)
            {
                j = i - d;
                if (j >= 0 && k >= t[i] && s[j][k - t[i]] > 0)
                {
                    if (s[i][k] < s[j][k - t[i]] + a[i])
                        s[i][k] = s[j][k - t[i]] + a[i];
                }
            }
        }
    }
    rs = 0;
    for (i = 0; i < n; i++)
    {
        for (k = 0; k <= T; k++)
        {
            if (s[i][k] > rs)
            {
                rs = s[i][k];
            }
        }
    }
    fptr = fopen("output.txt", "w");
    fprintf(fptr, "%d", rs);
    fclose(fptr);
}

int main()
{
    solve();
    return 0;
}
