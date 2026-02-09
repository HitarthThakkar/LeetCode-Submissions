class Solution
{
public:

    void traversal(TreeNode* node, vector<TreeNode*> &inorder)
    {
        if(!node) return;
        traversal(node->left, inorder);
        inorder.push_back(node);
        traversal(node->right, inorder);
    }

    TreeNode* recur(int l, int r, vector<TreeNode*> &inorder)
    {
        if(l > r) return NULL;

        int mid = (l + r) / 2;

        TreeNode* root = inorder[mid];

        root->left = recur(l, mid - 1, inorder);
        root->right = recur(mid + 1, r, inorder);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root)
    {
        vector<TreeNode*> inorder;
        traversal(root, inorder);

        if(inorder.size() < 3) return root;

        return recur(0, inorder.size() - 1, inorder);
    }
};