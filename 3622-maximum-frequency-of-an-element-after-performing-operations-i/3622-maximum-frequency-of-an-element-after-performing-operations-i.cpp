class Solution
{
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations)
    {
        map<long long, long long> diff;
        unordered_map<long long, long long> freq;

        set<long long> critical_points;

        for(long long e : nums)
        {
            critical_points.insert(e - k);
            critical_points.insert(e);
            critical_points.insert(e + k + 1);
            freq[e]++;
            diff[e - k]++;
            diff[e + k + 1]--;
        }

        long long pfx = 0;
        long long res = 1;

        for(auto i : critical_points)
        {
            long long total_achievable = diff[i] + pfx;
            pfx += diff[i];

            long long cost_incurred = total_achievable - freq[i];

            if(cost_incurred <= numOperations)
            {
                res = max(res, total_achievable);
            }
            else
            {
                res = max(res, numOperations + freq[i]);
            }
        }

        return res;
    }
};