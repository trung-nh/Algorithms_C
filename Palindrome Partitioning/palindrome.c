#include <stdio.h>
#include <string.h>
#include <limits.h>

int minPalPartition(char str[]);
int min(int a, int b);
int main()
{
    int n;
    FILE *fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d", &n);
    char str[n];
    fscanf(fptr, "%s", str);
    fptr = fopen("output.txt", "w");
    fprintf(fptr, "%d", minPalPartition(str));
    fclose(fptr);
    return 0;
}
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int minPalPartition(char str[])
{
    int n = strlen(str), i, j, k, L;
    int isPalin[n][n], minParti[n][n];
    // string of len = 1
    for (i = 0; i < n; i++)
    {
        isPalin[i][i] = 1;
        minParti[i][i] = 0;
    }
    // string of len greater than 1
    for (L = 2; L <= n; L++)
    {
        for (i = 0; i <= n - L; i++)
        {
            j = i + L - 1;
            // handle isPalin[]
            if (L == 2)
            {
                if (str[i] == str[j])
                {
                    isPalin[i][j] = 1;
                }
                else
                {
                    isPalin[i][j] = 0;
                }
            }
            else
            {
                if (str[i] == str[j] && isPalin[i + 1][j - 1] == 1)
                {
                    isPalin[i][j] = 1;
                }
                else
                {
                    isPalin[i][j] = 0;
                }
            }
            // handle minParti[]
            if (isPalin[i][j] == 1)
            {
                minParti[i][j] = 0;
            }
            else
            {
                minParti[i][j] = INT_MAX;
                for (k = i; k <= j - 1; k++)
                {
                    minParti[i][j] = min(minParti[i][j], minParti[i][k] + 1 + minParti[k + 1][j]);
                }
            }
        }
    }
    return minParti[0][n - 1];
}