class Solution
{
public:
    int sum = 0;

    void recur(TreeNode* node, string &s) {
        s += (node->val == 1 ? '1' : '0');

        if(node->left == NULL && node->right == NULL) {
            int pw = pow(2, s.length() - 1);

            for(auto c : s) {
                if(c == '1') sum += pw;
                pw >>= 1;
            }

            s.pop_back();
            return;
        }

        if(node->left) recur(node->left, s);
        if(node->right) recur(node->right, s);
        s.pop_back();
    }

    int sumRootToLeaf(TreeNode* root)
    {
        string s;
        recur(root, s);
        return sum;
    }
};