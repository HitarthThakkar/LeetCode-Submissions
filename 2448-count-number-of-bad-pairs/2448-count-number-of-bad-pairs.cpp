class Solution
{
public:
    long long countBadPairs(vector<int>& nums)
    {
        long long int n = nums.size();
        map<long long int, long long int> mp;
        long long ans = 0;
        long long int total = ((n * (n - 1)) / 2);
        for(int i = 0; i < n; i++)
        {
            long long int val = (i - nums[i]);
            if(mp.find(val) != mp.end()) ans += mp[val];
            mp[val]++;
        }
        return (total - ans);
    }
};