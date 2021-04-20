// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/674/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    /* to prevent overflow */
    if (*(int *)a > *(int *)b)
        return 1;
    else if (*(int *)a < *(int *)b)
        return -1;
    return 0;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    *returnSize = 0;
    int *res = (int *)malloc(sizeof(int));
    qsort(nums1, nums1Size, sizeof(int), cmpfunc);
    qsort(nums2, nums2Size, sizeof(int), cmpfunc);
    int i1 = 0, i2 = 0;
    while (i1 < nums1Size && i2 < nums2Size)
    {
        if (nums1[i1] < nums2[i2])
        {
            i1++;
        }
        else if (nums1[i1] > nums2[i2])
        {
            i2++;
        }
        else
        {
            res = realloc(res, sizeof(int) * (*returnSize + 1));
            res[*returnSize] = nums1[i1++];
            (*returnSize)++;
            i2++;
        }
    }
    return res;
}

int main()
{
    int a[7] = {INT_MAX, INT_MIN, 3, 4, 5, 6, 7};
    int b[5] = {INT_MIN, 3, INT_MAX, 5, 6};
    int *size;
    int *res = intersect(a, 7, b, 5, size);
    int i;
    for (int i = 0; i < *size; i++)
    {
        printf("%d\t", res[i]);
    }
    printf("size=%d\n", *size);
    return 0;
}