class Solution
{
public:
    long long int sumDfs2(TreeNode* node, long long int &total, long long int &best)
    {
        long long int left = 0, right = 0;
        if(node->left) left = sumDfs2(node->left, total, best);
        if(node->right) right = sumDfs2(node->right, total, best);

        long long int one = left + right + node->val;
        long long int two = total - one;

        best = max(best, one * two);

        return one;
    }

    void sumDfs(TreeNode* node, long long int &totalSum)
    {
        totalSum += node->val;
        if(node->left) sumDfs(node->left, totalSum);
        if(node->right) sumDfs(node->right, totalSum);
    }

    int maxProduct(TreeNode* root)
    {
        long long int totalSum = 0;
        sumDfs(root, totalSum);
        long long int best = 0;
        if(root->left) sumDfs2(root->left, totalSum, best);
        if(root->right) sumDfs2(root->right, totalSum, best);
        return (best % 1000000007);
    }
};