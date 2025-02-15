class Solution
{
private:
    void recur(TreeNode* node, int l, int d, vector<vector<pair<int, int>>> &vvp)
    {
        if(node == NULL) return;

        if(l >= vvp.size())
        {
            vector<pair<int, int>> tempo;
            tempo.push_back({d, node->val});
            vvp.push_back(tempo);
        }
        else
        {
            vvp[l].push_back({d, node->val});
        }

        recur(node->left, l - 1, d + 1, vvp);
        recur(node->right, l + 1, d + 1, vvp);
    }

    void getLeftMostDist(TreeNode* node, int parCoord, int &mexL)
    {
        if(node->left == NULL && node->right == NULL) return;

        if(node->left)
        {
            mexL = max(mexL, parCoord + 1);
            getLeftMostDist(node->left, parCoord + 1, mexL);
        }
        if(node->right)
        {
            mexL = max(mexL, parCoord - 1);
            getLeftMostDist(node->right, parCoord - 1, mexL);
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        int mexL = 0;
        getLeftMostDist(root, 0, mexL);

        vector<vector<int>> answer;
        vector<vector<pair<int, int>>> vvp(mexL + 1);

        recur(root, mexL, 0, vvp);

        for(auto &vec : vvp)
        {
            sort(vec.begin(), vec.end());
        }

        for(auto vp : vvp)
        {
            vector<int> temp;
            for(auto pr : vp) temp.push_back(pr.second);
            answer.push_back(temp);
        }

        return answer;
    }
};