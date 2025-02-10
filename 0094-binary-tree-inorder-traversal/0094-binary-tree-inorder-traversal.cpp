class Solution
{
private:
    void recur(TreeNode* node, vector<int> &v)
    {
        if(node == NULL) return;
        recur(node->left, v);
        v.push_back(node->val);
        recur(node->right, v);
    }
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> v;
        recur(root, v);
        return v;
    }
};