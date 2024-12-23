class Solution
{
public:
    bool check(vector<int>& nums)
    {
        int n = nums.size();
        int no_of_inv = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i] > nums[i + 1]) no_of_inv++;
        }
        return ((no_of_inv == 0) || (no_of_inv == 1 && (nums[n - 1] <= nums[0])));
    }
};