class Solution
{
public:
    void recur(int ind, int stat, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        bool prevTaken = false;

        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] != nums[i - 1]) prevTaken = false;

            if(((stat & (1 << i)) == 0) && !prevTaken)
            {
                prevTaken = true;
                temp.push_back(nums[i]);
                recur(ind + 1, (stat | (1 << i)), temp, nums, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans; vector<int> temp;
        recur(0, 0, temp, nums, ans);
        return ans;
    }
};