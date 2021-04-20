#include <stdio.h>
#include <string.h>

void print_scs(char X[], char Y[], int lx, int ly);
int min(int a, int b);

int main()
{
    int i, lx, ly;
    FILE *fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d%d", &lx, &ly);
    char X[lx], Y[ly];
    fscanf(fptr, "%s%s", X, Y);
    fclose(fptr);
    print_scs(X, Y, lx, ly);
    return 0;
}
int min(int a, int b)
{
    return (a < b) ? a : b;
}

void print_scs(char X[], char Y[], int lx, int ly)
{
    int i, j;
    int dp[lx + 1][ly + 1];
    // find the length of scs
    for (i = 0; i <= lx; i++)
    {
        for (j = 0; j <= ly; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    //print scs
    int index = dp[lx][ly];
    char str[index];
    i = lx;
    j = ly;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            str[index - 1] = X[i - 1];
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            str[index - 1] = Y[j - 1];
            j--;
        }
        else
        {
            str[index - 1] = X[i - 1];
            i--;
        }
        index--;
    }
    while (i > 0)
    {
        str[index - 1] = X[i - 1];
        i--, index--;
    }
    while (j > 0)
    {
        str[index - 1] = Y[j - 1];
        j--, index--;
    }
    printf("%s", str);
}