class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        // See last submission and why it failed pleej request.
        // u will get why we go bottom to top and not reverse ...

        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 1));

        if(dungeon[m - 1][n - 1] < 0) dp[m - 1][n - 1] = (-dungeon[m - 1][n - 1] + 1);

        for(int i = m - 2; i >= 0; i--)
        {
            dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
        }
        for(int j = n - 2; j >= 0; j--)
        {
            dp[m - 1][j] = max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);
        }

        for(int i = m - 2; i >= 0; i--)
        {
            for(int j = n - 2; j >= 0; j--)
            {
                int mini = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(1, mini - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};