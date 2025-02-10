class Solution
{
private:
    void recur(TreeNode* node, vector<int> &v)
    {
        if(node == NULL) return;
        v.push_back(node->val);
        recur(node->left, v);
        recur(node->right, v);
    }
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> v;
        recur(root, v);
        return v;
    }
};