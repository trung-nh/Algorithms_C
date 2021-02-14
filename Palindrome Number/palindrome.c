#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool oneDigit(int x)
{
    return (x < 10 && x >= 0);
};
bool isPalindUntil(int x, int *xptr)
{
    if (oneDigit(x))
    {
        return (x == (*xptr) % 10);
    }
    if (!isPalindUntil(x / 10, xptr))
    {
        return false;
    }
    (*xptr) /= 10;
    return (x % 10 == (*xptr) % 10);
}
bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    int *xptr = (int *)malloc(sizeof(x));
    xptr = &x;
    return (isPalindUntil(x, xptr));
}
int main()
{
    if(isPalindrome(101)) printf("101\n");
    return 0;
}