// https://leetcode.com/problems/longest-substring-without-repeating-characters
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int i = 0, j;
    int res = 0, n = strlen(s);
    int *lastId = (int *)malloc(MAX * sizeof(int));
    for (i = 0; i < n; i++)
    {
        lastId[(int)s[i]] = -1;
    }
    i = 0;
    // i stores starting id, j stores ending id
    for (j = 0; j < n; j++)
    {
        i = max(i, lastId[(int)s[j]] + 1);
        res = max(res, j - i + 1);
        lastId[(int)s[j]] = j;
    }
    free(lastId);
    return res;
}

int main()
{
    char *s = "a!@#$%^&*()_?>< 08a";
    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}