// https://codeforces.com/group/Ir5CI6f3FD/contest/276073/problem/A

#include <stdio.h>

int max_in_range(int arr[], int a, int b);
int main()
{
    FILE *fptr = fopen("input.txt", "r");
    int n, l1, l2, i, j, ans = -9999;
    fscanf(fptr, "%d%d%d", &n, &l1, &l2);
    int incl[n], arr[n];
    for (i = 0; i < l1; i++)
    {
        fscanf(fptr, "%d", &arr[i]);
        incl[i] = arr[i];
    }
    for (i = l1; i < n; i++)
    {
        fscanf(fptr, "%d", &arr[i]);
        incl[i] = max_in_range(incl, i - l2, i - l1) + arr[i];

        if (incl[i] > ans)
        {
            ans = incl[i];
        }
    }
    fptr = fopen("output.txt", "w");
    fprintf(fptr, "%d", ans);
    fclose(fptr);
    return 0;
}

int max_in_range(int arr[], int a, int b)
{
    int i, r = -9999, id = a;
    if (a < 0)
    {
        id = 0;
    }
    for (i = id; i <= b; i++)
    {
        if (arr[i] > r)
        {
            r = arr[i];
        }
    }
    return r;
}