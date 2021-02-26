// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isAnagram(char *s, char *t)
{
    int slen = strlen(s);
    int tlen = strlen(t);
    if (slen != tlen)
    {
        return false;
    }
    int *alphab = (int *)calloc(26, sizeof(int));
    int i;
    for (i = 0; i < slen; i++)
    {
        alphab[s[i] - 'a'] += 1;
    }
    for (i = 0; i < tlen; i++)
    {
        alphab[t[i] - 'a'] -= 1;
    }
    for (i = 0; i < 26; i++)
    {
        if (alphab[i] > 0)
        {
            free(alphab);
            return false;
        }
    }
    free(alphab);
    return true;
}
int main()
{
    char *s = "vietnam";
    char *t = "tienvam";
    if(isAnagram(s,t)){
        printf("True\n");
    }
    return 0;
}