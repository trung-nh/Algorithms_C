// https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/587/

// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

// The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume
// that nums1 has a size equal to m + n such that it has enough space to hold additional elements
// from nums2.
#include <stdio.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{

    int i, j = 0, tmp, k = 0;
    for (i = m + n - 1; i >= n; i--)
    {
        nums1[i] = nums1[i - n];
    }
    i = n;
    while (i < n + m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            nums1[k++] = nums1[i++];
        }
        else
        {
            nums1[k++] = nums2[j++];
        }
    }
    if (i == n + m)
    {
        while (j < n)
        {
            nums1[k++] = nums2[j++];
        }
    }
    else
    {
        while (i < n + m)
        {
            nums1[k++] = nums1[i++];
        }
    }
}