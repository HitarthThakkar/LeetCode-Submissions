class Solution
{
public:
    int answer = -1e5;
    int recur(TreeNode* node)
    {
        if(node == NULL) return 0;
        int mai = node->val;
        int left = recur(node->left);
        int right = recur(node->right);
        if(left == 0 && right == 0)
            answer = max({answer, mai, left + mai, right + mai, left + right + mai});
        else if(left == 0)
            answer = max({answer, mai, right, left + mai, right + mai, left + right + mai});
        else if(right == 0)
            answer = max({answer, mai, left, left + mai, right + mai, left + right + mai});
        else
            answer = max({answer, mai, left, right, left + mai, right + mai, left + right + mai});
        return (max({0, left, right}) + mai);
    }
    int maxPathSum(TreeNode* root)
    {
        recur(root);
        return answer;
    }
};