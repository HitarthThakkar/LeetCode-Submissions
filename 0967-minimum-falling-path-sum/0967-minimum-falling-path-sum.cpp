class Solution
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m, -1), cur(m, -1);
        for(int j = 0; j < m; j++) prev[j] = matrix[0][j];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int a = prev[j];
                int b = ((j != m - 1) ? prev[j + 1] : 1e9);
                int c = ((j != 0) ? prev[j - 1] : 1e9);
                cur[j] = matrix[i][j] + min({a, b, c});
            }
            prev = cur;
        }
        int ans = 1e9;
        for(int j = 0; j < m; j++) ans = min(prev[j], ans);
        return ans;
    }
};