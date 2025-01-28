class Solution
{
public:
    int minPairSum(vector<int>& nums)
    {
        int p1 = 0, p2 = nums.size() - 1;
        sort(nums.begin(), nums.end());

        int mex = -1;
        for(int i = 0; i <= (nums.size() / 2); i++)
        {
            if(nums[p1] + nums[p2] > mex)
            {
                mex = nums[p1] + nums[p2];
            }
            p1++, p2--;
        }
        return mex;
    }
};