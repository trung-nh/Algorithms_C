// https://leetcode.com/problems/combination-sum/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Stack
{
    int top;
    unsigned capacity;
    int *array;
} Stack_t;

Stack_t *createStack(unsigned capacity)
{
    Stack_t *stack = (Stack_t *)malloc(sizeof(Stack_t));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to add an item to stack.  It increases top by 1
void push(Stack_t *stack, int item)
{
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
int pop(Stack_t *stack)
{
    return stack->array[stack->top--];
}

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
void findAllCombiSum(int *arr, int n, int target, int *resSizes, int **resColSizes, Stack_t *combi, int start, int **res)
{
    if (target < 0)
    {
        return;
    }
    if (target == 0)
    {
        int k;
        int const range = combi->top + 1;
        res[*resSizes] = malloc(sizeof(int) * (range));
        // to boost runtime we can fix resColSizes[0] = malloc(sizeof(int *)* 256)
        resColSizes[0] = realloc(resColSizes[0], ((*resSizes) + 1) * sizeof(int *));
        resColSizes[0][(*resSizes)] = range;
        for (k = 0; k < range; k++)
        {
            res[*resSizes][k] = combi->array[k];
        }
        (*resSizes)++;
        return;
    }
    while (start < n && target - arr[start] >= 0)
    {
        push(combi, arr[start]);
        findAllCombiSum(arr, n, target - arr[start], resSizes, resColSizes, combi, start, res);
        start++;
        pop(combi);
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **combinationSum(int *arr, int arrSize, int target, int *resSizes, int **resColSizes)
{
    if (arr == NULL || arrSize == 0)
    {
        return NULL;
    }
    qsort(arr, arrSize, sizeof(int), cmpfunc);
    int **res = (int **)malloc(sizeof(int *) * 256);
    // max size of stack = target/min
    Stack_t *combi = createStack(target / arr[0]);
    *resSizes = 0;
    resColSizes[0] = malloc(sizeof(int *));
    findAllCombiSum(arr, arrSize, target, resSizes, resColSizes, combi, 0, res);
    free(resColSizes);
    free(res);
    return res;
}
