// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/

#include <stdio.h>

void reverseString(char *s, int sSize)
{
    if (sSize < 2)
    {
        return;
    }
    char tmp;
    int i;
    for (i = 0; i < sSize / 2; i++)
    {
        tmp = s[i];
        s[i] = s[sSize - 1 - i];
        s[sSize - 1 - i] = tmp;
    }
}