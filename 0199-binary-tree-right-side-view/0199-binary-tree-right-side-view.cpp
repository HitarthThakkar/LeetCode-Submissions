class Solution
{
private:
    void recur(TreeNode* node, int Depth, vector<int> &res)
    {
        if(node == NULL) return;
        if(res.size() == Depth) res.push_back(node->val);
        recur(node->right, Depth + 1, res);
        recur(node->left, Depth + 1, res);
    }
public:
    vector<int> rightSideView(TreeNode* root)
    {
        // 2025 Hiring Prep Sprint Q4 - [Eazy w/ Recursion]
        vector<int> res;
        recur(root, 0, res);
        return res;
    }
};