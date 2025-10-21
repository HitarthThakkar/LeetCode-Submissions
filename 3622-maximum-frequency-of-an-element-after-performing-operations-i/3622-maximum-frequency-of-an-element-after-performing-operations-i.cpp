class Solution
{
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations)
    {
        map<int, int> m;
        unordered_map<int, int> mp;

        int minm = 1e9, mex = -1;

        for(auto e : nums)
        {
            minm = min(minm, e);
            mex = max(mex, e);
            mp[e]++;
            m[e - k]++;
            m[e + k + 1]--;
        }

        int mini = minm - k;
        int maxi = mex + k;
        int pfx = 0;

        int res = 1;

        for(int i = mini; i <= maxi; i++)
        {
            int mc = m[i] + pfx;
            pfx += m[i];

            int cost = mc - mp[i];

            if(cost <= numOperations)
            {
                res = max(res, mc);
            }
            else
            {
                res = max(res, mc - (cost - numOperations));
            }
        }

        return res;
    }
};