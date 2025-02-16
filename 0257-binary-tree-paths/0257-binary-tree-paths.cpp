class Solution
{
private:
    string numtostr(int num)
    {
        string temp = "";
        bool neg = false;
        if(num < 0) { neg = true; num *= -1; }
        while(num)
        {
            temp += ((char) ((num % 10) + 48));
            num /= 10;
        }
        if(neg) temp += '-';
        reverse(temp.begin(), temp.end());
        return temp;
    }
    void recur(TreeNode* node, string temp, vector<string> &ans)
    {
        if(node == NULL) return;
        if(node->left == NULL && node->right == NULL)
        {
            temp += numtostr(node->val);
            ans.push_back(temp);
            return;
        }
        temp += numtostr(node->val); temp += "->";
        recur(node->left, temp, ans);
        recur(node->right, temp, ans);
        temp.pop_back(); temp.pop_back(); temp.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> ans; string temp = "";
        recur(root, temp, ans);
        return ans;
    }
};