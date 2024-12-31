class Solution
{
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        int n = days.size(), ptr = 0;
        vector<int> dp(n, 1e9), mp(days[n - 1], -1);
        for(int i = 0; i < days[n - 1]; i++)
        {
            if(ptr < n && days[ptr] == (i + 1)) mp[i] = ptr, ptr++;
            else if(i > 0) mp[i] = mp[i - 1];
        }
        for(int i = 0; i < n; i++)
        {
            int one = 1e9, two = 1e9, three = 1e9;
            if((days[i] - 2) >= 0 && mp[days[i] - 2] != -1) one = dp[mp[days[i] - 2]] + costs[0];
            else one = costs[0];
            if((days[i] - 8) >= 0 && mp[days[i] - 8] != -1) two = dp[mp[days[i] - 8]] + costs[1];
            else two = costs[1];
            if((days[i] - 31) >= 0 && mp[days[i] - 31] != -1) three = dp[mp[days[i] - 31]] + costs[2];
            else three = costs[2];
            dp[i] = min(one, min(two, three));
        }
        return dp[n - 1];
    }
};