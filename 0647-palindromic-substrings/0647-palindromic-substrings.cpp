class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, 1));
        int res = 0;
        int diag = n;
        while(diag--) {
            int j = n - diag;
            int i = 0;
            while(j < n) {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                res += dp[i][j];
                i++; j++;
            }
        }

        return (res + n);
    }
};