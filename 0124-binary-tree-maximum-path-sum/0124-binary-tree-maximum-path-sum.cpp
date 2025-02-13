class Solution
{
public:
    int recur(TreeNode* node, int &answer)
    {
        if(node == NULL) return 0;
        int left = max(0, recur(node->left, answer));
        int right = max(0, recur(node->right, answer));
        answer = max(answer, left + right + node->val);
        return (max(left, right) + node->val);
    }
    int maxPathSum(TreeNode* root)
    {
        int answer = -1e8;
        recur(root, answer);
        return answer;
    }
};