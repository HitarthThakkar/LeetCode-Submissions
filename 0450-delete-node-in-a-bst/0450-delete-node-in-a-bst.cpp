class Solution
{
public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        TreeNode* parent = NULL;
        TreeNode* tbDel = NULL;
        TreeNode* node = root;
        char dir = 'C';

        while(node)
        {
            if(node->val == key)
            {
                tbDel = node;
                break;
            }
            else if(node->val > key)
            {
                parent = node;
                node = node->left;
                dir = 'L';
            }
            else
            {
                parent = node;
                node = node->right;
                dir = 'R';
            }
        }

        if(tbDel == NULL) return root;
        
        if(parent == NULL)
        {
            TreeNode* leftfirst = tbDel->left;
            TreeNode* rightfirst = tbDel->right;
            if(rightfirst == NULL)
            {
                if(leftfirst == NULL) return NULL;
                return leftfirst;
            }
            tbDel->right = NULL;
            TreeNode* rightlast = rightfirst;
            while(rightlast->left != NULL) rightlast = rightlast->left;
            rightlast->left = leftfirst;
            return rightfirst;
        }
        else
        {
            TreeNode* leftfirst = tbDel->left;
            TreeNode* rightfirst = tbDel->right;

            if(rightfirst == NULL)
            {
                if(dir == 'L')
                {
                    parent->left = leftfirst;
                    return root;
                }
                else
                {
                    parent->right = leftfirst;
                    return root;
                }
            }

            if(dir == 'L')
            {
                parent->left = rightfirst;
                TreeNode* rightlast = rightfirst;
                while(rightlast->left != NULL) rightlast = rightlast->left;
                rightlast->left = leftfirst;
                return root;
            }
            else
            {
                parent->right = rightfirst;
                TreeNode* rightlast = rightfirst;
                while(rightlast->left != NULL) rightlast = rightlast->left;
                rightlast->left = leftfirst;
                return root;
            }
        }
    }
};