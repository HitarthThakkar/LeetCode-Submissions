class Solution
{
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper)
    {
        int n = nums.size(), i = 0;
        long long answer = 0;
        sort(nums.begin(), nums.end());
        for(auto e : nums)
        {
            int i1 = lower_bound(nums.begin(), nums.end(), lower - e) - nums.begin();
            int i2 = upper_bound(nums.begin(), nums.end(), upper - e) - nums.begin();
            if(i1 < n && i1 <= (i2 - 1))
            {
                answer += (i2 - i1);
                if(i1 <= i && i < i2) answer--;
            }
            i++;
        }
        return (answer / 2);
    }
};