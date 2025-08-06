/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool RangeBasedRecur(struct TreeNode* node, long long int mini, long long int maxi)
{
    if(!node) return true;
    if(node->val > mini && node->val < maxi)
    {
        bool left = RangeBasedRecur(node->left, mini, node->val);
        bool right = RangeBasedRecur(node->right, node->val, maxi);
        return (left & right);
    }
    return false;
}

bool isValidBST(struct TreeNode* root) {
    return RangeBasedRecur(root, -1e16, 1e16);
}