// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/770/

// You are given an n x n 2D matrix representing an image,
// rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify
// the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

#include <stdio.h>
#include <stdlib.h>

void rotate(int **matrix, int n, int *matrixColSize)
{
    if (n <= 1)
    {
        *matrixColSize = 1;
        return;
    }
    int i, j, tmp;
    for (i = 0; i <= (n / 2 - 1); i++)
    {
        for (j = i; j <= (n - 2 - i); j++)
        {
            tmp = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = tmp;
        }
    }
    *matrixColSize = n;
    return;
}