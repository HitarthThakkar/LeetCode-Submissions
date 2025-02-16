class Solution
{
private:
    bool recur(TreeNode* node, TreeNode* target, vector<TreeNode*> &path)
    {
        if(node == NULL) return false;
        if(node == target) { path.push_back(node); return true; }
        path.push_back(node);
        if(recur(node->left, target, path)) return true;
        if(recur(node->right, target, path)) return true;
        path.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        vector<TreeNode* > ppath, qpath;
        recur(root, p, ppath);
        recur(root, q, qpath);
        reverse(ppath.begin(), ppath.end());
        reverse(qpath.begin(), qpath.end());
        TreeNode* ans;
        while(ppath.size() > 0 && qpath.size() > 0)
        {
            if(ppath.back() == qpath.back())
            {
                ans = ppath.back();
                ppath.pop_back();
                qpath.pop_back();
            }
            else
            {
                return ans;
            }
        }
        return ans;
    }
};