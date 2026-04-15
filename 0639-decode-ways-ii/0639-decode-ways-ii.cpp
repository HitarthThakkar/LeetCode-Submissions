class Solution
{
public:

    int m = 1e9 + 7;

    long long recur(int i, string &s, vector<long long> &dp)
    {
        int n = s.length();
        if(i >= n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i] % m;

        if(s[i] == '*')
        {
            if(i + 1 < n && s[i + 1] == '0') return dp[i] = (2 * recur(i + 2, s, dp)) % m;

            long long op1 = (9 * recur(i + 1, s, dp)) % m;
            long long op2 = 0;

            if(i + 1 < n)
            {
                if(s[i + 1] == '*') op2 = (15 * recur(i + 2, s, dp)) % m;
                else if(s[i + 1] < '7') op2 = (2 * recur(i + 2, s, dp)) % m;
                else op2 = recur(i + 2, s, dp) % m;
            }

            return dp[i] = (op1 + op2) % m;
        }
        else
        {
            if(i + 1 < n && s[i + 1] == '0') return dp[i] = recur(i + 2, s, dp) % m;

            long long op1 = recur(i + 1, s, dp) % m;
            long long op2 = 0;

            if(i + 1 < n)
            {
                if(s[i + 1] == '*')
                {
                    if(s[i] == '1') op2 = (9 * recur(i + 2, s, dp)) % m;
                    else if(s[i] == '2') op2 = (6 * recur(i + 2, s, dp)) % m;
                }
                else
                {
                    if(s[i] == '1') op2 = recur(i + 2, s, dp) % m;
                    else if(s[i] == '2' && s[i + 1] < '7') op2 = recur(i + 2, s, dp) % m;
                }
            }

            return dp[i] = (op1 + op2) % m;
        }
    }

    int numDecodings(string s)
    {
        int n = s.length();

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                if(i == 0) return 0;
                if(s[i - 1] != '*' && s[i - 1] != '1' && s[i - 1] != '2') return 0;
                if(i + 1 < n && s[i + 1] == '0') return 0;
            }
        }

        vector<long long> dp(n, -1);
        return recur(0, s, dp);
    }
};