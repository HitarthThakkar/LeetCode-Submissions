class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long int answer = 0;
        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push({root, 1});
        while(!q.empty()) {
            int size = q.size();
            answer = max(answer, q.back().second - q.front().second);
            while(size--) {
                if(q.front().first->left)
                    q.push({q.front().first->left, q.front().second * 2});
                if(q.front().first->right)
                    q.push({q.front().first->right, (q.front().second * 2) + 1});
                q.pop();
            }
        }
        return ++answer;
    }
};