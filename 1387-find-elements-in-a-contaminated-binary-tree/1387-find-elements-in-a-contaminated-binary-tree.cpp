class FindElements
{
public:
    set<int> s;
    FindElements(TreeNode* root)
    {
        root->val = 0;
        s.insert(0);
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode * top = q.front();
            int x = top->val;
            q.pop();

            if(top->left)
            {
                top->left->val = (2 * x) + 1;
                s.insert(top->left->val);
                q.push(top->left);
            }

            if(top->right)
            {
                top->right->val = (2 * x) + 2;
                s.insert(top->right->val);
                q.push(top->right);
            }
        }
    }
    bool find(int target)
    {
        return (s.find(target) != s.end());
    }
};