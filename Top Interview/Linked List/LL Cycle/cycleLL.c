// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/773/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

// Floyd's Cycle Finding Algorithm
bool hasCycle(struct ListNode *head)
{
    // LL len < 2
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    struct ListNode *hare, *tortoise;
    tortoise = head;
    hare = head->next->next;
    while (hare != tortoise)
    {
        if (hare == NULL || hare->next == NULL)
        {
            return false;
        }
        tortoise = tortoise->next;
        hare = hare->next->next;
    }
    return true;
}
