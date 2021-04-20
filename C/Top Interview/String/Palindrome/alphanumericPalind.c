// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/
// Given a string s, determine if it is a palindrome,
//  considering only alphanumeric characters and ignoring cases.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isPalindrome(char *s)
{
    int l = strlen(s);
    int alpnumCount = 0, i, j, track = 0;
    for (i = 0; i < l; i++)
    {
        s[i] = tolower(s[i]);
    }
    for (i = 0; i < l; i++)
    {
        if (isalnum(s[i]))
        {
            alpnumCount++;
        }
    }
    i = 0;
    j = l - 1;
    while (track < alpnumCount / 2)
    {
        while (!isalnum(s[i]))
        {
            i++;
        }
        while (!isalnum(s[j]))
        {
            j--;
        }
        if (s[i] != s[j])
        {
            return false;
        }
        else
        {
            track++;
            i++;
            j--;
        }
    }
    return true;
}

int main(){
    char s[52]="1102A m^&an, a p!#La$>n, a C<--->Anal::> Panama2011";
    if(isPalindrome(s)){
        printf("Palind!\n");
    }
    return 0;
}