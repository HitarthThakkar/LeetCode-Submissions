class Solution
{
private:
    void recur(TreeNode* node, vector<int> &v)
    {
        if(node == NULL) return;
        recur(node->left, v);
        recur(node->right, v);
        v.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> v;
        recur(root, v);
        return v;
    }
};