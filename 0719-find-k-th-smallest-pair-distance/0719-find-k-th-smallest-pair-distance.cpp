class Solution
{
public:
    int pairsHavingDistanceLesserOrEqualToMid(int mid, vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = 0;
        int count = 0;
        while(right < n)
        {
            while(left < n && nums[right] - nums[left] > mid)
            {
                count += (right - left - 1);
                left++;
            }
            right++;
        }
        while(left < n) count += (right - left - 1), left++;
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int lo = 0;
        int hi = nums.back() - nums[0];
        int ans = hi;
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if(pairsHavingDistanceLesserOrEqualToMid(mid, nums) >= k) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};