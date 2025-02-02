class Solution
{
private:
    bool func(vector<int>& nums, int target)
    {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;

        if(target == nums[0]) return true;

        while(hi - lo > 1)
        {
            int mid = (lo + hi) / 2;

            if(nums[mid] == target) return true;

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

        if(nums[lo] == target) return true;
        if(nums[hi] == target) return true;
        return false;
    }
public:
    bool search(vector<int>& nums, int target)
    {
        int n = nums.size();

        if(nums[0] != nums[n - 1])
        {
            return func(nums, target);
        }
        else
        {

            if(nums[0] == target) return true;

            int lo = 1;
            int hi = n - 2;

            for(int i = 0; i <= hi; i++)
            {
                if(nums[i] == target)
                {
                    return true;
                }
            }

            return false;
        }
    }
};