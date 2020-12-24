#include <stdio.h>

void insertionSort(int list[], int size)
{
    int i, j;
    int next;
    for (i = 1; i < size; i++)
    {
        next = list[i];
        for (j = i - 1; j >= 0 && next < list[j]; j--)
        {
            list[j + 1] = list[j];
        }
        list[j + 1] = next;
    }
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, i, j = 1, max_rem = 0;
    FILE *fptr;
    fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        fscanf(fptr, "%d", &arr[i]);
    }
    insertionSort(arr, n);
    for (i = 0; i < n; i++)
    {
        while (j < n && arr[j] <= 2 * arr[i])
        {
            j++;
        }
        max_rem = max(max_rem, j - i);
    }
    fclose(fptr);
    fptr = fopen("output.txt", "w");
    fprintf(fptr, "%d", n - max_rem);
    return 0;
}