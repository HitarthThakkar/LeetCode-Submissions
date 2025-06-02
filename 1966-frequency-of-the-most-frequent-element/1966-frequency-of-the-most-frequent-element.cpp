class Solution
{
public:
    int maxFrequency(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        // for(auto e : nums) cout << e << " ";
        int n = nums.size();
        int left = 0;
        int right = 0;
        long long sum = 0;
        int maxFreq = 1;
        while(right < n)
        {
            sum += nums[right];
            long long need = ((right - left + 1) * 1LL * nums[right]);
            while(need - sum > k)
            {
                // cout << left << " " << right << endl;
                sum -= nums[left];
                need -= nums[right];
                left++;
            }
            maxFreq = max(maxFreq, right - left + 1);
            right++;
        }
        return maxFreq;
    }
};