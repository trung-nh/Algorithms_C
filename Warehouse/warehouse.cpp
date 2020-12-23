#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;

int a[maxn], t[maxn];
int s[maxn][maxn];
int n, T, D, rs;

void input()
{
    cin >> n >> T >> D;
    for (int i = 0; i <= n - 1; i++)
        cin >> a[i];
    for (int i = 0; i <= n - 1; i++)
        cin >> t[i];
}

void solve()
{
    for (int k = 0; k <= T; k++)
    {
        if (k != t[0])
            s[0][k] = 0;
        else
            s[0][k] = a[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int k = 0; k <= T; k++)
        {
            if (k != t[i])
                s[i][k] = 0;
            else
                s[i][k] = a[i];

            for (int d = 1; d <= D; d++)
            {
                int j = i - d;
                if (j >= 0 && k >= t[i] && s[j][k - t[i]] > 0)
                {
                    if (s[i][k] < s[j][k - t[i]] + a[i])
                        s[i][k] = s[j][k - t[i]] + a[i];
                }
            }
        }
    }
    rs = 0;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k <= T; k++)
        {
            if (s[i][k] > rs)
                rs = s[i][k];
        }
    }
    cout << rs;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
}
