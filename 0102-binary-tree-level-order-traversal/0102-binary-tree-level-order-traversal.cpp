class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> answer;

        if(!root) return answer;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            vector<int> temp;
            int size = q.size();

            while(size--)
            {
                temp.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }

            answer.push_back(temp);
        }

        return answer;
    }
};