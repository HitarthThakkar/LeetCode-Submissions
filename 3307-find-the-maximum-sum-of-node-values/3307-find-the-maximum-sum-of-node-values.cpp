class Solution
{
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges)
    {
        long long answer = 0;
        long long minDecrease = 1e18;
        vector<long long> increase;
        bool spare = false;

        for(long long e : nums)
        {
            answer += e;
            long long val = (e ^ k);

            if(val > e) increase.push_back(val - e);
            else if(val < e) minDecrease = min(e - val, minDecrease);
            else spare = true;
        }

        long long minIncrease = 1e18;

        for(auto e : increase)
        {
            answer += e;
            minIncrease = min(minIncrease, e);
        }

        if((increase.size() & 1) && (!spare))
        {
            answer -= min(minDecrease, minIncrease);
        }

        return answer;
    }
};