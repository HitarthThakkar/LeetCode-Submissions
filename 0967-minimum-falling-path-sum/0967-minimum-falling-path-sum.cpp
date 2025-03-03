class Solution
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        for(int j = 0; j < m; j++) dp[0][j] = matrix[0][j];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int a = dp[i - 1][j];
                int b = ((j != m - 1) ? dp[i - 1][j + 1] : 1e9);
                int c = ((j != 0) ? dp[i - 1][j - 1] : 1e9);
                dp[i][j] = matrix[i][j] + min({a, b, c});
            }
        }
        int ans = 1e9;
        for(int j = 0; j < m; j++) ans = min(dp[n - 1][j], ans);
        return ans;
    }
};