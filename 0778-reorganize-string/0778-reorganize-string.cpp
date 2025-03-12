class Solution
{
public:
    string reorganizeString(string s)
    {
        // 2025 Hiring Prep Sprint Q8 [Medium but got intuition way faster]
        // imma lookup formal proof or similar approach-ness thing though
        vector<int> f(26, 0); multimap<int, char> mp;
        for(auto c : s) f[c - 'a']++;
        for(int i = 0; i < 26; i++) if(f[i] > 0) mp.insert({f[i], i + 'a'});
        auto it = --mp.end(); int dc = 0; int i = 0; int j = 1; string ans = s;
        while(dc < s.length())
        {
            char ch = it->second;
            int f = it->first;
            while(f--)
            {
                dc++;
                if(i < s.length()) { ans[i] = ch; i += 2; }
                else if(j < s.length()) { ans[j] = ch; j += 2; }
                else return "";
            }
            it--;
        }
        for(int i = 1; i < s.length(); i++)
            if(ans[i - 1] == ans[i]) return ""; return ans;
    }
};