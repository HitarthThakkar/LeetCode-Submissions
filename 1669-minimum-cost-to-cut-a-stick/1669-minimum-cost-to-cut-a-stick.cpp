class Solution
{
public:
    int minCost(int n, vector<int>& cuts)
    {
        // This is not readable, see previous submission.

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int nn = cuts.size();
        vector<vector<int>> dp(nn - 1, vector<int> (nn - 2, 0));

        for(int i = 1; i < nn - 1; i++)
            dp[i - 1][i - 1] = cuts[i + 1] - cuts[i - 1];

        for(int i = nn - 4; i >= 0; i--)
        {
            for(int j = i + 1; j < nn - 2; j++)
            {
                int mini = 1e9;
                int tba = 0;
                if(i >= 0 && j + 2 < nn) tba = cuts[j + 2] - cuts[i];
                for(int k = i; k <= j; k++)
                {
                    int cost = 0;
                    int r = i; int c = k - 1;
                    if(r >= 0 && c >= 0 && r < dp.size() && c < dp[0].size())
                        cost += dp[r][c];
                    r = k + 1; c = j;
                    if(r >= 0 && c >= 0 && r < dp.size() && c < dp[0].size())
                        cost += dp[r][c];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini + tba;
            }
        }

        return dp[0][nn - 3];
    }
};