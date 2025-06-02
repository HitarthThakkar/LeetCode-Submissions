class Solution
{
public:
    bool isIdealPermutation(vector<int>& nums)
    {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] - 1 > i) return false;
            if(nums[i] == i + 1) {
                if(i + 1 >= n) return false;
                if(nums[i] - 1 != nums[i + 1]) return false;
                i++;
            }
        }
        return true;
    }
};