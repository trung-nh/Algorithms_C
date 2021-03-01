// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/603/
#include <stdio.h>
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};
// Approach 1 (Faster)
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *res = head;
    int i, count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    head = res;
    for (i = 0; i < count - n; i++)
    {
        head = head->next;
    }
    if (n != 1)
    {
        head->next = head->next->next;
    }
    else
    {
        head->next = NULL;
    }
    return res;
}

// Approach 2 (Slower)
// struct ListNode *