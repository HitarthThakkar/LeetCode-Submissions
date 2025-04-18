class Solution
{
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int left = 0, right = 0, ans = 0, z = 0;
        while(right < nums.size())
        {
            if(nums[right] == 0) z++;
            while(z > k) if(nums[left++] == 0) z--;
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};