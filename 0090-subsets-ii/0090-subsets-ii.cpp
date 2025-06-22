class Solution
{
public:
    void recur(int i, vector<int> &temp, vector<int> &nums, vector<vector<int>> &ans)
    {
        if(i >= nums.size()) { ans.push_back(temp); return; }
        temp.push_back(nums[i]);
        int del = 0;
        while(i + del < nums.size() && nums[i + del] == nums[i]) del++;
        recur(i + 1, temp, nums, ans);
        temp.pop_back();
        recur(i + del, temp, nums, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans; vector<int> temp;
        recur(0, temp, nums, ans);
        return ans;
    }
};