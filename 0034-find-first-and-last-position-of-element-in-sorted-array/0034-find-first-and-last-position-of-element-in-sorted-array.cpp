class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();

        int l = 0;
        int r = n - 1;
        
        vector<int> ans = {-1, -1};
        
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            
            if(nums[mid] > target)
            {
                r = mid - 1;
            }
            else if(nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                ans[0] = mid;
                r = mid - 1;
            }
        }

        if(ans[0] == -1)
        {
            return ans;
        }

        l = 0;
        r = n - 1;
        
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            
            if(nums[mid] < target)
            {
                l = mid + 1;
            }
            else if(nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                ans[1] = mid;
                l = mid + 1;
            }
        }
        
        return ans;
    }
};