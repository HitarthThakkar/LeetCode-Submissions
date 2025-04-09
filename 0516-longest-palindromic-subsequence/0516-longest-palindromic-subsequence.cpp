class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        string rs = s;
        reverse(rs.begin(), rs.end());
        // LCS of r and rs
        int n = s.length();
        int m = rs.length();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            if(rs[i] == s[0] || (i > 0 && dp[i - 1][0] == 1)) dp[i][0] = 1;
        for(int i = 0; i < n; i++)
            if(s[i] == rs[0] || (i > 0 && dp[0][i - 1] == 1)) dp[0][i] = 1;
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                int smth = ((s[j] == rs[i]) ? 1 : 0);
                int one = dp[i - 1][j];
                int two = dp[i][j - 1];
                int three = dp[i - 1][j - 1] + smth;
                dp[i][j] = max({one, two, three});
            }
        }
        return dp[m - 1][n - 1];
    }
};