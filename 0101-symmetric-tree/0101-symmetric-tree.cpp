class Solution
{
private:
    bool recur(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;
        bool op1 = recur(p->left, q->right);
        bool op2 = recur(p->right, q->left);
        return (op1 & op2);
    }
public:
    bool isSymmetric(TreeNode* root)
    {
        TreeNode* p = root;
        TreeNode* q = root;
        return recur(p, q);
    }
};