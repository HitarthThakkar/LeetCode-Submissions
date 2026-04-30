class Solution
{
public:
    int maxPathScore(vector<vector<int>>& grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (k + 1, -1e9)));

        dp[0][0][0] = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int cost = 0; cost <= k; cost++)
                {
                    if(dp[i][j][cost] == -1e9) continue;

                    // DOWN
                    if(i + 1 < m)
                    {
                        int newCost = cost + (grid[i + 1][j] == 2 ? 1 : grid[i + 1][j]);
                        int newScore = dp[i][j][cost] + grid[i + 1][j];
                        if(newCost <= k) dp[i + 1][j][newCost] = max(dp[i + 1][j][newCost], newScore);
                    }

                    // RIGHT
                    if(j + 1 < n)
                    {
                        int newCost = cost + (grid[i][j + 1] == 2 ? 1 : grid[i][j + 1]);
                        int newScore = dp[i][j][cost] + grid[i][j + 1];
                        if(newCost <= k) dp[i][j + 1][newCost] = max(dp[i][j + 1][newCost], newScore);
                    }
                }
            }
        }

        int res = -1;
        for(int c = 0; c <= k; c++) res = max(res, dp[m - 1][n - 1][c]);
        return res;
    }
};