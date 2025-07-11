class Solution
{
public:
    int recur(int i1, int j1, int i2, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        int j2 = (i1 + j1) - i2;

        if(i1 == n - 1 && i1 == j1 && i1 == j2 && i1 == i2) return grid[i1][j1];

        if(dp[i1][j1][i2] != -1) return dp[i1][j1][i2];

        int current = 0;
        int v1 = grid[i1][j1], v2 = grid[i2][j2];

        if(i1 == i2 && j1 == j2) current += grid[i1][j1];
        else current += (grid[i1][j1] + grid[i2][j2]);
        grid[i1][j1] = 0; grid[i2][j2] = 0;

        vector<int> di1 = {0, 0, 1, 1};
        vector<int> dj1 = {1, 1, 0, 0};
        vector<int> di2 = {0, 1, 0, 1};
        vector<int> dj2 = {1, 0, 1, 0};

        int mexi = -1e8;

        for(int i = 0; i < 4; i++)
        {
            int ni1 = i1 + di1[i];
            int ni2 = i2 + di2[i];
            int nj1 = j1 + dj1[i];
            int nj2 = j2 + dj2[i];

            if(ni1 < n && ni2 < n && nj2 < n && nj1 < n && grid[ni1][nj1] != -1 && grid[ni2][nj2] != -1)
            {
                mexi = max(mexi, recur(ni1, nj1, ni2, n, grid, dp));
            }
        }

        grid[i1][j1] = v1; grid[i2][j2] = v2;

        return dp[i1][j1][i2] = (mexi < 0 ? -1e8 : current + mexi);
    }

    int cherryPickup(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (n, -1)));
        return max(0, recur(0, 0, 0, n, grid, dp));
    }
};