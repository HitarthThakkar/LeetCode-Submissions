class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int ptr = 0, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[ptr] != nums[i]) nums[++ptr] = nums[i];
        }
        return (++ptr);
    }
};