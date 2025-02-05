class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        vector<char> v;
        for(int i = 0; i < s1.length(); i++)
        {
            if(s1[i] != s2[i])
            {
                v.push_back(s1[i]); v.push_back(s2[i]);
                if(v.size() > 4) return false;
            }
        }
        if(v.size() == 0) return true;
        if(v.size() == 2) return false;
        return ((v[1] == v[2]) && (v[0] == v[3]));
    }
};