class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        map<int, int> mp;
        mp[0] = 1;                      // IMP { TC : [3, -3, 1, 1, 1] }
        int pfxSum = 0, answer = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            pfxSum += nums[i];
            int remove = pfxSum - k;
            answer += mp[remove];
            mp[pfxSum]++;
        }

        return answer;
    }
};