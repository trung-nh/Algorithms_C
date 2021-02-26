// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/884/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int myAtoi(char *s)
{
    int i = 0, sign = 1, res = 0, n = strlen(s);
    //skip leading white spaces
    while (s[i] == ' ' || s[i] == '\t')
    {
        i++;
    }
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }
    while (i < n)
    {
        if (!isdigit(s[i]))
        {
            break;
        }

        if (res < INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' <= 7))
        {
            res = res * 10 + (s[i] - '0');
        }
        else
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        i++;
    }
    return sign * res;
}

int main()
{
    char maxInt[23] = "  214748364700000asssf";
    char minInt[38] = "                 -21474836495959abcde";
    printf("%d\n", myAtoi(maxInt));
    printf("%d\n", myAtoi(minInt));
    return 0;
}