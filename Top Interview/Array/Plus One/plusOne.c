// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/559/

// Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

// You may assume the integer does not contain any leading zero, except the number 0 itself.

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    *returnSize = digitsSize;
    int i, rem = 1, d;
    for (i = digitsSize - 1; i >= 0; i--)
    {
        if (digits[i] != 9)
        {
            break;
        }
        if (i == 0 && digits[0] == 9)
        {
            int *res = (int *)calloc(digitsSize + 1, sizeof(int));
            res[0] = 1;
            (*returnSize)++;
            return res;
        }
    }
    for (i = digitsSize - 1; i >= 0; i--)
    {
        d = digits[i];
        digits[i] = (d + rem) % 10;
        rem = (d + rem) / 10;
    }
    return digits;
}

int main()
{
    int a[2] = {1, 0};
    int a1[3] = {9, 9, 9};
    int *resS;
    int *b = plusOne(a, 2, resS);
    int i;
    printf("a:\t");
    for (i = 0; i < *resS; i++)
    {
        printf("%d\t", b[i]);
    }
    b = plusOne(a1, 3, resS);
    printf("\na1:\t");
    for (i = 0; i < *resS; i++)
    {
        printf("%d\t", b[i]);
    }
    return 0;
}