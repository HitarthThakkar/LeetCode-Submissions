class Solution
{
public:
    void recur(int mean, int target, int left, vector<int>& temp, vector<vector<int>>& ans)
    {
        if(left == 0) { if(target == 0) ans.push_back(temp); return; }
        for(int i = mean; i < 10; i++)
        {
            temp.push_back(i);
            recur(i + 1, target - i, left - 1, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> temp; vector<vector<int>> ans;
        recur(1, n, k, temp, ans);
        return ans;
    }
};