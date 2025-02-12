class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> answer;
        queue<TreeNode*> q;
        if(root) q.push(root);
        bool dir = false;
        while(!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            while(sz--) {
                temp.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            if(dir) reverse(temp.begin(), temp.end());
            answer.push_back(temp);
            dir = !dir;
        }
        return answer;
    }
};