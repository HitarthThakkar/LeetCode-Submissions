class Solution
{
public:

    int ctOfSubArraysLessOrEqualToSomeGoal(vector<int> &nums, int goal)
    {
        if(goal < 0) return 0;

        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int count = 0;

        while(right < n)
        {
            sum += nums[right];

            while(sum > goal)
            {
                sum -= nums[left];
                left++;
            }

            count += (right - left + 1);

            right++;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        int big = ctOfSubArraysLessOrEqualToSomeGoal(nums, goal);
        int smol = ctOfSubArraysLessOrEqualToSomeGoal(nums, goal - 1);
        return (big - smol);
    }
};