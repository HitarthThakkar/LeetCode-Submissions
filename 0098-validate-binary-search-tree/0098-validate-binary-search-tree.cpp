#define ll long long int
class Solution
{
public:
    bool RangeBasedRecur(TreeNode* node, ll mini, ll maxi)
    {
        if(!node) return true;
        if(node->val > mini && node->val < maxi)
        {
            bool left = RangeBasedRecur(node->left, mini, node->val);
            bool right = RangeBasedRecur(node->right, node->val, maxi);
            return (left & right);
        }
        return false;
    }
    bool isValidBST(TreeNode* root)
    {
        return RangeBasedRecur(root, -1e16, 1e16);
    }
};