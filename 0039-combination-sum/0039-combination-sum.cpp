class Solution
{
private:
    void recur(int i,int cs,int tgt,vector<int>& temp,vector<int>& candi,vector<vector<int>>& ans)
    {
        if(i == candi.size()) { if(cs == tgt) ans.push_back(temp); return; }
        if(cs + candi[i] <= tgt)
        {
            temp.push_back(candi[i]);
            recur(i, cs + candi[i], tgt, temp, candi, ans);
            temp.pop_back();
        }
        recur(i + 1, cs, tgt, temp, candi, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans; vector<int> temp;
        recur(0, 0, target, temp, candidates, ans);
        return ans;
    }
};