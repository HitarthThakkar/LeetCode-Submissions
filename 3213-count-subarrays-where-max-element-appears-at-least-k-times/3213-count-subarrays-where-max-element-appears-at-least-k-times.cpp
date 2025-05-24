class Solution
{
public:
    long long countSubarrays(vector<int>& nums, int k)
    {
        // no. of (mexEleCount >= k) is same as := [no. of total - no. of (mexEleCount < k)]
        long long n = nums.size();
        int mex = *max_element(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int mexCt = 0;
        long long total = ((n) * (n + 1) / 2);
        long long result = 0;
        while(right < n)
        {
            if(nums[right] == mex) mexCt++;
            while(mexCt >= k) { mexCt -= ((nums[left] == mex) ? 1 : 0); left++; }
            result += (right - left + 1);
            right++;
        }
        return (total - result);
    }
};