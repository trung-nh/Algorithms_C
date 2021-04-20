#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    unsigned capacity;
    int *array;
} Stack_t;

// function to create a stack of given capacity. It initializes size of
// stack as 0
Stack_t *createStack(unsigned capacity)
{
    Stack_t *stack = (Stack_t *)malloc(sizeof(Stack_t));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(Stack_t *stack)
{
    return (stack->top == stack->capacity - 1);
}

// Stack is empty when top is equal to -1
int isEmpty(Stack_t *stack)
{
    return stack->top == -1;
}

// Function to add an item to stack.  It increases top by 1
void push(Stack_t *stack, int item)
{
    if (isFull(stack))
    {
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
int pop(Stack_t *stack)
{
    if (isEmpty(stack))
    {
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
int peek(Stack_t *stack)
{
    if (isEmpty(stack))
    {
        return INT_MIN;
    }
    return stack->array[stack->top];
}
