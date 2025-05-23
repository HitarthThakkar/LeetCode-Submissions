class Solution
{
public:
    int maxScore(vector<int>& nums, int k)
    {
        int n = nums.size();
        int window_sz = n - k;
        int ArraySum = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        int right = 0;
        int windowSum = 0;
        int miniWindowSum = 1e9;
        while(right < n)
        {
            windowSum += nums[right];
            if((right - left + 1) > window_sz)
            {
                windowSum -= nums[left];
                left++;
            }
            if((right - left + 1) == window_sz)
            {
                miniWindowSum = min(miniWindowSum, windowSum);
            }
            right++;
        }
        return (ArraySum - miniWindowSum);
    }
};