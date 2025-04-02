class Solution
{
public:
    long long maximumTripletValue(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> rightmax(n, nums[n - 1]);
        for(int i = n - 2; i >= 0; i--) rightmax[i] = max(nums[i], rightmax[i + 1]);
        long long leftmax = nums[0];
        long long answer = 0;
        for(int j = 1; j < n - 1; j++)
        {
            answer = max(answer, (leftmax - nums[j]) * 1LL * rightmax[j + 1]);
            leftmax = max(leftmax, 1LL * nums[j]);
        }
        return answer;
    }
};