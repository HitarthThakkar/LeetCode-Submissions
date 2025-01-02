class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string str = strs[0];
        for(int i = 1; i < strs.size(); i++)
        {
            string newstr;
            string s = strs[i];
            for(int j = 0; j < min(s.length(), str.length()); j++)
                if(s[j] != str[j]) break; else newstr += s[j];
            str = newstr;
        }
        return str;
    }
};