class Solution
{
public:
    void recur(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (index == nums.size()) ans.push_back(nums);
        int stat = 0;
        for (int i = index; i < nums.size(); i++)
        {
            if((stat & (1 << (nums[i] + 10))) == 0)
            {
                stat |= (1 << (nums[i] + 10));
                swap(nums[index], nums[i]);
                recur(index + 1, nums, ans);
                swap(nums[index], nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        recur(0, nums, ans);
        return ans;
    }
};