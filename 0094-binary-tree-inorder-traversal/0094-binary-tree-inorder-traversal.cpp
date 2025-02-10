class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> v;
        stack<TreeNode*> st;
        if(root) st.push(root);
        while(!st.empty())
        {
            TreeNode* cur = st.top();
            st.pop();
            if(cur->left && cur->right)
            {
                st.push(cur->right);
                st.push(cur);
                st.push(cur->left);
                cur->left = NULL;
                cur->right = NULL;
            }
            else if(cur->left)
            {
                st.push(cur);
                st.push(cur->left);
                cur->left = NULL;
            }
            else if(cur->right)
            {
                v.push_back(cur->val);
                st.push(cur->right);
                cur->right = NULL;
            }
            else
            {
                v.push_back(cur->val);
            }
        }
        return v;
    }
};