class Solution
{
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        unsigned int answer = 0;
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            answer = max(answer, q.back().second - q.front().second);
            int size = q.size();
            int base = q.front().second;
            while(size--) {
                q.front().second -= base;   // tHE gOAT
                if(q.front().first->left)
                    q.push({q.front().first->left, (q.front().second * 2) + 1});
                if(q.front().first->right)
                    q.push({q.front().first->right, (q.front().second * 2) + 2});
                q.pop();
            }
        }
        return ++answer;
    }
};