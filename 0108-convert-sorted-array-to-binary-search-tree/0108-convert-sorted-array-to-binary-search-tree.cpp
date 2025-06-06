class Solution
{
public:
    void recur(int left, int right, TreeNode* node, vector<int> &nums)
    {
        int mid = (left + right) / 2;
        node->val = nums[mid];
        if(left <= mid - 1)
        {
            TreeNode* lefter = new TreeNode();
            recur(left, mid - 1, lefter, nums);
            node->left = lefter;
        }
        if(mid + 1 <= right)
        {
            TreeNode* righter = new TreeNode();
            recur(mid + 1, right, righter, nums);
            node->right = righter;
        }
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        int n = nums.size();
        TreeNode* root = new TreeNode();
        recur(0, n - 1, root, nums);
        return root;
    }
};