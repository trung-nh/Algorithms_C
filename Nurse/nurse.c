// https://codeforces.com/group/Ir5CI6f3FD/contest/276073/problem/F

#include <stdio.h>

int plan_count_last_day_rest(int i, int k1, int k2);

int main()
{
    int n, k1, k2, i;
    scanf("%d%d%d", &n, &k1, &k2);
    printf("%d", plan_count_last_day_rest(n, k1, k2) + plan_count_last_day_rest(n + 1, k1, k2));
    return 0;
}
int plan_count_last_day_rest(int id, int k1, int k2)
{
    int res = 0, i;
    if (id == 0 || id == 1)
    {
        return 1;
    }
    if (id < 0)
    {
        return 0;
    }
    for (i = k1; i <= k2; i++)
    {
        res += plan_count_last_day_rest(id - i - 1, k1, k2);
    }
    return res;
}