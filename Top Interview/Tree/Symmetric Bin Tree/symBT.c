#include <stdio.h>
#include <stdbool.h>

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Approach 1: A bit slower
bool dfs(struct TreeNode *node1, struct TreeNode *node2)
{
    if (node1 == NULL && node2 == NULL)
    {
        return true;
    }
    if (node1 == NULL || node2 == NULL)
    {
        return false;
    }
    return (node1->val == node2->val) 
    && dfs(node1->left, node2->right) 
    && dfs(node1->right, node2->left);
}

bool isSymmetric(struct TreeNode *root)
{
    return dfs(root->left, root->right);
}

