class Solution
{
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations)
    {
        map<int, int> diff;
        unordered_map<int, int> freq;

        set<int> critical_points;

        for(int e : nums)
        {
            critical_points.insert(e - k);
            critical_points.insert(e);
            critical_points.insert(e + k + 1);
            freq[e]++;
            diff[e - k]++;
            diff[e + k + 1]--;
        }

        int pfx = 0;
        int res = 1;

        for(auto i : critical_points)
        {
            int total_achievable = diff[i] + pfx;
            pfx += diff[i];

            int cost_incurred = total_achievable - freq[i];

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