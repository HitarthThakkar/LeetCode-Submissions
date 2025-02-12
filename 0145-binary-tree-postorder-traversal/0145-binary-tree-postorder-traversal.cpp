class Solution
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> v;
        stack<TreeNode *> st;
        if (root != NULL) st.push(root);
        while (!st.empty())
        {
            TreeNode *top = st.top();
            v.push_back(top->val);
            st.pop();
            if(top->left) st.push(top->left);
            if(top->right) st.push(top->right);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};