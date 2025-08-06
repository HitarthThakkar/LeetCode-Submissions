/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int recur(struct TreeNode* node, int dir)
{
    if(node == NULL) return 0;
    if(node->left == NULL && node->right == NULL && dir == -1) return node->val;
    int res = recur(node->left, -1);
    res += recur(node->right, 1);
    return res;
}

int sumOfLeftLeaves(struct TreeNode* root) {
    return recur(root, 0);
}