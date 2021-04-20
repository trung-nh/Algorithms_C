// https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/743/

// Write a program that outputs the string representation of numbers from 1 to n.

// But for multiples of three it should output “Fizz” instead of the number and for
// the multiples of five output “Buzz”. For numbers which are multiples of both
// three and five output “FizzBuzz”.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define N "%d"
#define F "Fizz"
#define B "Buzz"

const char *const FMT[] = {N, N, F, N, B, F, N, N, F, B, N, F, N, N, F B};

char **fizzBuzz(const int n, int *const retSize)
{
    char **ret;
    int i, j;

    ret = malloc((*retSize = n) * sizeof(char *));
    for (i = j = 0; i < n; ++i, j = (j == 14) ? 0 : j + 1)
    {
        (void)sprintf(ret[i] = malloc(9 * sizeof(char)), FMT[j], i + 1);
    }
    return ret;
}

int main()
{
    char **res;
    int *resSize;
    res = fizzBuzz(30, resSize);
    int i;
    for (i = 0; i < *resSize; i++)
    {
        printf("%d: %s\n", i + 1, res[i]);
    }
    return 0;
}