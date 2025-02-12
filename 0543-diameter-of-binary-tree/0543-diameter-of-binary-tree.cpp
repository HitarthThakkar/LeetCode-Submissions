class Solution
{
public:
    int answer = 0;
    
    int recur(TreeNode* node)
    {
        if(node == NULL) return 0;
        int l = recur(node->left);
        int r = recur(node->right);
        answer = max(answer, l + r);
        return (max(l, r) + 1);
    }
    int diameterOfBinaryTree(TreeNode* root)
    {
        recur(root);
        return answer;
    }
};