#include <stdio.h>
#include <stdbool.h>

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isValidBSTHelper(struct TreeNode *root, long int min, long int max)
{
    if (root)
    {
        if (min < root->val && max > root->val)
            return isValidBSTHelper(root->left, min, root->val) && isValidBSTHelper(root->right, root->val, max);
        else
            return false;
    }
    else
        return true;
}
bool isValidBST(struct TreeNode *root)
{
    return isValidBSTHelper(root, -10000000000, 10000000000);
}