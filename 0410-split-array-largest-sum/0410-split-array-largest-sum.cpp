class Solution
{
private:
    bool check(long long int lss, int k, vector<int> &nums)
    {
        long long int rs = 0;
        int nos = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(rs + nums[i] > lss) { nos++; rs = nums[i]; }
            else { rs += nums[i]; }
        }
        return (nos <= k);
    }
public:
    int splitArray(vector<int>& nums, int k)
    {
        long long int lo = *max_element(nums.begin(), nums.end());
        long long int hi = 0;
        for(auto ele : nums) hi += ele;
        long long int ans = hi;
        while(lo <= hi)
        {
            long long int mid = lo + (hi - lo) / 2;
            if(check(mid, k, nums)) { ans = mid; hi = mid - 1; }
            else lo = mid + 1;
        }
        return ans;
    }
};