class Solution
{
public:
    int getMeGEQthanVal(vector<vector<int>> &events, int Val)
    {
        int lo = 0;
        int hi = events.size() - 1;
        int answer = events.size();
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(events[mid][0] >= Val)
            {
                answer = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return answer;
    }
    // int recur(int i, int stn, int left, vector<vector<int>> &events)
    // {
    //     if(i >= events.size() || left == 0) return stn;
    //     int op1 = recur(ni, stn + events[i][2], left - 1, events);
    //     int op2 = recur(i + 1, stn, left, events);
    //     return max(op1, op2);
    // }
    int maxValue(vector<vector<int>>& events, int k)
    {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));

        for(int left = 1; left <= k; left++)
        {
            for(int i = n - 1; i >= 0; i--)
            {
                int ni = getMeGEQthanVal(events, events[i][1] + 1);
                int op1 = events[i][2] + dp[ni][left - 1];
                int op2 = dp[i + 1][left];
                dp[i][left] = max(op1, op2);
            }
        }

        return dp[0][k];
        // return recur(0, 0, k, events);
    }
};