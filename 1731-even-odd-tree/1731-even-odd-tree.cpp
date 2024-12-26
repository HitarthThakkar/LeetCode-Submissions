class Solution
{
public:
    bool isEvenOddTree(TreeNode* root)
    {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            if(level & 1)
            {
                int prev = 1e9;
                for(int i = 0; i < n; i++)
                {
                    int cval = q.front()->val;
                    if((cval % 2 == 0) && (cval < prev)) prev = cval;
                    else return false;
                    if(q.front()->left) q.push(q.front()->left);
                    if(q.front()->right) q.push(q.front()->right);
                    q.pop();
                }
            }
            else
            {
                int prev = -1;
                for(int i = 0; i < n; i++)
                {
                    int cval = q.front()->val;
                    if((cval & 1) && (cval > prev)) prev = cval;
                    else return false;
                    if(q.front()->left) q.push(q.front()->left);
                    if(q.front()->right) q.push(q.front()->right);
                    q.pop();
                }
            }
            level++;
        }
        return true;
    }
};