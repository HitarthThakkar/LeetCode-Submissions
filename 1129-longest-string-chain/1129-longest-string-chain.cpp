class Solution
{
private:
    bool f(string a, string b)
    {
        if(b.length() - 1 != a.length()) return false;
        int i = 0, j = 0;
        while(a[i] == b[j]) i++, j++;
        j++;
        while(i < a.length()) if(a[i] != b[j]) return false; else i++, j++;
        return true;
    }
    int recur(int i, int prev, vector<string> &words, vector<vector<int>> &dp)
    {
        if(i == words.size()) return 0;
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        int ans = 0;
        if(prev == -1 || f(words[prev], words[i])) ans = (1 + recur(i + 1, i, words, dp));
        ans = max(ans, recur(i + 1, prev, words, dp));
        return dp[i][prev + 1] = ans;
    }
public:
    static bool cmp(string &a, string &b)
    {
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return recur(0, -1, words, dp);
    }
};