class Solution
{
public:
    int recur(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp, int m, int n)
    {
        if(dp[i][j] != -1) return dp[i][j];

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        int result = 0;

        for(int ii = 0; ii < 4; ii++)
        {
            int ni = i + dr[ii];
            int nj = j + dc[ii];

            if(ni >= 0 && nj >= 0 && ni < m && nj < n && matrix[ni][nj] < matrix[i][j])
            {
                result = max(result, recur(ni, nj, matrix, dp, m, n));
            }
        }

        return dp[i][j] = (1 + result);
    }

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int> (n, -1));
        int result = 1;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                result = max(result, recur(i, j, matrix, dp, m, n));
            }
        }

        return result;
    }
};