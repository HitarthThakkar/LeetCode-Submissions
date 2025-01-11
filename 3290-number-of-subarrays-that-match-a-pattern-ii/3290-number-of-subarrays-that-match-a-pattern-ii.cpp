class Solution
{
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern)
    {
        int n = nums.size(), m = pattern.size(), j = 0, ans = 0;
        vector<int> panums(n - 1, 0); vector<int> lps(m, 0);
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i] < nums[i + 1]) panums[i] = 1;
            else if(nums[i] == nums[i + 1]) panums[i] = 0;
            else if(nums[i] > nums[i + 1]) panums[i] = -1;
        }
        for(int i = 1; i < m; i++)
        {
            while(j > 0 && pattern[j] != pattern[i]) j = lps[j - 1];
            if(pattern[j] == pattern[i]) lps[i] = ++j;
        }
        j = 0;
        for(int i = 0; i < n - 1; i++)
        {
            while(j > 0 && pattern[j] != panums[i]) j = lps[j - 1];
            if(pattern[j] == panums[i]) { j++; if(j == m) ans++, j = lps[j - 1]; }
        }
        return ans;
    }
};