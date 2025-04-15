class Solution
{
private:
    int recur(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if(i == s.length() && j == t.length()) return 0;
        if(i == s.length()) return (t.length() - j);
        if(j == t.length()) return (s.length() - i);
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) {
            return dp[i][j] = recur(i + 1, j + 1, s, t, dp);
        }
        else {
            int mini = 1e9;
            mini = min(mini, recur(i + 1, j, s, t, dp));
            mini = min(mini, recur(i, j + 1, s, t, dp));
            mini = min(mini, recur(i + 1, j + 1, s, t, dp));
            return dp[i][j] = 1 + mini;
        }
    }
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return recur(0, 0, word1, word2, dp);
    }
};