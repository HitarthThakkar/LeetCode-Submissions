class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        // 2025 Hiring Prep Sprint Q5 [Medium, actually]
        vector<int> pfx(26, 0), sfx(26, 0);
        for(auto ele : s) sfx[ele - 'a']++;
        set<string> ans;
        for(int i = 0; i < s.length(); i++)
        {
            sfx[s[i] - 'a']--;
            for(int j = 0; j < 26; j++)
                if(pfx[j] > 0 && sfx[j] > 0)
                {
                    char ch = (char) (j + 'a');
                    string ss = ""; ss += ch; ss += s[i]; ss += ch;
                    ans.insert(ss);
                }
            pfx[s[i] - 'a']++;
        }
        return ans.size();
    }
};