class Solution
{
public:
    void recur(TreeNode* node, int &k, int &answer)
    {
        if(node == NULL || answer > 0) return;
        recur(node->left, k, answer);
        if(--k == 0) { answer = node->val; return; }
        recur(node->right, k, answer);
    }
    int kthSmallest(TreeNode* root, int k)
    {
        int answer = -1;
        recur(root, k, answer);
        return answer;
    }
};