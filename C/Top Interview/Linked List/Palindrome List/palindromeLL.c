
#include <stdio.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode *head)
{
    // LL length  < 2
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    // LL length >= 2
    struct ListNode *firstHalf, *secondHalf, *checkEnd, *tmp;
    firstHalf = NULL;
    secondHalf = head;
    checkEnd = head;
    while (checkEnd != NULL && checkEnd->next != NULL)
    {
        // checkEnd jump 2 steps ech iteration
        checkEnd = checkEnd->next->next;
        tmp = secondHalf;
        secondHalf = secondHalf->next;
        tmp->next = firstHalf;
        firstHalf = tmp;
    }
    // By the time checkEnd reach NULL ptr or the last node, firstHalf'll point to the
    // start of the first half (which has already been reversed) & secondHalf'll reach
    // the start of the second half OR the node between the 2 halves

    // check odd number of nodes in the original LL
    if (checkEnd != NULL)
    {
        secondHalf = secondHalf->next;
    }
    while (firstHalf != NULL && secondHalf != NULL)
    {
        if (firstHalf->val != secondHalf->val)
        {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}