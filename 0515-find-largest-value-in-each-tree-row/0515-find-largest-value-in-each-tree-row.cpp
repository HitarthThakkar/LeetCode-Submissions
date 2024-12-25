class Solution
{
public:
    vector<int> largestValues(TreeNode* root)
    {
        queue<TreeNode*> q; vector<int> res;
        if(root != nullptr) q.push(root);
        while(!q.empty())
        {
            int mex = INT_MIN;
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                mex = max(mex, q.front()->val);
                if(q.front()->left != nullptr) q.push(q.front()->left);
                if(q.front()->right != nullptr) q.push(q.front()->right);
                q.pop();
            }
            res.push_back(mex);
        }
        return res;
    }
};