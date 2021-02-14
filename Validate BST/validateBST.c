#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// bool isValidBST(struct TreeNode *root)
// {
//     static struct TreeNode *prev =  NULL;

//     if (root)
//     {
//         if(!isValidBST(root->left)){
//             return false;
//         }
//         if(prev!= NULL && root->val <= prev->val){
//             return false;
//         }
//         prev = root;
//         return isValidBST(root->right);
//     }
//     return true;
// }

// approach 2:
// int minVal(struct TreeNode *root){
//     if (root == NULL)
//     {
//         return INT_MAX;
//     }
//     int res = root->val;
//     if (root->left != NULL)
//     {
//         int maxl = root->left->val;
//         if (maxl < res)
//             res = maxl;
//     }
//     if (root->right != NULL)
//     {
//         int maxr = root->right->val;
//         if (maxr < res)
//             res = maxr;
//     }
//     return res;
// }

// int maxVal(struct TreeNode *root)
// {
//     if (root == NULL)
//     {
//         return INT_MIN;
//     }
//     int res = root->val;
//     if (root->left != NULL)
//     {
//         int maxl = root->left->val;
//         if (maxl > res)
//             res = maxl;
//     }
//     if (root->right != NULL)
//     {
//         int maxr = root->right->val;
//         if (maxr > res)
//             res = maxr;
//     }
//     return res;
// }

// bool isValidBST(struct TreeNode *root)
// {
//     if (root == NULL)
//         return true;
//     if (root->left != NULL && maxVal(root->left) >= root->val)
//     {
//         return false;
//     }
//     if (root->right != NULL && minVal(root->right) >= root->val)
//     {
//         return false;
//     }
//     if (!isValidBST(root->left) || !isValidBST(root->right))
//     {
//         return false;
//     }
//     return true;
// }

// approach 3:

bool checkBST(struct TreeNode *node, long min, long max)
{
    if (node == NULL)
    {
        return true;
    }
    const int val = node->val;
    return ((val > min) && (val < max)) &&
           checkBST(node->left, min, val) &&
           checkBST(node->right, val, max);
}

bool isValidBST(struct TreeNode *root)
{
    checkBST(root, INT_MIN, INT_MAX);
}
int main()
{
    struct TreeNode *r;
    r->val = 0;
    r->left = NULL;
    r->right = NULL;
    if (isValidBST(r))
    {
        printf("ok");
    }
    return 0;
}