class Solution
{
public:

    int recur(TreeNode* node, int dir)
    {
        // dir == 0 means its a root, no parent
        // dir == -1 means i'm a left child of my parent
        // dir == 1 means i'm a right child of my parent

        if(node == NULL) return 0;
        if(node->left == NULL && node->right == NULL && dir == -1) return node->val;
        int res = recur(node->left, -1);
        res += recur(node->right, 1);
        return res;
    }

    int sumOfLeftLeaves(TreeNode* root)
    {
        return recur(root, 0);
    }
};