class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n - 1] != nums[n - 2]) return nums[n - 1];
        int lo = 1, hi = n - 2;
        while(hi - lo > 1)
        {
            int mid = (hi + lo) / 2;

            if(nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid])
            {
                return nums[mid];
            }

            if(nums[mid] == nums[mid + 1])
            {
                if(mid & 1)
                {
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            else
            {
                if(mid & 1)
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
        }

        if(nums[lo - 1] != nums[lo] && nums[lo + 1] != nums[lo]) return nums[lo];
        return nums[hi];
    }
};