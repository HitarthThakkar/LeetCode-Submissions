class Solution
{
public:
    bool recur(int ind, string &s, vector<string>& dict, vector<int> &dp)
    {
        if(ind == s.length()) return true;
        if(dp[ind] != -1) return dp[ind];
        for(int i = 0; i < dict.size(); i++)
        {
            int sslen = dict[i].length();
            int leftlen = (s.length() - ind);
            if(leftlen >= sslen && s.substr(ind, sslen) == dict[i])
                if(recur(sslen + ind, s, dict, dp)) return dp[ind] = true;
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int n = s.length();
        vector<int> dp(n, -1);
        return recur(0, s, wordDict, dp);
    }
};