class Solution
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        TreeNode* node = root;
        TreeNode* newNode = new TreeNode(val);

        if(!root) return newNode;

        while(true)
        {
            if(node->val > val)
            {
                if(node->left == NULL)
                {
                    node->left = newNode;
                    return root;
                }
                else
                {
                    node = node->left;
                }
            }
            else
            {
                if(node->right == NULL)
                {
                    node->right = newNode;
                    return root;
                }
                else
                {
                    node = node->right;
                }
            }
        }

        return root;
    }
};