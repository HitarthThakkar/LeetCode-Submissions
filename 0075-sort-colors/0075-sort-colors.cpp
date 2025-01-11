class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int sp = 0, lp = nums.size() - 1;
        for(int i = 0; i <= lp; i++)
            if (nums[i] == 0) swap(nums[i], nums[sp]), sp++;
            else if (nums[i] == 2) swap(nums[i], nums[lp]), i--, lp--;
    }
};