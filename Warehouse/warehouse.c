#include <stdio.h>

#define maxn 1001

int a[maxn], t[maxn];
int s[maxn][maxn];
int n, T, D, rs, i, j, d, k;

void input()
{
    FILE *fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d%d%d", &n, &T, &D);
    for (i = 0; i <= n - 1; i++)
        fscanf(fptr, "%d", &a[i]);
    for (i = 0; i <= n - 1; i++)
        fscanf(fptr, "%d", &t[i]);
}
void solve()
{
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
        printf("\n", i);
        for (k = 0; k <= T; k++)
        {
            printf("%d\t", s[i][k]);
            if (s[i][k] > rs)
            {
                rs = s[i][k];
            }
        }
    }
    printf("%d", rs);
}

int main()
{
    input();
    solve();
    return 0;
}
