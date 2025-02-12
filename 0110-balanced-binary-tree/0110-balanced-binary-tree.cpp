class Solution
{
public:
    int recur(TreeNode* node)
    {
        if(node == NULL) return 0;
        int leftDepth = recur(node->left);
        int rightDepth = recur(node->right);
        if(leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1) return -1;
        return (max(leftDepth, rightDepth) + 1);
    }
    bool isBalanced(TreeNode* root)
    {
        return (recur(root) == -1 ? false : true);
    }
};