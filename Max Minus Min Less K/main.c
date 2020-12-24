#include <stdio.h>

int max_index(int arr[], int i, int K);
int main()
{
    int i, j, n, K;
    FILE *fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d%d", &n, &K);
    int arr[n], ans = n, tmp;
    for (i = 0; i < n; i++)
    {
        fscanf(fptr, "%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        tmp = (n - (max_index(arr, i, K) - i + 1));
        if (tmp < ans)
        {
            ans = tmp;
        }
    }
    fptr = fopen("output.txt", "w");
    fprintf(fptr, "%d", ans);
    fclose(fptr);
    return 0;
}
int max_index(int arr[], int i, int K)
{
    int p = i + 1;
    while (arr[p] - arr[i] <= K)
    {
        p++;
    }
    return p - 1;
}