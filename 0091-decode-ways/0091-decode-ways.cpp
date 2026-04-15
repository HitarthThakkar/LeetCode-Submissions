class Solution
{
public:
    int recur(int i, string &s, vector<int> &dp)
    {
        if(i >= s.length()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        if(i + 1 < s.length() && s[i + 1] == '0') return recur(i + 2, s, dp);
        int op1 = recur(i + 1, s, dp);
        int op2 = 0;
        if(i + 1 < s.length()) {
            if(s[i] == '1') op2 = recur(i + 2, s, dp);
            if(s[i] == '2' && s[i + 1] < '7') op2 = recur(i + 2, s, dp);
        }
        return dp[i] = (op1 + op2);
    }

    int numDecodings(string s)
    {
        int n = s.length();

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                if(i == 0) return 0;
                if(s[i - 1] != '1' && s[i - 1] != '2') return 0;
                if(i + 1 < n && s[i + 1] == '0') return 0;
            }
        }

        vector<int> dp(n, -1);
        return recur(0, s, dp);
    }
};