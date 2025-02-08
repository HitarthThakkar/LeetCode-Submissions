// https://www.youtube.com/watch?v=f2ic2Rsc9pU&t=645s [He is the GOAT]
class Solution
{
public:
    void recur(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (index == nums.size()) ans.push_back(nums);

        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            recur(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        recur(0, nums, ans);
        return ans;
    }
};