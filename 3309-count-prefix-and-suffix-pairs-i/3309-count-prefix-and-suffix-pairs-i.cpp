class Solution
{
private:
    int ispfxsfx(string s, string str)
    {
        if(s.length() > str.length()) return 0;
        for(int i = 0; i < s.length(); i++) if(s[i] != str[i]) return 0;
        int j = str.length() - 1;
        for(int i = s.length() - 1; i >= 0; i--) if(s[i] != str[j]) return 0; else j--;
        return 1;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words)
    {
        int n = words.size(), ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                ans += ispfxsfx(words[i], words[j]);
        return ans;
    }
};