// https://leetcode.com/problems/longest-substring-without-repeating-characters

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 256

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int lengthOfLongestSubstring(char *s)
{
    if (strlen(s) == 0)
    {
        return 0;
    }
    int i, j;
    int res = 0, n = strlen(s);
    for (i = 0; i < n; i++)
    {
        bool *repeated = (bool *)calloc(MAX, sizeof(bool));
        for (j = i; j < n; j++)
        {
            if (repeated[(int)s[j]] == true)
            {
                break;
            }
            else
            {
                res = max(res, j - i + 1);
                repeated[(int)s[j]] = true;
            }
        }
        free(repeated);
    }
    return res;
}

int main()
{
    char *s = "zzavA25!@&*/.,Baklj";
    int res = lengthOfLongestSubstring(s);
    printf("%d", res);
    return 0;
}