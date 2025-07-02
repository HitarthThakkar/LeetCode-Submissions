class Solution
{
public:
    int calculate(vector<int> &nums, int cur_target, int k)
    {
        int runningsum = 0;
        int mexsum = 0;
        for(auto e : nums)
        {
            if(e == cur_target) runningsum++;
            if(e == k) runningsum--;
            if(runningsum < 0) runningsum = 0;
            mexsum = max(mexsum, runningsum);
        }
        return mexsum;
    }

    int maxFrequency(vector<int>& nums, int k)
    {
        // \U0001f480\U0001f480\U0001f480 Aryan Mittal

        unordered_map<int, int> freq;
        for(auto e : nums) freq[e]++;

        int maxFreqtba = 0;

        for(auto &[val, _] : freq)
            maxFreqtba = max(maxFreqtba, calculate(nums, val, k));

        return freq[k] + maxFreqtba;
    }
};