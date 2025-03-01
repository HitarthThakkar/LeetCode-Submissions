class Solution
{
public:
    vector<int> applyOperations(vector<int>& nums)
    {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++)
            if(nums[i] == nums[i + 1])
                nums[i] *= 2, nums[i + 1] = 0;
        int ptr = 0;
        for(int i = 0; i < n; i++)
            if(nums[i] != 0)
                nums[ptr++] = nums[i];
        for(int i = ptr; i < n; i++)
            nums[i] = 0;
        return nums;
    }
};