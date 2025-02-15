class Solution
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> result;
        queue<TreeNode *> q;
        if(root) q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                if(i == sz - 1) result.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
        }
        return result;
    }
};