class Solution
{
public:
    string longestPrefix(string s)
    {
        int n = s.length(), j = 0;
        vector<int> lps(n, 0); string str = "";
        for(int i = 1; i < n; i++)
        {
            while(j > 0 && s[j] != s[i]) j = lps[j - 1];
            if(s[j] == s[i]) lps[i] = ++j;
        }
        return s.substr(0, lps[n - 1]);
    }
};