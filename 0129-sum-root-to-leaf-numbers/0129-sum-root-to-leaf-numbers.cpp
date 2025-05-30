class Solution
{
public:
    int recur(TreeNode* node, int sum)
    {
        if(node == NULL) return 0;
        if(node->left == NULL && node->right == NULL)
            return ((sum * 10) + node->val);
        int res = recur(node->left, (sum * 10) + node->val);
        res += recur(node->right, (sum * 10) + node->val);
        return res;
    }
    int sumNumbers(TreeNode* root)
    {
        return recur(root, 0);
    }
};