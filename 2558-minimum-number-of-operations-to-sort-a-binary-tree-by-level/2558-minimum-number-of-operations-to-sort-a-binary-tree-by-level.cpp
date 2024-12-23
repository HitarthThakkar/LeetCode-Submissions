class Solution
{
private:
    int getMinSwaps(vector<int>& original)
    {
        int swaps = 0;
        vector<int> target = original;
        sort(target.begin(), target.end());

        map<int, int> pos;
        for(int i = 0; i < original.size(); i++) pos[original[i]] = i;

        for(int i = 0; i < original.size(); i++)
        {
            if(original[i] != target[i])
            {
                swaps++;
                int curPos = pos[target[i]];
                pos[original[i]] = curPos;
                swap(original[curPos], original[i]);
            }
        }

        return swaps;
    }
public:
    int minimumOperations(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        int totalSwaps = 0;

        while(!q.empty())
        {
            int levelSz = q.size();
            vector<int> levelValues(levelSz);

            for(int i = 0; i < levelSz; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                levelValues[i] = node->val;

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }

            totalSwaps += getMinSwaps(levelValues);
        }

        return totalSwaps;
    }
};