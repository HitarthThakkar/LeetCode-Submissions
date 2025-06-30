class Solution
{
public:
    int findLHS(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int answer = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int index = lower_bound(nums.begin(), nums.end(), nums[i] + 2) - nums.begin();
            if(nums[index - 1] - nums[i] == 1) answer = max(answer, index - i);
        }
        return answer;
    }
};