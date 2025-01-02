class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n = s.length();
        unordered_map<char, char> m; unordered_set<char> st;
        for(int i = 0; i < n; i++)
        {
            auto it = m.find(t[i]);
            if (it == m.end() && st.find(s[i]) == st.end())
                { m.insert({t[i], s[i]}); st.insert(s[i]); }
            else if(it == m.end()) return false;
            else if(it->second != s[i]) return false;
        }
        return true;
    }
};