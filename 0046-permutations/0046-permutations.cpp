class Solution
{
public:
    void recur(int status, vector<int>& temp, vector<int>& nums,vector<vector<int>>& ans)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(((1 << i) & status) == 0)
            {
                temp.push_back(nums[i]);
                recur((status | (1 << i)), temp, nums, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        int status = 0;
        vector<vector<int>> ans; vector<int> temp;
        recur(status, temp, nums, ans);
        return ans;
    }
};