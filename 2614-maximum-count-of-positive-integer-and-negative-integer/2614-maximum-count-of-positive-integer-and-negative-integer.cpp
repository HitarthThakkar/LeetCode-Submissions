class Solution
{
public:
    int maximumCount(vector<int>& nums)
    {
        int n = nums.size();
        int lni = -1, fpi = -1;
        int lo = 0, hi = n - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(nums[mid] < 0) { lni = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        lo = 0, hi = n - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(nums[mid] > 0) { fpi = mid; hi = mid - 1; }
            else lo = mid + 1;
        }
        if(lni == -1 && fpi == -1) return 0;
        if(lni == -1) return (n - fpi);
        if(fpi == -1) return (lni + 1);
        return max(lni + 1, n - fpi);
    }
};