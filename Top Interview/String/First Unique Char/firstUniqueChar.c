// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int firstUniqChar(char *s)
{
    // can't do better than O(N)
    int *alphab = (int *)calloc(26, sizeof(int));

    int i, slen = strlen(s);
    for (i = 0; i < slen; i++)
    {
        alphab[s[i] - 'a'] += 1;
    }

    for (i = 0; i < slen; i++)
    {
        if (alphab[s[i] - 'a'] == 1)
        {
            free(alphab);
            return i;
        }
    }
    free(alphab);
    return -1;
}

int main()
{
    char str[8] = "leetcode";
    printf("ans=%d\n", firstUniqChar(str));
    printf("%d %d\n", 'a', 'z' - 97);
    return 0;
}