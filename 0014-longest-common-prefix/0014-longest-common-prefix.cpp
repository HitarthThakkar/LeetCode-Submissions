class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        sort(strs.begin(), strs.end());
        int i = 0;
        string res = "";
        while(i < strs[0].length() && strs[0][i] == strs.back()[i]) res += strs[0][i++];
        return res;
        // prev solution
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