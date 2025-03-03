class Solution
{
public:
    int rob(vector<int>& nums)
    {

        if(nums.size() == 1)
        {
            return nums[0];
        }

        int prev2 = nums[0];
        int prev = max(nums[1], prev2);

        for(int i = 2; i <= nums.size() - 1; i++)
        {
            int lr = nums[i] + prev2;
            int rr = prev;
            int cur_i = max(lr, rr);

            cout << cur_i << " ";

            prev2 = prev;
            prev = cur_i;
        }

        return prev;
    }
};