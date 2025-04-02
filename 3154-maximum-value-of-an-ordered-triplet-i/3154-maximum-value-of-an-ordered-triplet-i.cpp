class Solution
{
public:
    long long maximumTripletValue(vector<int>& nums)
    {
        // Overpowered Solution, defeated me fr...
        // GOTO PART 2 OF THIS QUE AND REALIZE THIS APPROACH BY DRY_RUN
        int n = nums.size();
        long long res = 0, imax = 0, dmax = 0;
        for (int k = 0; k < n; k++)
        {
            res = max(res, dmax * nums[k]);     // nums[k] actually represents nums[k]
            dmax = max(dmax, imax - nums[k]);   // nums[k] actually represents nums[j]
            imax = max(imax, 1LL * nums[k]);    // nums[k] actually represents nums[i]
        }
        return res;
    }
};