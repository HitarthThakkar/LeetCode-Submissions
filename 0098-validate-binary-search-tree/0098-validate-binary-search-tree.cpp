class Solution
{
private:
    pair<int, int> recur(TreeNode* node, bool &answer)
    {
        if(answer == false) return {-1, -1};

        pair<int, int> lp, rp;
        bool left = false, right = false;

        if(node->left)
        {
            left = true;
            lp = recur(node->left, answer);
            if(answer == false) return {-1, -1};
        }
        if(node->right)
        {
            right = true;
            rp = recur(node->right, answer);
            if(answer == false) return {-1, -1};
        }

        if(left == false && right == false)
        {
            return {node->val, node->val};
        }
        else if(left == false && right == true)
        {
            if(min(rp.first, rp.second) > node->val)
            {
                return {node->val, max(rp.first, rp.second)};
            }
            else
            {
                answer = false;
                return {-1, -1};
            }
        }
        else if(left == true && right == false)
        {
            if(max(lp.first, lp.second) < node->val)
            {
                return {min(lp.first, lp.second), node->val};
            }
            else
            {
                answer = false;
                return {-1, -1};
            }
        }
        else
        {
            if((min(rp.first, rp.second) > node->val) && (max(lp.first, lp.second) < node->val))
            {
                return {min(lp.first, lp.second), max(rp.first, rp.second)};
            }
            else
            {
                answer = false;
                return {-1, -1};
            }
        }
    }
public:
    bool isValidBST(TreeNode* root)
    {
        bool answer = true;
        recur(root, answer);
        return answer;
    }
};