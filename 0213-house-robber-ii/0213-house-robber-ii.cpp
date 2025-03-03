class Solution
{
public:
    int rob(vector<int>& nums)
    {
        if(nums.size() == 1)
        {
            return nums[0];
        }
        if(nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }

        int prev2 = nums[0];
        int prev = max(nums[1], prev2);

        for(int i = 2; i < nums.size() - 1; i++)
        {
            int lr = nums[i] + prev2;
            int rr = prev;
            int cur_i = max(lr, rr);

            prev2 = prev;
            prev = cur_i;
        }

        int pc1 = prev;

        prev2 = nums[1];
        prev = max(nums[2], prev2);

        for(int i = 3; i <= nums.size() - 1; i++)
        {
            int lr = nums[i] + prev2;
            int rr = prev;
            int cur_i = max(lr, rr);

            prev2 = prev;
            prev = cur_i;
        }

        int pc2 = prev;

        return max(pc1, pc2);
    }
};