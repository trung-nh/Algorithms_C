#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }
    int rev = 0;
    while (rev < x)
    {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return (x == rev || x == (rev / 10));
}

int main()
{
    if(isPalindrome(120030021)) printf("yes");
    return 0;
}
