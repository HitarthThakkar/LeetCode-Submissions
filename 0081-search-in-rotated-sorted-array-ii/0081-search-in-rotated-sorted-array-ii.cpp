class Solution
{
public:
    bool search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;

        if(target == nums[0]) return true;

        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if(nums[mid] == target) return true;

            if(nums[mid] == nums[lo] && nums[mid] == nums[hi])
            {
                lo++; hi--;
                continue;
            }

            if(nums[mid] >= nums[lo])
            {
                if(target >= nums[lo] && target <= nums[mid]) hi = mid - 1;
                else lo = mid + 1;
            }
            else
            {
                if(nums[mid] <= target && target <= nums[hi]) lo = mid + 1;
                else hi = mid - 1;
            }
        }

        return false;
    }
};