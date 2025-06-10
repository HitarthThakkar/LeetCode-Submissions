class Solution
{
public:
    int recur(int i, vector<vector<bool>> &dp, vector<int> &actualDP)
    {
        if(i >= dp.size()) return 0;
        if(actualDP[i] != -1) return actualDP[i];
        int mini = 1 + recur(i + 1, dp, actualDP);
        for(int j = 0; j < dp[i].size(); j++)
            if(dp[i][j])
                mini = min(mini, recur(j + 1, dp, actualDP));
        return actualDP[i] = mini;
    }
    int minExtraChar(string s, vector<string>& dictionary)
    {
        set<string> dict;
        for(auto s : dictionary) dict.insert(s);
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        vector<int> actualDP(n, -1);
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                if(dict.find(s.substr(i, j - i + 1)) != dict.end()) dp[i][j] = true;
        return recur(0, dp, actualDP);
    }
};