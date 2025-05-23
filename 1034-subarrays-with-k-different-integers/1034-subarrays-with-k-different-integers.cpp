class Solution
{
public:
    int ctOfsubArraysWithLessOrEqualThanKDistinct(vector<int> &nums, int k)
    {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int count = 0;
        unordered_map<int, int> mp;
        while(right < n)
        {
            mp[nums[right]]++;
            while(mp.size() > k)
            {
                count += (right - left);
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }
            right++;
        }
        while(left < n) { count += (right - left); left++; }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k)
    {
        int big = ctOfsubArraysWithLessOrEqualThanKDistinct(nums, k);
        int smol = ctOfsubArraysWithLessOrEqualThanKDistinct(nums, k - 1);
        return (big - smol);
    }
};