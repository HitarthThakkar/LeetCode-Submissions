class NodeValue
{
public:
    int maxNode, minNode, maxSum;
    NodeValue(int minNode, int maxNode, int maxSum)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSum = maxSum;
    }
};

class Solution
{
public:
    int answer = 0;

    NodeValue largestBSTSubtreeHelper(TreeNode* root)
    {
        if (!root) return NodeValue(INT_MAX, INT_MIN, 0);

        // cout << root->val << " " << answer << endl;
        
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        if (left.maxNode < root->val && root->val < right.minNode)
        {
            answer = max(answer, left.maxSum + right.maxSum + root->val);
            // It is a BST, update the values for the current tree
            return NodeValue(min(root->val, left.minNode),
                max(root->val, right.maxNode), left.maxSum + right.maxSum + root->val);
        }
        
        // If the current tree is not a BST,
        // return values indicating invalid tree properties
        answer = max(answer, max(left.maxSum, right.maxSum));
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }

    int maxSumBST(TreeNode* root)
    {
        answer = 0;
        largestBSTSubtreeHelper(root).maxSum;
        return answer;
    }
};