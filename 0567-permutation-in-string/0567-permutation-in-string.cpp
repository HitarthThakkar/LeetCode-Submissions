class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> v1(26, 0), v2(26, 0);
        if(s2.length() < s1.length()) return false;
        for(auto ele : s1) v2[ele - 'a']++;
        int l = 0, r = s1.length();
        for(int i = l; i < r; i++) v1[s2[i] - 'a']++;
        if(v1 == v2) return true;
        for(int i = r; i < s2.length(); i++)
        {
            v1[s2[i - r] - 'a']--; v1[s2[i] - 'a']++; l++;
            if(v1 == v2) return true;
        }
        return false;
    }
};