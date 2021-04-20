// https://leetcode.com/problems/jewels-and-stones/
#include <stdio.h>
#include <string.h>

int numJewelsInStones(char *J, char *S)
{
    int i, j;
    int slen = strlen(S);
    int jlen = strlen(J);
    int jewelCount = 0;
    for (i = 0; i < slen; i++)
    {
        for (j = 0; j < jlen; j++)
        {
            if (S[i] == J[j])
            {

                jewelCount++;
            }
        }
    }
    return jewelCount;
}

int main()
{
    char *j = "aA";
    char *s = "aAAbbbb";
    printf("%d", numJewelsInStones(j, s));
    return 0;
}