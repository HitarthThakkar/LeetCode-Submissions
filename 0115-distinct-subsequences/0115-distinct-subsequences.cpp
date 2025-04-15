class Solution
{
private:
    int recur(int i, int j, string &s, string &t, vector<int> &seema, vector<vector<int>> &dp)
    {
        if(i == s.length() && j == t.length()) return 1;
        if(i == s.length()) return 0;
        if(j == t.length()) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j])
        {
            int answer = 0;
            if(seema[j] != i) answer += recur(i + 1, j, s, t, seema, dp);
            answer += recur(i + 1, j + 1, s, t, seema, dp);
            return dp[i][j] = answer;
        }
        else
        {
            return dp[i][j] = recur(i + 1, j, s, t, seema, dp);
        }
    }
public:
    int numDistinct(string s, string t)
    {
        vector<vector<int>> dp(s.length(), vector<int> (t.length(), -1));
        vector<int> seema(t.length(), 0);
        int i = s.length() - 1;
        for(int j = t.length() - 1; j >= 0; j--)
        {
            while(i > 0 && s[i] != t[j]) i--;
            if(i < 0) return 0;
            seema[j] = i;
        }
        return recur(0, 0, s, t, seema, dp);
    }
};