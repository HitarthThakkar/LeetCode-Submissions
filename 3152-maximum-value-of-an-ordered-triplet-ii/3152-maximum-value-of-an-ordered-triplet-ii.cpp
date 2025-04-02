class Solution
{
public:
    long long maximumTripletValue(vector<int>& nums)
    {
        // Overpowered Solution, defeated me fr...
        // DRY RUN THIS PLZ, THIS IS OVERPOWERED.
        // WATCH SUBMISSIONS HISTORY & REALIZE GREATNESS OF THIS QUE.
        int n = nums.size();
        long long res = 0, imax = 0, dmax = 0;
        for (int k = 0; k < n; k++)
        {
            res = max(res, dmax * nums[k]);     // nums[k] represents nums[k]
            dmax = max(dmax, imax - nums[k]);   // nums[k] represents nums[j]
            imax = max(imax, 1LL * nums[k]);    // nums[k] represents nums[i]
        }
        return res;
    }
};