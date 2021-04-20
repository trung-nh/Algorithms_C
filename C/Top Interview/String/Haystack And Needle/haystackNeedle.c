// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/885/
#include <stdio.h>
#include <string.h>

int strStr(char *haystack, char *needle)
{
    int nLen = strlen(needle);
    int hLen = strlen(haystack);
    if (nLen == 0)
    {
        return 0;
    }
    int i, j;
    for (i = 0; i < hLen - nLen + 1; i++)
    {
        for (j = 0; j < nLen; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                break;
            }
            if (j == nLen - 1 && haystack[i + j] == needle[j])
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    char *h = "helloworld";
    char *n = "low";
    int res = strStr(h,n);
    printf("%d\n", res);
    return 0;
}