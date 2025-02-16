class Solution
{
private:
    TreeNode* recur(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if(node == NULL) return NULL;
        TreeNode * one = recur(node->left, p, q);
        TreeNode * two = recur(node->right, p, q);
        if(one == NULL && two == NULL)
            if(node == p || node == q) return p; else return NULL;
        if(one != NULL && two != NULL) return node;
        if(node == p || node == q) return node;
        if(one == NULL) return two; return one;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return recur(root, p, q);
    }
};