class Solution
{
private:
    int findHeight(TreeNode* node, char dir)
    {
        int height = 0;
        while(node)
        {
            height++;
            if(dir == 'L') node = node->left;
            else node = node->right;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root)
    {
        if(root == NULL) return 0;
        int lh = findHeight(root, 'L');                                 // LogN
        int rh = findHeight(root, 'R');                                 // LogN
        if(lh == rh) return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);    // LogN
        // Why this recursion is taking logN time?
        // Every time you call recursion, you go 1 level down.
        // Total levels by definition of complete BT are logN.
        // So, total calls will be logN atmost.
        // Total, (2 * logN) for each recursion call and LogN recursion calls.
        // TC = O((logN * (2 * logN))) == O((logN)^2)
        // Space complexity, recursion calls are stored in stack space.
        // and they canbe logN at max.
        // SC = O(logN)
    }
};