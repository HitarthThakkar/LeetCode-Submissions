class Solution
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> v;
        stack<TreeNode *> st;

        TreeNode *cur = root;

        while (cur != NULL || !st.empty())
        {
            if (cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode *temp = st.top()->right;

                if (temp == NULL)
                {
                    temp = st.top();
                    st.pop();

                    v.push_back(temp->val);

                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        v.push_back(temp->val);
                    }
                }
                else
                {
                    cur = temp;
                }
            }
        }

        return v;
    }
};