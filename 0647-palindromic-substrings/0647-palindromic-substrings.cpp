class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, 1));
        int res = 0;
        for(int diag = n - 1; diag > 0; diag--) {
            int i = 0;
            for(int j = n - diag; j < n; j++) {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                res += dp[i][j];
                i++;
            }
        }
        return (res + n);
    }
};