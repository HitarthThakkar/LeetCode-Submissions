class Solution {
public:
    int m, n;
    int mod = 1000000007;
    // right = 0, down = 1, start = 2
    int recur(int i, int j, int lastDir, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        if(i == m - 1 && j == n - 1) return 1;
        if(dp[i][j][lastDir] != -1) return (dp[i][j][lastDir] % mod);

        if(grid[i][j] == 1) {
            if(lastDir == 0) {
                if(i + 1 < m) dp[i][j][lastDir] = (recur(i + 1, j, 1, grid, dp) % mod); else dp[i][j][lastDir] = 0;
                return (dp[i][j][lastDir] % mod);
            }
            else {
                if(j + 1 < n) dp[i][j][lastDir] = (recur(i, j + 1, 0, grid, dp) % mod); else dp[i][j][lastDir] = 0;
                return (dp[i][j][lastDir] % mod);
            }
        }
        else {
            int result = 0;
            if(j + 1 < n) result = (((result % mod) + (recur(i, j + 1, 0, grid, dp) % mod)) % mod);
            if(i + 1 < m) result = (((result % mod) + (recur(i + 1, j, 1, grid, dp) % mod)) % mod);
            return dp[i][j][lastDir] = (result % mod);
        }
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (3, -1)));
        recur(0, 0, 2, grid, dp);
        return (dp[0][0][2] % mod);
    }
};