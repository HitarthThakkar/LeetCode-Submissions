class Solution
{
public:
    int maxLevelSum(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        int curLevel = 1;

        int maxSum = -1e9;
        int LevelOfmaxSum = 1;

        while(!q.empty())
        {
            int sz = q.size();
            int sumOnThisLevel = 0;

            while(sz--)
            {
                TreeNode* node = q.front();
                q.pop();
                sumOnThisLevel += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(sumOnThisLevel > maxSum)
            {
                maxSum = sumOnThisLevel;
                LevelOfmaxSum = curLevel;
            }

            curLevel++;
        }

        return LevelOfmaxSum;
    }
};