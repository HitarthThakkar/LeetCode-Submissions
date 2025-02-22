class Solution
{
public:
    TreeNode* recoverFromPreorder(string traversal)
    {
        stack<TreeNode*> st;
        int i = 0;
        while (i < traversal.size())
        {
            int d = 0;
            int val = 0;
            while (i < traversal.size() && traversal[i] == '-') d++, i++;
            while (i < traversal.size() && isdigit(traversal[i]))
                val = val * 10 + (traversal[i] - '0'), i++;
            TreeNode* node = new TreeNode(val);
            while (st.size() > d) st.pop();
            if (!st.empty())
                if (st.top()->left == nullptr) st.top()->left = node;
                else st.top()->right = node;
            st.push(node);
        }
        while (st.size() > 1) st.pop();
        return st.top();
    }
};