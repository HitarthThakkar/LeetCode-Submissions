class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int count = 0;
        long long int mul = 1;

        while(right < n)
        {
            if(nums[right] >= k)
            {
                mul = 1;
                left = right + 1;
                right++;
                continue;
            }

            mul *= nums[right];

            while(mul >= k)
            {
                mul /= nums[left];
                left++;
            }

            count += (right - left + 1);

            right++;
        }

        return count;
    }
};