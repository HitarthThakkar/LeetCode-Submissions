class Solution
{
public:
    void recur(int ind,int target,vector<int>& temp,vector<int>&candidates,vector<vector<int>>& ans)
    {
        if(target == 0) ans.push_back(temp);
        for(int i = ind; i < candidates.size(); i++) {
            if(i > ind && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;
            temp.push_back(candidates[i]);
            recur(i + 1, target - candidates[i], temp, candidates, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans; vector<int> temp;
        recur(0, target, temp, candidates, ans);
        return ans;
    }
};