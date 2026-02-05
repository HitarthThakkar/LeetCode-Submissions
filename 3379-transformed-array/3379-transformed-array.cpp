class Solution
{
public:
    vector<int> constructTransformedArray(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> result(n);

        for(int i = 0; i < n; i++)
        {
            int ind = i;
            if(nums[i] > 0) ind = i + nums[i];
            else if(nums[i] < 0) {
                int temp = -nums[i];
                temp %= n;
                ind = (i + (n - temp));
            }
            ind %= n;
            result[i] = nums[ind];
        }

        return result;
    }
};