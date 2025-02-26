class Solution
{
public:
    int maxAbsoluteSum(vector<int>& nums)
    {
        int mexsum = 0, mexsum2 = 0;
        int runningsum = 0, runningsum2 = 0;
        for(auto ele : nums)
        {
            runningsum += ele;
            if(runningsum > mexsum) mexsum = runningsum;
            if(runningsum < 0) runningsum = 0;
            runningsum2 += ele;
            if(runningsum2 < mexsum2) mexsum2 = runningsum2;
            if(runningsum2 > 0) runningsum2 = 0;
        }
        return max(mexsum, abs(mexsum2));
    }
};