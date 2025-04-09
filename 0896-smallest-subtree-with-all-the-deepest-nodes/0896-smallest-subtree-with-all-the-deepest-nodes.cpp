class Solution
{
public:
    pair<TreeNode*, int> dfs(TreeNode* root)
    {
        if (!root) return {nullptr, 0};

        auto left = dfs(root->left);    // {lca_of_left, depth_of_left}
        auto right = dfs(root->right);  // {lca_of_right, depth_of_right}

        // left is deeper
        if (left.second > right.second) return {left.first, left.second + 1};
        // right is deeper
        if (left.second < right.second) return {right.first, right.second + 1};
        // both equally deep, return anyone
        return {root, left.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) { return dfs(root).first; }
};