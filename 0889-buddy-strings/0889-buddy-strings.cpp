class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        if(s.length() != goal.length()) return false;
        vector<char> v; set<char> ss; bool dups = false;
        for(int i = 0; i < s.length(); i++)
        {
            if(!dups)
                if(ss.find(s[i]) == ss.end()) ss.insert(s[i]);
                else dups = true;
            if(s[i] != goal[i])
                v.push_back(s[i]), v.push_back(goal[i]);
            if(v.size() > 4) return false;
        }
        if(v.size() == 0) return dups; if(v.size() != 4) return false;
        return ((v[1] == v[2]) && (v[0] == v[3]));
    }
};