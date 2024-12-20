class Solution
{
private:
    void dfs(TreeNode* l, TreeNode* r, int lvl)
    {
        if(l == nullptr || r == nullptr) return;
        if(lvl & 1) swap(l->val, r->val);
        dfs(l->left, r->right, lvl + 1);
        dfs(l->right, r->left, lvl + 1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root)
    {
        dfs(root->left, root->right, 1);
        return root;
    }
};