class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;

        if(target == nums[0]) return 0;

        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if(nums[mid] == target) return mid;

            if(nums[mid] >= nums[0])
            {
                if(target > nums[0] && target < nums[mid]) hi = mid - 1;
                else lo = mid + 1;
            }
            else
            {
                if(target < nums[0] && target > nums[mid]) lo = mid + 1;
                else hi = mid - 1;
            }
        }

        return -1;
    }
};