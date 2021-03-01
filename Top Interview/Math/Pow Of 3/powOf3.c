#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

// Slow
// bool isPowerOfThree(int n)
// {
//     if (n <= 0)
//     {
//         return false;
//     }
//     if (n == 1)
//     {
//         return true;
//     }
//     int multi = 3;
//     while (multi <= n)
//     {
//         if (multi == n)
//         {
//             return true;
//         }
//         if (multi <= INT_MAX / 3)
//         {
//             multi *= 3;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     return false;
// }

// Tricky
bool isPowerOfThree(int n)
{
    return n > 0 && 1162261467 % n == 0;
}

int main()
{
    printf("INT_MAX : %d\n", isPowerOfThree(INT_MAX));         //F
    printf("27 : %d\n", isPowerOfThree(27));                   //T
    printf("1162261467 : %d\n", isPowerOfThree(1162261467));   // T
    printf("-531441 : %d\n", isPowerOfThree(-531441));         //F
    printf("INT_MAX - 3 : %d\n", isPowerOfThree(INT_MAX - 3)); // F
    return 0;
}